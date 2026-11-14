# Third-party notices

## Font atlas

`assets/font.rgba` is a raster glyph atlas derived from DejaVu font glyphs.
The full accompanying notice is preserved in [assets/FONT-LICENSE.txt](assets/FONT-LICENSE.txt).
It contains the Bitstream Vera font terms, the public-domain status of DejaVu
changes and the Debian packaging notices. Those notices apply to their respective
materials independently of the project's [PolyForm license](LICENSE).

Upstream: https://dejavu-fonts.github.io/

## SDL2

The application loads the system-provided `libSDL2-2.0.so.0` at runtime.
No SDL2 shared library is bundled. The small `src/sdl-api.h` file declares the ABI
used by BaetaCalc. SDL2 is an external dependency, licensed under the zlib license.

Upstream and license: https://www.libsdl.org/license.php

## SDL ABI helper provenance

The contents of `src/sdl-api.h` match the BaetaMP helper apart from two
header comments. BaetaMP identifies its helper as inherited from the RG DS+
ScummVM package and marks it GPL-3.0-or-later. The PolyForm notice for
BaetaCalc original material excludes this helper. Verify its upstream
provenance and applicable terms before distributing a new combined build
under PolyForm.

## Tools and platform

GCC, Clang/Zig, GNU Make, Python and the Linux firmware are external tools or
platform components. The project license covers original BaetaCalc code and
documentation. Third-party software and firmware retain their own licenses.
BaetaCalc is an independent application; no Texas Instruments ROM is included.

## Project logo

The supplied logo is preserved unchanged; see [LOGO_NOTICE.md](LOGO_NOTICE.md).
