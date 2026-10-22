# BaetaCalc v2.5.1 — English by default

BaetaCalc now starts in English on first launch, making the application easier to use for international users.

## Changes
- English (EN) is the default when no valid language preference exists.
- Previously saved Portuguese (PT) and English (EN) preferences are preserved.
- Switch languages at any time using the PT/EN button on the home screen; your choice is saved.
- Language files support LF, CRLF and no trailing newline.
- Updated manuals and language regression tests.

## Installation / update
Download **BaetaCalc_2_5_1_PT_EN_RGDSPlus.zip** below. Extract it and copy the contents of **APPS** into **Roms/APPS** on the games card, allowing file replacement.

When updating, do not delete the existing BaetaCalc folder: keep your state, language and calibration files. An installation with Portuguese already selected will continue to use Portuguese. Select English using the home-screen language button if desired.

GitHub's automatic **Source code** archives do not contain the installable executable.

## Target and validation
RGDS+ with Linux Stock OS (ARM64). Rebuilt with Zig 0.15.2 for `aarch64-linux-gnu.2.34`. Automated tests and archive integrity checks are run during release preparation. Console testing is still required; POWER suspend/resume remains firmware-dependent.
