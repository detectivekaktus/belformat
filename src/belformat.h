#ifndef BELFORMAT_IMPLEMENTATION_H
#define BELFORMAT_IMPLEMENTATION_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>

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
      (str)->capacity += 2; \
      (str)->chars = realloc((str)->chars, (str)->capacity * sizeof(char)); \
    } \
    if ((str)->size == 0) { \
      (str)->size++; \
      (str)->chars[(str)->size - 1] = val; \
      (str)->size++; \
      (str)->chars[(str)->size - 1] = '\0'; \
    } else { \
      (str)->chars[(str)->size - 1] = 0; \
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

void append_one_sequence(str *buffer, unsigned char a);
void append_syntax_error(str *buffer, unsigned char token, unsigned char got);
int belprintf(const char *format, ...);
int fbelprintf(FILE *stream, const char *format, ...);
int vbelprintf(const char *format, va_list args);
int vfbelprintf(FILE *stream, const char *format, va_list args);

#endif // !BELFORMAT_IMPLEMENTATION_H
