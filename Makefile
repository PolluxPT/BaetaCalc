CC ?= cc
ZIG ?= zig
CFLAGS ?= -O2 -Wall -Wextra -Werror
CPPFLAGS += -Isrc
LDLIBS += -lm -ldl
HEADERS := $(wildcard src/*.h)
TEST_NAMES := $(patsubst tests/%.c,%,$(wildcard tests/test-*.c))
TEST_BINS := $(addprefix build/tests/,$(TEST_NAMES))

.PHONY: all test check arm64 package clean
all: build/BaetaCalc

build/BaetaCalc: src/baetacalc.c $(HEADERS)
	mkdir -p build
	$(CC) $(CPPFLAGS) $(CFLAGS) -std=gnu99 $< $(LDLIBS) -o $@

build/tests/%: tests/%.c src/baetacalc.c $(HEADERS)
	mkdir -p build/tests
	$(CC) $(CPPFLAGS) $(CFLAGS) -Wno-unused-function -std=gnu99 $< $(LDLIBS) -o $@

test: $(TEST_BINS)
	mkdir -p build/test-runtime
	@set -e; for t in $(TEST_NAMES); do (cd build/test-runtime && ../tests/$$t); done

check: all test

arm64:
	mkdir -p build/arm64
	$(ZIG) cc -target aarch64-linux-gnu.2.34 -std=gnu99 $(CFLAGS) -s src/baetacalc.c $(LDLIBS) -o build/arm64/BaetaCalc

package: arm64
	python3 scripts/package_release.py --binary build/arm64/BaetaCalc

clean:
	rm -rf build dist
