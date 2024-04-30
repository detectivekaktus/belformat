CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -ggdb
BUILD_DIR = build
SOURCES = src/belformat.c
TARGETS = belformat.o

win_belformat: $(TARGETS)
	$(CC) $(CFLAGS) -shared -fPIC -o libbelformat.dll $(TARGETS)

psx_belformat: $(TARGETS)
	$(CC) $(CFLAGS) -shared -fPIC -o libbelformat.so $(TARGETS)

static_belformat: $(TARGETS)
	ar rcs libbelformat.a belformat.o

$(TARGETS):
	$(CC) $(CFLAGS) -fPIC -c $(SOURCES) -o $(TARGETS)

examples: $(TARGETS)
	$(CC) $(CFLAGS) -c examples/examples.c -o exam.o
	$(CC) $(CFLAGS) -o exam belformat.o exam.o

clean:
	rm *.o
	rm *.so
