#!/usr/bin/env python3
"""Package a supplied ARM64 BaetaCalc ELF; never collect runtime files."""
import argparse
import hashlib
import struct
import zipfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def arm64_elf(path):
    header = path.read_bytes()[:20]
    return (len(header) == 20 and header[:4] == b'\x7fELF'
            and header[4] == 2 and header[5] == 1
            and struct.unpack('<H', header[18:20])[0] == 183)


def add(archive, path, name, executable=False):
    info = zipfile.ZipInfo(name, (2026, 10, 18, 0, 0, 0))
    info.create_system = 3
    info.external_attr = (0o100755 if executable else 0o100644) << 16
    info.compress_type = zipfile.ZIP_DEFLATED
    archive.writestr(info, path.read_bytes())


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--binary', required=True, type=Path)
    parser.add_argument('--output-dir', type=Path, default=ROOT / 'dist')
    args = parser.parse_args()
    if not args.binary.is_file() or not arm64_elf(args.binary):
        parser.error('--binary must be a little-endian 64-bit ARM/aarch64 ELF')
    args.output_dir.mkdir(parents=True, exist_ok=True)
    output = args.output_dir / 'BaetaCalc_2_5_Final_PT_EN_RGDSPlus.zip'
    root_files = ['README.md', 'README_EN.md', 'LICENSE', 'THIRD_PARTY_NOTICES.md',
                  'CHANGELOG.md', 'CONTRIBUTING.md', 'LOGO_NOTICE.md', 'Makefile', 'VERSION',
                  '.gitignore', '.gitattributes']
    with zipfile.ZipFile(output, 'w') as archive:
        add(archive, ROOT / 'launcher/BaetaCalc.sh', 'APPS/BaetaCalc.sh', True)
        add(archive, args.binary, 'APPS/BaetaCalc/BaetaCalc', True)
        add(archive, ROOT / 'assets/BaetaCalc.png', 'APPS/Imgs/BaetaCalc.png')
        for name in ['font.rgba', 'FONT-LICENSE.txt']:
            add(archive, ROOT / 'assets' / name, 'APPS/BaetaCalc/' + name)
        for src, dest in [('docs/MANUAL_PT.txt', 'LE-ME.txt'),
                          ('docs/MANUAL_EN.txt', 'README_EN.txt'),
                          ('LICENSE', 'LICENSE'),
                          ('THIRD_PARTY_NOTICES.md', 'THIRD_PARTY_NOTICES.md'),
                          ('LOGO_NOTICE.md', 'LOGO_NOTICE.md')]:
            add(archive, ROOT / src, dest)
        for name in root_files:
            add(archive, ROOT / name, 'Sources/' + name)
        for directory in ['src', 'tests', 'assets', 'launcher', 'scripts', 'docs']:
            for path in sorted((ROOT / directory).rglob('*')):
                if path.is_file() and '__pycache__' not in path.parts and path.suffix != '.pyc':
                    add(archive, path, 'Sources/' + path.relative_to(ROOT).as_posix())
    with zipfile.ZipFile(output) as archive:
        if archive.testzip() is not None:
            raise RuntimeError('ZIP verification failed')
    digest = hashlib.sha256(output.read_bytes()).hexdigest()
    (args.output_dir / 'SHA256SUMS').write_text(f'{digest}  {output.name}\n')
    print(output)


if __name__ == '__main__':
    main()
