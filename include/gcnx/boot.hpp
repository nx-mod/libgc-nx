#pragma once

// Booting a GameCube game.
//
// The console hands the machine to the game and gets out of the way: there is
// no IOS, no IPC, and nothing running beside it. Booting means placing the
// executable, filling in the low-memory block the SDK reads back all through a
// run, and jumping to the entry point.
//
// That block is not the Wii's. There is no MEM2 arena and no IOS version in it,
// the console type says GameCube, and the memory it describes is 24 MB.
//
// Nothing is written yet; this says what has to be.

#include <cstdint>

namespace gcnx::boot {

inline constexpr std::uint32_t kMemorySize = 24 * 1024 * 1024;

// Fill in the low memory a game reads: the disc's own header, the console type,
// how much memory there is, and where the arena begins and ends.
void PrepareLowMemory(std::uint32_t arena_low, std::uint32_t arena_high);

// The apploader, which is the small program on the disc the console runs to
// load the game. A game whose disc has one is loaded through it, because that
// is what decides where its pieces go.
bool RunApploader();

}  // namespace gcnx::boot
