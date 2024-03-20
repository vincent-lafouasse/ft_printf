CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
INCLUDE_PATH = ../include
LIBRARY_PATH = ..


all:
	rm -rf exec
	make exec
	./exec

exec:
	$(CC) $(CFLAGS) -I$(INCLUDE_PATH) -L$(LIBRARY_PATH) main.c -lprintf -o exec	
