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

int append_sequence(const char *format, str *buffer, unsigned char token) {
  int steps = 0;

  format++;
  steps++;
  assert(*format == '>' || *format == ';');
  if (*format == '>') {
    append_short_sequence(buffer, token);
    steps++;
  } else if (*format == ';') {
    append_short_sequence(buffer, token);
    format++;
    steps++;
    int fg_steps = append_color(format, buffer, '3');
    format += fg_steps;
    steps += fg_steps;
    assert(*format == '>' || *format == ';');
    if (*format == '>')
      steps++;
    else {
      format++;
      steps++;
      int bg_steps = append_color(format, buffer, '4');
      format += bg_steps;
      steps += bg_steps;
      assert(*format == '>');
      steps++;
    }
  }

  return steps;
}

int append_color(const char *format, str *buffer, unsigned char token) {
  char color[9];
  int i = 0;
  while ((*format != '>' && i < 8) && (*format != ';' && i < 8)) {
    color[i] = *format;
    i++;
    format++;
  }
  color[i] = '\0';

  if (strcmp(color, "black") == 0) append_long_sequence(buffer, token, '0');
  if (strcmp(color, "red") == 0) append_long_sequence(buffer, token, '1');
  if (strcmp(color, "green") == 0) append_long_sequence(buffer, token, '2');
  if (strcmp(color, "yellow") == 0) append_long_sequence(buffer, token, '3');
  if (strcmp(color, "blue") == 0) append_long_sequence(buffer, token, '4');
  if (strcmp(color, "magenta") == 0) append_long_sequence(buffer, token, '5');
  if (strcmp(color, "cyan") == 0) append_long_sequence(buffer, token, '6');
  if (strcmp(color, "white") == 0) append_long_sequence(buffer, token, '7');
  return i;
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
          format += append_sequence(format, buffer, '1');
          break;
        }
        case 'd': {
          format += append_sequence(format, buffer, '2');
          break;
        }
        case 'i': {
          format += append_sequence(format, buffer, '3');
          break;
        }
        case 'u': {
          format += append_sequence(format, buffer, '4');
          break;
        }
        case 'l': {
          format += append_sequence(format, buffer, '5');
          break;
        }
        case 'r': {
          format += append_sequence(format, buffer, '7');
          break;
        }
        case 'p': {
          format += append_sequence(format, buffer, '8');
          break;
        }
        case 's': {
          format += append_sequence(format, buffer, '9'); 
          break;
        }
        case 'c': {
          format++;
          assert(*format == ';');
          format++;
          format += append_color(format, buffer, '3') + 1;
          break;
        }
        case '/': {
          format++;
          assert(*format == '>');
          append_short_sequence(buffer, '0');
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

  int result = vfprintf(stream, buffer->chars, args);
  str_free(buffer);
  return result;
}
