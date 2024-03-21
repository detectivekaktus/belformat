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

#define str_insert(str, val) \
  do { \
    while((str)->size + (strlen(val) + 1) >= (str)->capacity) { \
      (str)->capacity *= 2; \
      (str)->chars = realloc((str)->chars, (str)->capacity * sizeof(char)); \
    } \
    if ((str)->size == 0) { \
      strcpy((str)->chars + (str)->size, val); \
      (str)->size += strlen(val) + 1; \
    } else { \
      (str)->chars[(str)->size - 1] = 0; \
      (str)->size--; \
      strcpy((str)->chars + (str)->size, val); \
      (str)->size += strlen(val) + 1; \
    } \
  } while(0)

#define str_free(str) \
  do { \
    free((str)->chars); \
    free(str); \
  } while(0)

#endif // !BELFORMAT_IMPLEMENTATION_H
