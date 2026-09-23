#pragma once

// Memory cards, as files.
//
// A GameCube card is a small filesystem: a header with the card's own id and
// its checksums, two copies of a block allocation table, a directory of up to
// 127 entries, and 8 KiB blocks of data. A game mounts a card, reads and writes
// files on it, and expects the console's own checksums to hold - so a card
// written here is one a real console would accept, and a card from a real
// console is one a game reads here.
//
// The Wii keeps saves in its NAND instead, which is libwii-nx's.
//
// Nothing is written yet; this says what has to be.

#include <cstdint>
#include <string>

namespace gcnx::card {

inline constexpr std::uint32_t kBlockSize = 8 * 1024;
inline constexpr std::uint32_t kDirectoryEntries = 127;

// The sizes a card comes in, in blocks: 59 is Nintendo's own 4 Mbit card.
inline constexpr std::uint32_t kBlocks59 = 59;
inline constexpr std::uint32_t kBlocks251 = 251;
inline constexpr std::uint32_t kBlocks2043 = 2043;

// A card in a slot, kept as a file on the host.
bool Mount(int slot, const std::string& path);
void Unmount(int slot);
bool Mounted(int slot);

// A new card, formatted the way the console formats one.
bool Format(const std::string& path, std::uint32_t blocks);

}  // namespace gcnx::card
