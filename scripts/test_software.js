const { spawn } = require('child_process');
const path = require('path');
const fs = require('fs');

async function testSoftware() {
    console.log('🔍 Testing Software Rendering Isolated...');
    
    const mgbaPath = path.resolve(__dirname, '..', 'mgba_native', 'mGBA-custom', 'mGBA.exe');
    const romPath = path.resolve(__dirname, '..', 'roms', 'QuetzalEnglishAlpha8v4.gba');
    
    // Command line for software rendering
    const args = [
        '-m', '4',
        '-C', 'audio.driver=dummy',
        '-C', 'video.driver=software',
        '--stream-pipe', 'test_software_pipe',
        romPath
    ];
    
    console.log(`🚀 Spawning: ${mgbaPath} ${args.join(' ')}`);
    const mgba = spawn(mgbaPath, args);
    
    mgba.stdout.on('data', (data) => console.log(`[STDOUT] ${data.toString().trim()}`));
    mgba.stderr.on('data', (data) => console.log(`[STDERR] ${data.toString().trim()}`));
    
    mgba.on('exit', (code) => {
        console.log(`[EXIT] mGBA exited with code ${code}`);
    });
    
    // Kill after 10s if it doesn't crash before
    setTimeout(() => {
        console.log('⏰ Test finished (10s), killing mGBA...');
        mgba.kill();
        process.exit(0);
    }, 10000);
}

testSoftware();
