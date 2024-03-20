NAME = libprintf.a

.PHONY: all
all: build

BUILD_DIR            = ./build
SRC_DIR              = ./src
INCLUDE_DIR          = ./include
INTERNAL_INCLUDE_DIR = ./src

SRCS = $(shell find $(SRC_DIRS) -name *.c)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

CC        = cc
CFLAGS    = -Wall -Wextra -Werror -g3
CPPFLAGS  = -I$(INCLUDE_DIR) -I$(INTERNAL_INCLUDE_DIR)
CPPFLAGS += -MMD -MP

.PHONY: build
build: $(NAME)

.PHONY: re
re: fclean build

.PHONY: clean
clean:
	$(RM) $(NAME)

.PHONY: fclean
fclean: clean
	$(RM) -r $(BUILD_DIR)

