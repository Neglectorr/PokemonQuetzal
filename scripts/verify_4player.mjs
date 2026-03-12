import puppeteer from 'puppeteer';
import { spawn } from 'child_process';
import path from 'path';
import { fileURLToPath } from 'url';

const __dirname = path.dirname(fileURLToPath(import.meta.url));
const serverPath = path.join(__dirname, '..', 'server', 'index.js');
const BASE_URL = 'http://localhost:3000';

async function runTest() {
    console.log('🚀 Starting 4-Player Local Verification...');

    // 1. Start Server
    const server = spawn('node', [serverPath], {
        stdio: 'inherit',
        env: { ...process.env, DEBUG_AUTH: 'true', PORT: '3000', DISABLE_AUTO_LOGIN: 'true' }
    });

    // Wait for server to be ready
    await new Promise(r => setTimeout(r, 5000));

    const browser = await puppeteer.launch({ 
        headless: "new", 
        defaultViewport: { width: 1280, height: 720 },
        args: ['--no-sandbox', '--disable-setuid-sandbox']
    });

    try {
        // --- STEP 1: HOST CREATES ROOM ---
        const hostContext = await browser.createBrowserContext();
        const hostPage = await hostContext.newPage();
        
        console.log('[Host] Logging in...');
        await hostPage.goto(BASE_URL);
        await hostPage.waitForSelector('#username-input');
        await hostPage.type('#username-input', 'Host_Wesley');
        await hostPage.click('#login-btn');
        
        console.log('[Host] Waiting for Dashboard...');
        await hostPage.waitForSelector('#create-room-btn');
        await hostPage.click('#create-room-btn');
        
        console.log('[Host] Filling form...');
        await hostPage.waitForSelector('#room-name-input');
        await hostPage.type('#room-name-input', 'Local 4-Player Test');
        
        await hostPage.waitForSelector('#rom-select option[value*=".gba"]', { timeout: 10000 });
        const romValue = await hostPage.evaluate(() => {
            const select = document.querySelector('#rom-select');
            const options = Array.from(select.options);
            const quetzal = options.find(o => o.text.includes('Quetzal'));
            return quetzal ? quetzal.value : options[1]?.value;
        });
        
        if (!romValue) {
            const content = await hostPage.content();
            console.log('[DEBUG] Page content:', content);
            throw new Error('No ROMs found in dropdown!');
        }
        await hostPage.select('#rom-select', romValue);
        
        console.log(`[Host] Submitting room creation for ROM: ${romValue}`);
        await hostPage.click('#create-room-form button[type="submit"]');
        
        console.log('[Host] Waiting up to 15s for URL change to /room/...');
        await hostPage.waitForFunction(() => window.location.pathname.includes('/room/'), { timeout: 15000 });
        
        const roomUrl = hostPage.url();
        const roomId = roomUrl.split('/').pop().split('?')[0];
        console.log(`[Host] Room ID: ${roomId}`);

        // --- STEP 2: PLAYERS JOIN ---
        for (let i = 2; i <= 4; i++) {
            const context = await browser.createBrowserContext();
            const page = await context.newPage();
            
            console.log(`[Player ${i}] Joining room ${roomId}...`);
            await page.goto(BASE_URL);
            await page.waitForSelector('#username-input');
            await page.type('#username-input', `Player_${i}`);
            await page.click('#login-btn');
            
            await page.goto(`${BASE_URL}/room/${roomId}`);
            await page.waitForSelector('.room-title');
        }

        // --- STEP 3: START GAME ---
        console.log('[Host] Starting game...');
        await hostPage.waitForSelector('#start-game-btn');
        
        // Wait for player list to propagate
        await new Promise(r => setTimeout(r, 2000));
        await hostPage.click('#start-game-btn');
        
        console.log('⌛ Waiting 15 seconds for mGBA flow...');
        await new Promise(r => setTimeout(r, 15000));

        // --- STEP 4: VERIFY MULTI-VIEW ---
        console.log('[Verifier] Opening Multi-View Dashboard...');
        const verifierContext = await browser.createBrowserContext();
        const verifierPage = await verifierContext.newPage();
        await verifierPage.goto(`${BASE_URL}/multi_view.html?room=${roomId}`);
        
        console.log('⌛ Waiting 10 seconds for frames...');
        await new Promise(r => setTimeout(r, 10000));
        
        console.log('📸 Taking verification screenshot...');
        await verifierPage.screenshot({ path: path.join(__dirname, '..', 'verification_4player.png'), fullPage: true });
        
        console.log('✅ Verification complete! Screenshot saved to verification_4player.png');

    } catch (err) {
        console.error('❌ Verification failed:', err.message);
        try {
            const pages = await browser.pages();
            for (let i = 0; i < pages.length; i++) {
                await pages[i].screenshot({ path: path.join(__dirname, '..', `error_page_${i}.png`) });
            }
        } catch(e) {}
    } finally {
        console.log('🧹 Cleaning up...');
        await browser.close();
        server.kill();
        process.exit(0);
    }
}

runTest();
