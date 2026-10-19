# Build / Compilação

## Requirements

Linux, GNU Make and GCC/Clang with GNU C99 and `__int128` support. The application
loads SDL2 dynamically: runtime `libSDL2-2.0.so.0` is needed for interactive use.
The non-interactive tests do not need an SDL2 development package or display server.
Packaging needs Python 3. ARM64 cross compilation was tested with Zig 0.15.2.

## Native build and tests

From the repository root:

```sh
make check
```

Produces `build/BaetaCalc` and runs all tests from an isolated directory under
`build/test-runtime`. `-Wno-unused-function` is used only for the test translation
units that intentionally include subsets of the implementation.

Desktop preview (two SDL windows, no hardware suspend):

```sh
mkdir -p build/preview
cp assets/font.rgba build/preview/
./build/BaetaCalc "$PWD/build/preview" --host
```

The preview writes its state to `build/preview`, not to source directories.
`--host` disables direct console power and touch-device access. Layouts use the
same 1024×768 logical coordinates as the console.

## RGDS+ ARM64

```sh
make arm64 ZIG=/path/to/zig
```

Target: `aarch64-linux-gnu.2.34`. This is a glibc compatibility target, not the
application version. Do not replace it with `2.5` or `2.54` when renaming a release.
The target uses the firmware's libc/libm and SDL2 shared library.
No SDL2 shared object, firmware or toolchain is bundled.

## Make an installable ZIP

```sh
make package ZIG=/path/to/zig
```

Or package an already built ARM64 ELF:

```sh
python3 scripts/package_release.py --binary build/arm64/BaetaCalc
```

Output goes to `dist/`. The archive has `APPS/BaetaCalc.sh`,
`APPS/BaetaCalc/BaetaCalc`, `APPS/Imgs/BaetaCalc.png`, the font/license, manuals, original-code license,
third-party notices and a complete source tree under `Sources`.
The script checks for an ARM64 ELF, sets executable permissions in the ZIP and
writes SHA256SUMS. It never includes build output, runtime state, logs or calibration.

## Release provenance

The separately supplied v2.5.0 GitHub release asset reuses the executable from the
original 2.5 Final archive without modification. The supplied logo, license files and this organized
source/documentation tree have been added. The new Makefile was tested separately;
a rebuild is not claimed to be byte-for-byte identical to the original binary.
The source reorganization changes no application C/H content.

## Hardware checks

Automated tests do not validate panel wake-up, firmware suspend behavior, physical
button mappings or touch calibration on every console. In particular, POWER
suspend/resume remains firmware-dependent and requires RGDS+ hardware testing.
