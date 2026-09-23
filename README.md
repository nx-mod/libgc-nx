# gc-nx

GameCube games running natively on Nintendo Switch — statically recompiled from
your own discs, not emulated. Each game's PowerPC code is translated to C++
ahead of time and compiled for the Switch, with the console's system software
answered natively rather than simulated.

Game code and data are never in this repository. You build from your own disc.

## Why this is mostly done already

The GameCube and the Wii are the same machine with different peripherals. The
CPU is the same core, the graphics hardware is the same GX, the sound hardware
is the same DSP, and the SDK is the same code two years apart: of the libraries
Nintendo shipped, sixteen appear in both SDKs under the same names and do the
same job.

So there is no second translator and no second runtime. A GameCube game runs on
the same engine a Wii game does, with a different console profile underneath.

| | GameCube | Wii |
|---|---|---|
| CPU | Gekko, 486 MHz | Broadway, 729 MHz — same instruction set |
| Graphics | Flipper GX | Hollywood GX — same pipeline |
| Sound | DSP + ARAM | DSP, no ARAM |
| System software | none: the game owns the machine | IOS, reached over IPC |
| Storage | memory card | NAND |
| Media | unencrypted disc | encrypted partitions |

## What the GameCube needs of its own

Four modules and a boot path. Everything else is shared.

| Part | Is | State |
|---|---|---|
| `aram` | the 16 MB the CPU cannot address, reached by DMA | to write |
| `card` | memory cards, as files | to write |
| `dtk` | disc streaming audio, which the Wii dropped | to write |
| `si` / `pad` | the controller ports | shared, already native |
| boot | the apploader path and the console's low memory | to write |
| disc | an unencrypted image and its filesystem | shared reader, GameCube layout |

## Games

One folder per game in [gcgames-nx](gcgames-nx). Candidates first, by how much
is already known about them:

| Game | Disc | Why it is a good first target |
|---|---|---|
| Mario Kart: Double Dash!! | `GM4E01` | the sibling of the engine most of our natives were written against, and a CC0 decompilation exists |
| Super Mario Sunshine | `GMSE01` | CC0 decompilation, JSystem throughout, and its THP video path is one we already replace |
| The Wind Waker | `GZLE01` | CC0 decompilation, and a separate project has already proved the whole ISA translates |
| Twilight Princess | `GZ2E01` | the most complete decompilation of any GameCube game |

## Layout

```
gc-nx/
├── gcgames-nx/   one folder per game
└── docs/         what the GameCube needs, and where its behaviour is documented
```

| Library | Role |
|---|---|
| [libdol-nx](https://github.com/nx-mod/libdol-nx) | the machine both consoles are: CPU, GX, DSP, the SDK, the translator |
| `libgc-nx` | what only a GameCube has: ARAM, memory cards, DTK, its boot path |
| [aurora-nx](https://github.com/nx-mod/aurora-nx) | GX on WebGPU |
| [dawn-nx](https://github.com/nx-mod/dawn-nx) | WebGPU on Switch |
| [nxvk](https://github.com/nx-mod/nxvk) | the Vulkan driver underneath |

## License

GPL-3.0-or-later. No game code or data is included or distributed.
