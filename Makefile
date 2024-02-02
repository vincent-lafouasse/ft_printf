LIB = libprintf.a

CC = clang

SRC_DIR   = ./src
INC_DIR   = ./include
INTERNAL_INC_DIR = ./src/internal_h
BUILD_DIR = ./build

C_FILES = $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(C_FILES:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:%.o=%.d)


CFLAGS  = -Wall -Wextra
#CFLAGS += -Werror

CPPFLAGS  = -I$(INC_DIR) -I$(INTERNAL_INC_DIR)
CPPFLAGS += -MMD -MP

.PHONY: all
all: build

.PHONY: build
build: $(LIB)

$(LIB): $(OBJS)
	@echo Building $(LIB)
	@ar rcs $@ $^
	@printf "$(GREEN)===============BUILD COMPLETED===============$(NC)\n"

$(BUILD_DIR)/%.c.o: %.c
	@echo Compiling $<
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@echo Cleaning up object files
	@rm -rf $(BUILD_DIR)

.PHONY: fclean
fclean: clean
	@echo Cleaning up lib
	@rm -rf $(LIB)
	@make -C test clean

.PHONY: re
re: fclean update

.PHONY: test
test: $(LIB)
	@make -C test

.PHONY: fmt
fmt:
	@echo Formatting
	@bash aux/norme.sh

.PHONY: check
check: re
	@python3 -c 'print("-" * 80)'
	@echo SAINTE NORMINETTE SOIS CLEMENTE
	@python3 -c 'print("-" * 80)'
	@echo
	@norminette $(C_FILES)
	@echo
	@norminette $(INC_DIR)
	@printf "$(GREEN)===============NORME OK===============$(NC)\n"
	@echo
	@cppcheck --language=c $(C_FILES)

	@cppcheck --language=c $(INC_DIR)/*.h
	@printf "$(GREEN)===============CPPCHECK OK===============$(NC)\n"

# LSP stuff, don't worry about it
.PHONY: update
update:
	make clean
	make clean -C test
	mkdir -p $(BUILD_DIR)
	bear --output $(BUILD_DIR)/compile_commands.json -- make build -C test

# aliases
.PHONY: b f c u t
b: build
f: fmt
c: clean
u: update
t: test

GREEN = \033[0;32m
NC = \033[0m

-include $(DEPS)
