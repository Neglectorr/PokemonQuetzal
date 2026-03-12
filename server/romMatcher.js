/**
 * ROM Matching Engine
 * Groups compatible ROMs for multiplayer sessions (link cable + wireless adapter)
 */

// ROM compatibility groups - games that can connect via link cable or wireless adapter
const ROM_GROUPS = {
  'RSE': {
    name: 'Ruby / Sapphire / Emerald',
    titles: [
      'pokemon ruby', 'pokemon sapphire', 'pokemon emerald',
      'pokemon - ruby', 'pokemon - sapphire', 'pokemon - emerald',
      'ruby', 'sapphire', 'emerald'
    ],
    linkCable: true,
    wirelessAdapter: true // Emerald + FR/LG have wireless adapter support
  },
  'FRLG': {
    name: 'FireRed / LeafGreen',
    titles: [
      'pokemon firered', 'pokemon leafgreen',
      'pokemon - firered', 'pokemon - leafgreen',
      'firered', 'leafgreen', 'fire red', 'leaf green'
    ],
    linkCable: true,
    wirelessAdapter: true
  },
  'RSE_FRLG': {
    name: 'Gen III Cross-compatible',
    titles: [], // Virtual group for cross-gen trading (post-game)
    linkCable: true,
    wirelessAdapter: true
  },
  'QUETZAL': {
    name: 'Pokémon Quetzal (ROM Hack)',
    titles: [
      'pokemon quetzal', 'quetzal', 'pokemonquetzal'
    ],
    linkCable: true,
    wirelessAdapter: true
  }
};

/**
 * Determine which compatibility group a ROM belongs to
 * @param {string} romFilename - The ROM filename
 * @returns {string} The group ID
 */
function getRomGroup(romFilename) {
  const name = romFilename.toLowerCase().replace(/\.gba$/i, '').replace(/[_\-\.]/g, ' ').trim();

  for (const [groupId, group] of Object.entries(ROM_GROUPS)) {
    if (groupId === 'RSE_FRLG') continue; // Skip virtual group
    for (const title of group.titles) {
      if (name.includes(title)) {
        return groupId;
      }
    }
  }

  return 'UNKNOWN';
}

/**
 * Check if two ROMs can play together
 * @param {string} rom1 - First ROM filename
 * @param {string} rom2 - Second ROM filename
 * @returns {{ compatible: boolean, mode: string }}
 */
function canConnect(rom1, rom2) {
  const group1 = getRomGroup(rom1);
  const group2 = getRomGroup(rom2);

  // Same group = always compatible
  if (group1 === group2 && group1 !== 'UNKNOWN') {
    return { compatible: true, mode: 'same-group' };
  }

  // RSE <-> FRLG cross-compatibility (trading only in real games, but we allow it)
  if ((group1 === 'RSE' && group2 === 'FRLG') || (group1 === 'FRLG' && group2 === 'RSE')) {
    return { compatible: true, mode: 'cross-gen' };
  }

  // Quetzal can connect with RSE (it's based on Emerald)
  if ((group1 === 'QUETZAL' && group2 === 'RSE') || (group1 === 'RSE' && group2 === 'QUETZAL')) {
    return { compatible: true, mode: 'quetzal-rse' };
  }

  // Same exact filename = always compatible (fallback)
  if (rom1.toLowerCase() === rom2.toLowerCase()) {
    return { compatible: true, mode: 'exact-match' };
  }

  // Unknown or incompatible
  return { compatible: false, mode: 'incompatible' };
}

/**
 * Get compatible ROMs for a given ROM
 * @param {string} romFilename
 * @param {string[]} availableRoms
 * @returns {string[]}
 */
function getCompatibleRoms(romFilename, availableRoms) {
  return availableRoms.filter(rom => canConnect(romFilename, rom).compatible);
}

/**
 * Get connection capabilities for a ROM group
 * @param {string} groupId
 * @returns {{ linkCable: boolean, wirelessAdapter: boolean }}
 */
function getCapabilities(groupId) {
  const group = ROM_GROUPS[groupId];
  if (!group) return { linkCable: true, wirelessAdapter: false };
  return { linkCable: group.linkCable, wirelessAdapter: group.wirelessAdapter };
}

module.exports = { getRomGroup, canConnect, getCompatibleRoms, getCapabilities, ROM_GROUPS };
