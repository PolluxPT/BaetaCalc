# Public-package validation

- Native build and all 13 test programs passed using `make check` from this tree.
- ARM64 build passed using Zig 0.15.2 and `aarch64-linux-gnu.2.34`.
- All application C/H files and tests match the 2.5 Final working sources byte for byte.
- Release executable matches the original 2.5 Final executable byte for byte.
- Executable SHA-256: `0ab3135cd30af651307d8dd264419229b0190bab22aa4f49684a1b1453e2aef5`.
- Supplied logo is preserved byte for byte at `APPS/Imgs/BaetaCalc.png`.
- ZIP integrity and executable permission bits checked.
- Original-code license, separate logo notice and font notice included.
- Runtime state, logs, calibration, build files and local paths excluded.
- README local links checked; repository is below browser-upload size/count limits.

The release is ready for manual publication; no GitHub repository was created.
Desktop tests do not constitute console suspend/resume validation.
