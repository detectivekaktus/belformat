#include "belformat.h"
#include <string.h>

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
          if (*format == ';') {
            append_short_sequence(buffer, '1');
            format++;

            char color[8];
            int i = 0;
            while (*format != '>' && i < 8) {
              color[i] = *format;
              i++;
              format++;
            }
            color[i] = '\0';

            if (strcmp(color, "black") == 0) append_long_sequence(buffer, '3', '0');
            if (strcmp(color, "red") == 0) append_long_sequence(buffer, '3', '1');
            if (strcmp(color, "green") == 0) append_long_sequence(buffer, '3', '2');
            if (strcmp(color, "yellow") == 0) append_long_sequence(buffer, '3', '3');
            if (strcmp(color, "blue") == 0) append_long_sequence(buffer, '3', '4');
            if (strcmp(color, "magenta") == 0) append_long_sequence(buffer, '3', '5');
            if (strcmp(color, "cyan") == 0) append_long_sequence(buffer, '3', '6');
            if (strcmp(color, "white") == 0) append_long_sequence(buffer, '3', '7');

            format++;
          } else if (*format == '>') {
            append_short_sequence(buffer, '1');
            format++;
          }
          break;
        }
        case 'i': {
          format++;
          if (*format == ';') {
            append_short_sequence(buffer, '3');
            format++;

            char color[8];
            int i = 0;
            while (*format != '>' && i < 8) {
              color[i] = *format;
              i++;
              format++;
            }
            color[i] = '\0';

            if (strcmp(color, "black") == 0) append_long_sequence(buffer, '3', '0');
            if (strcmp(color, "red") == 0) append_long_sequence(buffer, '3', '1');
            if (strcmp(color, "green") == 0) append_long_sequence(buffer, '3', '2');
            if (strcmp(color, "yellow") == 0) append_long_sequence(buffer, '3', '3');
            if (strcmp(color, "blue") == 0) append_long_sequence(buffer, '3', '4');
            if (strcmp(color, "magenta") == 0) append_long_sequence(buffer, '3', '5');
            if (strcmp(color, "cyan") == 0) append_long_sequence(buffer, '3', '6');
            if (strcmp(color, "white") == 0) append_long_sequence(buffer, '3', '7');

            format++;
          } else if (*format == '>') {
            append_short_sequence(buffer, '3');
            format++;
          }
          break;
        }
        case 'u': {
          format++;
          if (*format == ';') {
            append_short_sequence(buffer, '4');
            format++;

            char color[8];
            int i = 0;
            while (*format != '>' && i < 8) {
              color[i] = *format;
              i++;
              format++;
            }
            color[i] = '\0';

            if (strcmp(color, "black") == 0) append_long_sequence(buffer, '3', '0');
            if (strcmp(color, "red") == 0) append_long_sequence(buffer, '3', '1');
            if (strcmp(color, "green") == 0) append_long_sequence(buffer, '3', '2');
            if (strcmp(color, "yellow") == 0) append_long_sequence(buffer, '3', '3');
            if (strcmp(color, "blue") == 0) append_long_sequence(buffer, '3', '4');
            if (strcmp(color, "magenta") == 0) append_long_sequence(buffer, '3', '5');
            if (strcmp(color, "cyan") == 0) append_long_sequence(buffer, '3', '6');
            if (strcmp(color, "white") == 0) append_long_sequence(buffer, '3', '7');

            format++;
          } else if (*format == '>') {
            append_short_sequence(buffer, '4');
            format++;
          }
          break;
        }
        case 's': {
          format++;
          if (*format == ';') {
            append_short_sequence(buffer, '9');
            format++;

            char color[8];
            int i = 0;
            while (*format != '>' && i < 8) {
              color[i] = *format;
              i++;
              format++;
            }
            color[i] = '\0';

            if (strcmp(color, "black") == 0) append_long_sequence(buffer, '3', '0');
            if (strcmp(color, "red") == 0) append_long_sequence(buffer, '3', '1');
            if (strcmp(color, "green") == 0) append_long_sequence(buffer, '3', '2');
            if (strcmp(color, "yellow") == 0) append_long_sequence(buffer, '3', '3');
            if (strcmp(color, "blue") == 0) append_long_sequence(buffer, '3', '4');
            if (strcmp(color, "magenta") == 0) append_long_sequence(buffer, '3', '5');
            if (strcmp(color, "cyan") == 0) append_long_sequence(buffer, '3', '6');
            if (strcmp(color, "white") == 0) append_long_sequence(buffer, '3', '7');

            format++;
          } else if (*format == '>') {
            append_short_sequence(buffer, '9');
            format++;
          }
          break;
        }
        case 'd': {
          format++;
          if (*format == ';') {
            append_short_sequence(buffer, '2');
            format++;

            char color[8];
            int i = 0;
            while (*format != '>' && i < 8) {
              color[i] = *format;
              i++;
              format++;
            }
            color[i] = '\0';

            if (strcmp(color, "black") == 0) append_long_sequence(buffer, '3', '0');
            if (strcmp(color, "red") == 0) append_long_sequence(buffer, '3', '1');
            if (strcmp(color, "green") == 0) append_long_sequence(buffer, '3', '2');
            if (strcmp(color, "yellow") == 0) append_long_sequence(buffer, '3', '3');
            if (strcmp(color, "blue") == 0) append_long_sequence(buffer, '3', '4');
            if (strcmp(color, "magenta") == 0) append_long_sequence(buffer, '3', '5');
            if (strcmp(color, "cyan") == 0) append_long_sequence(buffer, '3', '6');
            if (strcmp(color, "white") == 0) append_long_sequence(buffer, '3', '7');

            format++;
          } else if (*format == '>') {
            append_short_sequence(buffer, '2');
            format++;
          }
          break;
        }
        case 'l': {
          format++;
          if (*format == ';') {
            append_short_sequence(buffer, '5');
            format++;

            char color[8];
            int i = 0;
            while (*format != '>' && i < 8) {
              color[i] = *format;
              i++;
              format++;
            }
            color[i] = '\0';

            if (strcmp(color, "black") == 0) append_long_sequence(buffer, '3', '0');
            if (strcmp(color, "red") == 0) append_long_sequence(buffer, '3', '1');
            if (strcmp(color, "green") == 0) append_long_sequence(buffer, '3', '2');
            if (strcmp(color, "yellow") == 0) append_long_sequence(buffer, '3', '3');
            if (strcmp(color, "blue") == 0) append_long_sequence(buffer, '3', '4');
            if (strcmp(color, "magenta") == 0) append_long_sequence(buffer, '3', '5');
            if (strcmp(color, "cyan") == 0) append_long_sequence(buffer, '3', '6');
            if (strcmp(color, "white") == 0) append_long_sequence(buffer, '3', '7');

            format++;
          } else if (*format == '>') {
            append_short_sequence(buffer, '5');
            format++;
          }
          break;
        }
        case 'p': {
          format++;
          if (*format == ';') {
            append_short_sequence(buffer, '8');
            format++;

            char color[8];
            int i = 0;
            while (*format != '>' && i < 8) {
              color[i] = *format;
              i++;
              format++;
            }
            color[i] = '\0';

            if (strcmp(color, "black") == 0) append_long_sequence(buffer, '3', '0');
            if (strcmp(color, "red") == 0) append_long_sequence(buffer, '3', '1');
            if (strcmp(color, "green") == 0) append_long_sequence(buffer, '3', '2');
            if (strcmp(color, "yellow") == 0) append_long_sequence(buffer, '3', '3');
            if (strcmp(color, "blue") == 0) append_long_sequence(buffer, '3', '4');
            if (strcmp(color, "magenta") == 0) append_long_sequence(buffer, '3', '5');
            if (strcmp(color, "cyan") == 0) append_long_sequence(buffer, '3', '6');
            if (strcmp(color, "white") == 0) append_long_sequence(buffer, '3', '7');

            format++;
          } else if (*format == '>') {
            append_short_sequence(buffer, '8');
            format++;
          }
          break;
        }
        case 'r': {
          format++;
          if (*format == ';') {
            append_short_sequence(buffer, '7');
            format++;

            char color[8];
            int i = 0;
            while (*format != '>' && i < 8) {
              color[i] = *format;
              i++;
              format++;
            }
            color[i] = '\0';

            if (strcmp(color, "black") == 0) append_long_sequence(buffer, '3', '0');
            if (strcmp(color, "red") == 0) append_long_sequence(buffer, '3', '1');
            if (strcmp(color, "green") == 0) append_long_sequence(buffer, '3', '2');
            if (strcmp(color, "yellow") == 0) append_long_sequence(buffer, '3', '3');
            if (strcmp(color, "blue") == 0) append_long_sequence(buffer, '3', '4');
            if (strcmp(color, "magenta") == 0) append_long_sequence(buffer, '3', '5');
            if (strcmp(color, "cyan") == 0) append_long_sequence(buffer, '3', '6');
            if (strcmp(color, "white") == 0) append_long_sequence(buffer, '3', '7');

            format++;
          } else if (*format == '>') {
            append_short_sequence(buffer, '7');
            format++;
          }
          break;
        }
        case '/': {
          format++;
          if (*format == '>') {
            append_short_sequence(buffer, '0');
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
