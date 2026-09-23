# libgc-nx

The GameCube's own hardware, as a library, for statically recompiled GameCube
games running natively on Nintendo Switch.

It holds only what a GameCube has and a Wii does not. Everything both machines
share - the CPU, GX, the DSP, the OS, the SDK's libraries, the translator - is
in [libdol-nx](https://github.com/nx-mod/libdol-nx), which this builds on.

## Why it is small

The two consoles are the same machine with different peripherals. Of the
libraries Nintendo shipped in the two SDKs, sixteen appear in both under the
same names and do the same job: `ai ax axfx base card dsp dvd exi gd gf gx mtx
os pad si vi`. Those are libdol-nx's.

| | GameCube | Wii |
|---|---|---|
| CPU | Gekko, 486 MHz | Broadway, 729 MHz - same instruction set |
| Graphics | Flipper GX | Hollywood GX - same pipeline |
| Sound | DSP, with ARAM behind it | DSP, no ARAM |
| System software | none: the game owns the machine | IOS, reached over IPC |
| Storage | memory card | NAND |
| Media | an unencrypted disc | encrypted partitions |

## Modules

| Module | Is | State |
|---|---|---|
| `aram` | the 16 MB the CPU cannot address, reached by DMA, and the allocator and request queue the SDK puts on top | to write |
| `card` | memory cards as files, with the console's own checksums kept so a card written here is one a GameCube would accept | to write |
| `dtk` | audio streamed off the disc as ADPCM, which the Wii dropped | to write |
| `boot` | the apploader path, and the low-memory block the SDK reads | to write |

A GameCube disc is read by libdol-nx: the same reader serves both consoles,
since a Wii image is a GameCube one plus a partition table and encryption.

## Working on it

- [docs/porting.md](docs/porting.md) - what each module has to do, in the order
  it has to be built
- [docs/references.md](docs/references.md) - where the hardware and the SDK are
  documented, and what may be taken from each source

## License

GPL-3.0-or-later. No game code or data is included or distributed.
