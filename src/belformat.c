#include "belformat.h"

void append_short_sequence(str *buffer, unsigned char a) {
  if (a >= 48 && a <= 57) {
    str_append(buffer, '\033');
    str_append(buffer, '[');
    str_append(buffer, a);
    str_append(buffer, 'm');
  }
}

void append_long_sequence(str *buffer, unsigned char a, unsigned char b) {
  if ((a >= 48 && a <= 57) && (b >= 48 && b <= 57)) {
    str_append(buffer, '\033');
    str_append(buffer, '[');
    str_append(buffer, a);
    str_append(buffer, b);
    str_append(buffer, 'm');
  }
}

int belprintf(const char *format, ...) {
  va_list args;
  va_start(args, format);
  int result = vfbelprintf(stdout, format, args);
  va_end(args);
  return result;
}

int fbelprintf(FILE *stream, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int result = vfbelprintf(stream, format, args);
  va_end(args);
  return result;
}

int vbelprintf(const char *format, va_list args) {
  return vfbelprintf(stdout, format, args);
}

int vfbelprintf(FILE *stream, const char *format, va_list args) {
  str *buffer = malloc(sizeof(str));
  str_start(buffer);

  while (*format != '\0') {
    if (*format == '<') {
      format++;
      switch (*format) {
        case 'b': {
          format++;
          if (*format == '>') {
            append_short_sequence(buffer, 49);
            format++;
          }
          break;
        }
        case 'i': {
          format++;
          if (*format == '>') {
            append_short_sequence(buffer, 51);
            format++;
          }
          break;
        }
        case 'u': {
          format++;
          if (*format == '>') {
            append_short_sequence(buffer, 52);
            format++;
          }
          break;
        }
        case 's': {
          format++;
          if (*format == '>') {
            append_short_sequence(buffer, 57);
            format++;
          }
          break;
        }
        case 'd': {
          format++;
          if (*format == '>') {
            append_short_sequence(buffer, 50);
            format++;
          }
          break;
        }
        case 'l': {
          format++;
          if (*format == '>') {
            append_short_sequence(buffer, 53);
            format++;
          }
          break;
        }
        case 'p': {
          format++;
          if (*format == '>') {
            append_short_sequence(buffer, 56);
            format++;
          }
          break;
        }
        case 'r': {
          format++;
          if (*format == '>') {
            append_short_sequence(buffer, 55);
            format++;
          }
          break;
        }
        case '/': {
          format++;
          if (*format == '>') {
            append_short_sequence(buffer, 48);
            format++;
          }
          break;
        }
        default: {
          str_append(buffer, '<');
          break;
        }
      }
    } else {
      str_append(buffer, *format);
      format++;
    }
  }

  int result = vfprintf(stream, buffer->chars, args);
  str_free(buffer);
  return result;
}
