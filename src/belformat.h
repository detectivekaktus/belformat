#ifndef BELFORMAT_IMPLEMENTATION_H
#define BELFORMAT_IMPLEMENTATION_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>

#define INIT_STRING_CAPACITY 128
typedef struct {
  char *chars;
  size_t size;
  size_t capacity;
} str;

#define str_start(str) \
  do { \
    (str)->chars = calloc(INIT_STRING_CAPACITY, sizeof(char)); \
    (str)->size = 0; \
    (str)->capacity = INIT_STRING_CAPACITY; \
  } while(0) 

// TODO #2: define str_long_append that appends a string
// to the current buffer
#define str_append(str, val) \
  do { \
    if ((str)->size == (str)->capacity) { \
      (str)->capacity += 1; \
      (str)->chars = realloc((str)->chars, (str)->capacity * sizeof(char)); \
    } \
    if ((str)->size == 0) { \
      (str)->size++; \
      (str)->chars[(str)->size - 1] = val; \
      (str)->size++; \
      (str)->chars[(str)->size - 1] = '\0'; \
    } else { \
      (str)->chars[(str)->size - 1] = val; \
      (str)->size++; \
      (str)->chars[(str)->size - 1] = '\0'; \
    } \
  } while(0)

#define str_free(str) \
  do { \
    free((str)->chars); \
    free(str); \
  } while(0)

void append_short_sequence(str *buffer, unsigned char a);
void append_long_sequence(str *buffer, unsigned char a, unsigned char b);

int append_sequence(const char *format, str *buffer, unsigned char token);
int append_color(const char *format, str *buffer, unsigned char token);

/* Outputs formatted string `format` to the stream `stream` with
 * `args` arguments. Extends the features of the `vfprintf` from
 * the standard C library adding styling tags to output bold, italic,
 * dim, underlined, strikethrought, blinking, hidden, and riversed
 * strings.
 *
 * Colores the characters with terminal-predefined colors: black, red, 
 * green, blue, yellow, cyan, magenta, and white. */
int vfbelprintf(FILE *stream, const char *format, va_list args);
int belprintf(const char *format, ...);
int fbelprintf(FILE *stream, const char *format, ...);
int vbelprintf(const char *format, va_list args);

#endif // !BELFORMAT_IMPLEMENTATION_H
