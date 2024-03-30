CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -ggdb
BUILD_DIR = build
TARGETS = belformat.o

win_belformat: $(TARGETS)
	$(CC) $(CFLAGS) -shared -fPIC -o libbelformat.dll $(TARGETS)

psx_belformat: $(TARGETS)
	$(CC) $(CFLAGS) -shared -fPIC -o libbelformat.so $(TARGETS)

static_belformat: $(TARGETS)
	ar rcs libbelformat.a belformat.o

examples: belformat.o exam.o
	$(CC) $(CFLAGS) -o exam belformat.o exam.o

exam.o:
	$(CC) $(CFLAGS) -c examples/examples.c -o exam.o

belformat.o:
	$(CC) $(CFLAGS) -fPIC -c src/belformat.c -o belformat.o
