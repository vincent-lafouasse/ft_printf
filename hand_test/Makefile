CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE_PATH = ../include
LIBRARY_PATH = ../build


all:
	rm -rf exec
	make exec
	./exec

exec:
	$(CC) $(CFLAGS) -I$(INCLUDE_PATH) -L$(LIBRARY_PATH) main.c -lprintf -o exec	
