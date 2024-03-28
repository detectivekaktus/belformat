#ifndef BELFORMAT_IMPLEMENTATION_H
#define BELFORMAT_IMPLEMENTATION_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#define INIT_STRING_CAPACITY 128
typedef struct {
  char *chars;
  size_t size;
  size_t capacity;
} str;

#define STR_START(str) \
  do { \
    (str)->chars = calloc(INIT_STRING_CAPACITY, sizeof(char)); \
    (str)->size = 0; \
    (str)->capacity = INIT_STRING_CAPACITY; \
  } while(0) 

// TODO #2: define str_long_append that appends a string
// to the current buffer
#define STR_APPEND(str, val) \
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

#define STR_FREE(str) \
  do { \
    free((str)->chars); \
    free(str); \
  } while(0)

void append_short_sequence(str *buffer, unsigned char a);
void append_long_sequence(str *buffer, unsigned char a, unsigned char b);

int append_sequence(const char *format, str *buffer, unsigned char token);
int append_color(const char *format, str *buffer, unsigned char token);
int append_hex_color(const char *format, str *buffer, unsigned char mode);

/* Converts a 1 byte long string hexadecimal value to a 1 byte long
 * string decimal value. Be careful! You need to free the pointer once
 * you're done using the string gotten from this function! */
char *strhex1b_to_strint1b(const char *hex);
bool is_hex(const char c);

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

void belinfo(const char *msg, ...);
void belwarn(const char *msg, ...);
void belerror(const char *msg, ...);
void bellog(const char *msg, ...);

#endif // !BELFORMAT_IMPLEMENTATION_H
