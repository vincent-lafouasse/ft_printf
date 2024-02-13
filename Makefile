BUILD_DIR = build

all: test

build:
	cmake --build $(BUILD_DIR)

test: build
	$(BUILD_DIR)/test/test_runner

clean:
	rm -rf $(BUILD_DIR)

format:
	echo todo

update:
	cmake -B $(BUILD_DIR)

.PHONY: all build test clean update
.PHONY: b t c f u
b: build
t: test
c: clean
f: format
u: update
