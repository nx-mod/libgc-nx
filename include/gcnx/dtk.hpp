#pragma once

// DTK: audio streamed straight off the disc.
//
// A GameCube disc can carry an audio track the drive decodes on its own, in
// 4-bit ADPCM, and mixes into the console's output without the game touching
// it. Several games use it for all their music. The Wii dropped it.
//
// Here the disc is a file and the drive is us, so the decode is ours: the
// stream is read, expanded, and handed to the same mixer the game's own voices
// go through.
//
// Nothing is written yet; this says what has to be.

#include <cstdint>

namespace gcnx::dtk {

// Begin streaming from `offset` on the disc, for `length` bytes, and keep
// going until told otherwise.
void Start(std::uint32_t offset, std::uint32_t length);
void Stop();

// The volume the game set, per channel, 0 to 255.
void SetVolume(std::uint8_t left, std::uint8_t right);

// Whether the track is still playing, which a game polls to know when its
// music ended.
bool Playing();

}  // namespace gcnx::dtk
