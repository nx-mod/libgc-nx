# What a GameCube game needs

The engine, the translator and the graphics layer are shared with the Wii. This
is the list of what is not, in the order it has to be built.

## 1. The disc

GameCube images have no encryption and no partitions: the header is at offset 0,
the filesystem table is where the header says, and files are stored plainly.
The same reader serves both consoles - a Wii image is this plus a partition
table and cluster decryption.

| Field | At | Is |
|---|---|---|
| game code, maker, disc id | `0x00` | `GM4E01`, and which disc of a set |
| magic | `0x1C` | `0xC2339F3D` - what makes it a GameCube disc |
| name | `0x20` | as the console shows it |
| apploader | `0x2440` | the code the console runs to load the game |
| main executable | `0x0420` | offset of the DOL |
| filesystem | `0x0424` | offset and size of the FST |

## 2. Boot

The console hands the machine to the game and gets out of the way: there is no
IOS, no IPC and nothing running beside it. Booting means placing the DOL, filling
in the low-memory block the SDK reads, and jumping to the entry point.

The low-memory block differs from the Wii's: no MEM2 arena, no IOS version, a
different console type, and the physical memory size is 24 MB.

## 3. ARAM

16 MB of auxiliary memory the CPU cannot address. Games use it as storage they
DMA in and out of main memory - sound samples, textures, level data - through
`ARStartDMA`. The Wii has none of it: its SDK emulates ARAM inside MEM2, which
is the shape this takes as well, with the DMA becoming a copy.

Anything that reads ARAM addresses expects the SDK's allocator on top
(`ARAlloc`, the ARQ request queue), so both layers are needed.

## 4. Audio

The DSP and its AI output are shared with the Wii and already native. What is
not:

- **AX voices out of ARAM** - a voice points at ARAM rather than main memory
- **DTK** - audio streamed off the disc, decoded as ADPCM and mixed in. The Wii
  dropped it entirely; several GameCube games use it for all their music.

## 5. Saves

A memory card is a file: a header, a block allocation table in two copies, a
directory of up to 127 entries, and 8 KiB blocks. `CARD` calls become reads and
writes of that file, with the card's own checksums maintained so a card written
here is one a real console would accept.

## 6. What comes free

Shared with the Wii and already native: GX, MTX, the OS core (threads, alarms,
cache, context, time), AI, DSP, EXI, SI and PAD, the C library, and the video
interface apart from its mode tables.
