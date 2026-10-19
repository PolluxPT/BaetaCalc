# BaetaCalc

<img src="assets/BaetaCalc.png" alt="BaetaCalc logo" width="240">

[⬇ Descarregar / Download](https://github.com/PolluxPT/BaetaCalc/releases/latest)

**Scientific and graphing calculator for the RGDS+ running Linux Stock OS.**

[Português](README.md) · [English manual](docs/MANUAL_EN.txt) · [Build](docs/BUILD.md) · [MIT license](LICENSE)

Developed by Filipe Baeta. Menus are available in European Portuguese and English.

![Exact square-root result](docs/images/calculator.png)

## Install

1. Open **Releases** on this repository's page.
2. Download **BaetaCalc_2_5_Final_PT_EN_RGDSPlus.zip** from the release assets.
   GitHub's automatic **Source code** archives do not contain an installable binary.
3. Extract it and copy **BaetaCalc.sh** and the **BaetaCalc** folder from **APPS**
   to **Roms/APPS** on the games card.
   Also copy **Imgs/BaetaCalc.png** to **Roms/APPS/Imgs/BaetaCalc.png**.
4. Launch **BaetaCalc** from the console's APPS menu.

For updates, overwrite files without deleting the application folder first.
Keep existing state, language and calibration files. The startup log is overwritten,
not accumulated. A saved ScummVM touch calibration is imported when available;
otherwise normalized touch coordinates are used.

## Features

- Normal/scientific calculator, session history and cursor editing.
- Supported exact fractions and real radicals, including simplification and
  rationalization: `sqrt(8)` → `2√2`; `1/sqrt(2)` → `√2/2`.
- Six Y/X functions, horizontal and vertical lines, graphs, tables and TRACE.
- Graph panning, zoom and shading defined by intersecting selected conditions.
- Polynomial roots (degrees 1–6), equations in X on an interval, linear systems
  with two/three variables and nonlinear systems with two variables.
- PT/EN menus, exit confirmation and full mathematical reset.

**A/B** toggles decimal/exact presentation. Unsupported exact forms remain decimal.

## Controls

| Control | Action |
|---|---|
| Touch / A | Activate a key |
| D-pad | Navigate; pan in graph view |
| B | Delete while editing; go back in overview panels |
| START | Confirm/evaluate depending on context |
| Y | Swap displays |
| L / R | Graph zoom |
| L2 + R2 | Clear mathematical memory, functions and equations |
| Short POWER press | Request suspend; press again to resume |

## Compatibility and limitations

Target: **RGDS+ / Linux Stock OS / ARM64**, using the system SDL2 library.
Other consoles, including the non-Plus RGDS and RG35XXSP, are not confirmed.
**POWER suspend/resume depends on firmware and still needs hardware validation.**

The numerical engine uses floating point. Exact presentation supports bounded
expressions, not general symbolic algebra. Numerical searches may miss roots;
nonlinear systems seek one solution near the starting values. No 3D view or
shaded-area integration is implemented. Graphs are sampled.

## Develop and report issues

See [docs/BUILD.md](docs/BUILD.md). Tests cover mathematics, exact radicals,
navigation, persistence and UI layout on Linux. Screenshots are computer-rendered
test examples, not console photographs.

For an Issue, include console, firmware, application version and reproduction steps.
Check the contents of `BaetaCalc_Arranque.txt` before attaching it.

Original code/docs: [MIT](LICENSE), © 2026 Filipe Baeta.
Logo: [separate notice](LOGO_NOTICE.md). Font and dependencies: [third-party notices](THIRD_PARTY_NOTICES.md).
