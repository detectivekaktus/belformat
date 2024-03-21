#include "belformat.h"

void append_one_sequence(str *buffer, unsigned char a) {
  if (a >= 48 && a <= 57) {
    str_append(buffer, '\033');
    str_append(buffer, '[');
    str_append(buffer, a);
    str_append(buffer, 'm');
  }
}

void append_syntax_error(str *buffer, unsigned char token, unsigned char got) {
  str_append(buffer, '<');
  str_append(buffer, token);
  str_append(buffer, got);
}

int belprintf(const char *format, ...) {
  va_list args;
  str *buffer = malloc(sizeof(str));
  str_start(buffer);

  while (*format != '\0') {
    if (*format == '<') {
      format++;
      switch (*format) {
        case 'b': {
          format++;
          if (*format == '>') append_one_sequence(buffer, 49);
          else append_syntax_error(buffer, 'b', *format);
          format++;
          break;
        }
        case 'i': {
          format++;
          if (*format == '>') append_one_sequence(buffer, 51);
          else append_syntax_error(buffer, 'i', *format);
          format++;
          break;
        }
        case 'u': {
          format++;
          if (*format == '>') append_one_sequence(buffer, 52);
          else append_syntax_error(buffer, 'u', *format);
          format++;
          break;
        }
        case 's': {
          format++;
          if (*format == '>') append_one_sequence(buffer, 57);
          else append_syntax_error(buffer, 's', *format);
          format++;
          break;
        }
        case 'd': {
          format++;
          if (*format == '>') append_one_sequence(buffer, 50);
          else append_syntax_error(buffer, 'd', *format);
          format++;
          break;
        }
        case 'l': {
          format++;
          if (*format == '>') append_one_sequence(buffer, 53);
          else append_syntax_error(buffer, 'l', *format);
          format++;
          break;
        }
        case 'p': {
          format++;
          if (*format == '>') append_one_sequence(buffer, 56);
          else append_syntax_error(buffer, 'p', *format);
          format++;
          break;
        }
        case 'r': {
          format++;
          if (*format == '>') append_one_sequence(buffer, 55);
          else append_syntax_error(buffer, 'r', *format);
          format++;
          break;
        }
        case '/': {
          format++;
          if (*format == '>') append_one_sequence(buffer, 48);
          else append_syntax_error(buffer, '/', *format);
          format++;
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

  int result = vprintf(buffer->chars, args);
  str_free(buffer);
  return result;
}
