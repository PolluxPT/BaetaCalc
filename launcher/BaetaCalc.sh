#!/bin/bash
set -u
parent=$(CDPATH= cd -P "$(dirname "$0")" && pwd) || exit 1
app="$parent/BaetaCalc"
exec > "$app/BaetaCalc_Arranque.txt" 2>&1
printf 'BaetaCalc 2.5 final for RGDS+\n'
export XDG_RUNTIME_DIR="${XDG_RUNTIME_DIR:-/var/run}"
export WAYLAND_DISPLAY="${WAYLAND_DISPLAY:-wayland-0}"
export SDL_VIDEODRIVER=wayland
export SDL_RENDER_DRIVER=software
export SDL_MOUSE_TOUCH_EVENTS=0
export LD_LIBRARY_PATH="/usr/lib:/lib:/mnt/vendor/lib"
unset LD_PRELOAD
export BAETACALC_CALIBRATION="$parent/ScummVM_RGDSPlus/config/touch-calibration.txt"
control=/sys/class/anbernic_misc/tpctrl
old_touch=$(cat "$control" 2>/dev/null || true)
restore() { if [ -n "$old_touch" ]; then printf '%s\n' "$old_touch" > "$control"; fi; }
trap restore EXIT
trap 'exit 130' INT TERM HUP
if [ -w "$control" ]; then printf '0\n' > "$control"; fi
# Preserve the existing state when upgrading from Calc84, once only.
if [ ! -e "$app/state.txt" ] && [ -f "$parent/Calc84_RGDSPlus/state.txt" ]; then
    cp "$parent/Calc84_RGDSPlus/state.txt" "$app/state.txt" || exit 1
fi
cd "$app" || exit 1
if [ ! -x ./BaetaCalc ]; then chmod +x ./BaetaCalc; fi
./BaetaCalc "$app"
result=$?
printf 'Código de saída: %s\n' "$result"
exit "$result"
