# Where the GameCube's behaviour is documented

What each source is good for, and what may be taken from it. Code is taken only
from projects with an explicit licence; the rest are read to understand what a
function does, and then the function is written here.

## The SDK, decompiled

| Project | Licence | Holds |
|---|---|---|
| [zeldaret/tp](https://github.com/zeldaret/tp) | CC0 | both SDKs side by side - `libs/dolphin` (37 libraries) and `libs/revolution` (34) - plus JSystem and the C runtime |
| [zeldaret/tww](https://github.com/zeldaret/tww) | CC0 | `src/dolphin`: ai, ar, base, card, db, dsp, dvd, exi, gba, gd, gf, gx, mtx, os, pad, si, vi |
| [doldecomp/sms](https://github.com/doldecomp/sms) | CC0 | `src/dolphin` including `thp`, and JSystem |
| [doldecomp/mkdd](https://github.com/doldecomp/mkdd) | CC0 | `libs/dolphin` including the networking libraries, and JSystem |
| [doldecomp/dolsdk2004](https://github.com/doldecomp/dolsdk2004) | none | the SDK itself, April 2004 - read as reference |
| [doldecomp/dolsdk2001](https://github.com/doldecomp/dolsdk2001) | none | the SDK itself, May 2001 - read as reference |

Comparing `libs/dolphin` with `libs/revolution` in the first of those is the
quickest way to see what is genuinely console-specific: sixteen libraries appear
in both under the same names.

## Other recompilers

Different targets, same problem. Useful for comparing how an instruction or a
subsystem was handled.

| Project | Licence | Is |
|---|---|---|
| [sp00nznet/ww](https://github.com/sp00nznet/ww) | MIT | a GameCube game recompiled to native Windows, covering the Gekko instruction set including paired singles and quantised loads |
| [ExpansionPak/DolRecomp](https://github.com/ExpansionPak/DolRecomp) | GPL-3.0 | a GameCube and Wii static recompiler |
| [mstan/gcnlle](https://github.com/mstan/gcnlle) | GPL-3.0 | the console's own boot program, statically recompiled |
| [KaiserGranatapfel/GameCubeRecompiled](https://github.com/KaiserGranatapfel/GameCubeRecompiled) | CC0 | DOL and REL to Rust |
| [encounter/decomp-toolkit](https://github.com/encounter/decomp-toolkit) | Apache-2.0 | DOL, REL and symbol analysis |

## Hardware

- **YAGCD** - the GameCube hardware documentation: registers, the disc format,
  the memory card format, low memory.
- **libogc** - the homebrew SDK, for hardware behaviour the official one hides.
