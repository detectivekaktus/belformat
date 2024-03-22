#ifndef BELFORMAT_IMPLEMENTATION_H
#define BELFORMAT_IMPLEMENTATION_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

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

/* Appends `\033[am` sequence to the print buffer. The `a` argument
 * must be a valid ASCII character from 48 to 57 (characters from 0
 * to 9). If `a` is invalid, nothing gets appended. */
void append_one_sequence(str *buffer, unsigned char a);

/* Appends `<token + got` sequence to the print buffer. The `token`
 * parameter represents the current token being processed while `got`
 * parameter is the character gotten from during parsing. */
void append_syntax_error(str *buffer, unsigned char token, unsigned char got);

/* Outputs formatted string `format` to the stream `stream` with
 * `args` arguments. Extends the features of the `vfprintf` from
 * the standard C library adding styling tags to output bold, italic,
 * dim, underlined, strikethrought, blinking, hidden, and riversed
 * strings. */
int vfbelprintf(FILE *stream, const char *format, va_list args);
int belprintf(const char *format, ...);
int fbelprintf(FILE *stream, const char *format, ...);
int vbelprintf(const char *format, va_list args);

#endif // !BELFORMAT_IMPLEMENTATION_H
