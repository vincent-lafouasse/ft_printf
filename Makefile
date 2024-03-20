NAME = libftprintf.a

BUILD_DIR            = ./build
SRC_DIR              = ./src
INCLUDE_DIR          = ./include
INTERNAL_INCLUDE_DIR = ./src

SRCS = $(shell find $(SRC_DIR) -name *.c)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CC        = cc
CFLAGS    = -Wall -Wextra -Werror -g3
CPPFLAGS  = -I$(INCLUDE_DIR) -I$(INTERNAL_INCLUDE_DIR)
CPPFLAGS += -MMD -MP

LIBFT_PATH = ./lib/libft
LIBFT = $(LIBFT_PATH)/libft.a
OBJS += $(LIBFT)
CPPFLAGS += -I$(LIBFT_PATH)/include

ARFLAGS = rcs

.PHONY: all
all: build

.PHONY: build
build: $(NAME)

# Linking
$(NAME): $(LIBFT) $(OBJS)
	ar $(ARFLAGS) $@ $(OBJS)

# Compilation
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH)

.PHONY: re
re: fclean build

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)
	$(RM) -r $(LIBFT_PATH)/$(BUILD_DIR)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

# LSP stuff, don't worry about it
.PHONY: update
update:
	make clean
	mkdir -p $(BUILD_DIR)
	bear --output $(BUILD_DIR)/compile_commands.json -- make build
