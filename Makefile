BUILD_DIR = build

all: test

build:
	cmake --build $(BUILD_DIR)

test: update build
	make -C hand_test

clean:
	rm -rf $(BUILD_DIR)

format:
	bash aux/format.sh

update:
	cmake -Wno-dev -B $(BUILD_DIR)

.PHONY: all build test clean update
.PHONY: b t c f u
b: build
t: test
c: clean
f: format
u: update
