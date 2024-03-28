CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -ggdb -fPIC
BUILD_DIR = build
TARGETS = belformat.o

win_belformat: $(TARGETS)
	$(CC) $(CFLAGS) -shared -o libbelformat.dll belformat.o

psx_belformat: $(TARGETS)
	$(CC) $(CFLAGS) -shared -o libbelformat.so belformat.o

belformat.o:
	$(CC) $(CFLAGS) -c src/belformat.c -o belformat.o
