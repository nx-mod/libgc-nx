# TODO - libgc-nx

Nothing here is written yet. In the order it has to be built, with
[docs/porting.md](docs/porting.md) for what each one does.

- [ ] `boot` - the apploader path, and the low-memory block the SDK reads: 24 MB
      of memory, no MEM2, no IOS
- [ ] `aram` - the 16 MB the CPU cannot address, its DMA, and the allocator and
      request queue the SDK puts on top
- [ ] `card` - memory cards as files, with the console's own checksums kept so a
      card written here is one a GameCube would accept
- [ ] `dtk` - audio streamed off the disc as ADPCM, which the Wii dropped
- [ ] AX voices that read out of ARAM rather than main memory
- [ ] The GameCube's video modes
- [ ] The Broadband Adapter: the games that support it play on a local network
      with no service anywhere, which is the only multiplayer either console has
      that needs nothing from the internet. Double Dash is the case
      ([why](https://github.com/nx-mod/wiiconnect-nx/blob/main/docs/lan.md))

Waiting on libdol-nx: a disc reader that handles an unencrypted image, and a
console profile that leaves out everything IOS.
