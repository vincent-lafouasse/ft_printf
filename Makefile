NAME = libprintf.a

.PHONY: all
all: build

BUILD_DIR            = ./build
SRC_DIR              = ./src
INCLUDE_DIR          = ./include
INTERNAL_INCLUDE_DIR = ./src

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
CPPFLAGS = -I$(INCLUDE_DIR) -I$(INTERNAL_INCLUDE_DIR)

.PHONY: build
build: $(NAME)

.PHONY: re
re: fclean build

.PHONY: clean
clean:
.PHONY: fclean
fclean:
