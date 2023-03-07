CC=gcc
CFLAGS= -Wall -Werror -Wextra

door_struct: dmanager_module.o
	$(CC) $(CFLAGS) dmanager_module.o -o ../build/Quest_1
dmanager_module.o: dmanager_module.c door_struct.h
	$(CC) $(CFLAGS) -c dmanager_module.c

clean:
	rm -rf *.o ../build/Quest_*