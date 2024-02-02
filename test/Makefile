EXEC = tests.out

BUILD_DIR = ./build
SRC_DIR = ./src

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

LIB = printf
LDLIBS = -l$(LIB) -lunity
LDFLAGS = -L.. -LUnity

INC_DIRS = ./src ../include ./Unity/include
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

###
CFLAGS  = -std=c99
CFLAGS += -g3
CFLAGS += -Wall -Wextra
#CFLAGS += -Werror
CFLAGS += $(INC_FLAGS)


.PHONY: test build run
test: run

run: build
	@$(BUILD_DIR)/$(EXEC) -v

build:
	make clean
	make fclean -C ..
	make $(BUILD_DIR)/$(EXEC)

# Linking
$(BUILD_DIR)/$(EXEC): $(OBJS)
	make lib$(LIB).a -C ..
	make libunity.a -C Unity
	$(CC) $^ -o $@ $(LDFLAGS) $(LDLIBS)

# Compile C 
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)

# LSP stuff, don't worry about it
.PHONY: update
update:
	make clean
	mkdir -p $(BUILD_DIR)
	bear --output $(BUILD_DIR)/compile_commands.json -- make build
