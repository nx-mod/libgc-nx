# src

What only a GameCube has. Everything both consoles share is in
[libdol-nx](https://github.com/nx-mod/libdol-nx).

| Module | Is | State |
|---|---|---|
| [`boot`](../include/gcnx/boot.hpp) | the apploader path, and the low memory a game reads | to write |
| [`aram`](../include/gcnx/aram.hpp) | the 16 MB the processor cannot address, and its DMA | to write |
| [`card`](../include/gcnx/card.hpp) | memory cards, as files a console would accept | to write |
| [`dtk`](../include/gcnx/dtk.hpp) | audio streamed off the disc, which the Wii dropped | to write |

The headers in `include/gcnx/` say what each module has to do and what the
hardware actually is. Nothing is implemented yet, and nothing here pretends to
be: a build that includes this compiles four empty folders.

These are compiled into the runtime rather than linked as a library of their
own, the way libwii-nx's are: they answer a game's SDK calls and use the
runtime's memory and logging. `cmake/Sources.cmake` is what a build includes.
