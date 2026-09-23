#pragma once

// ARAM: the 16 MB a GameCube has beside its main memory, which the processor
// cannot address.
//
// A game reaches it by DMA - it asks the hardware to move a block one way or
// the other and waits for an interrupt - and uses it as the place to keep what
// will not fit: sound samples, textures, level data. The Wii dropped it
// entirely and gave its SDK an emulation over MEM2, which is the shape this
// takes as well: a flat 16 MB block, with the DMA becoming a copy.
//
// Three layers, and a game may use any of them:
//
//   AR     the memory and its DMA
//   ARAlloc  the SDK's allocator on top
//   ARQ    a queue, for a game that does not want to wait
//
// Nothing is written yet; this says what has to be.

#include <cstddef>
#include <cstdint>

namespace gcnx::aram {

inline constexpr std::size_t kSize = 16 * 1024 * 1024;

// How much of it the SDK left to the game, once its own use is taken out.
std::uint32_t UserSize();

// One transfer. `type` is the SDK's: 0 moves main memory into ARAM, 1 brings it
// back. A transfer is a copy here, so it finishes before this returns and the
// interrupt the game waits for is raised straight away.
void Transfer(std::uint32_t type, std::uint32_t main_address, std::uint32_t aram_address,
              std::uint32_t length);

// Where a game's block of ARAM begins, and how much there is. The SDK hands
// these out from a stack, so a game that frees out of order is a game with a
// bug on real hardware too.
std::uint32_t Allocate(std::uint32_t length);
void Free(std::uint32_t address);

}  // namespace gcnx::aram
