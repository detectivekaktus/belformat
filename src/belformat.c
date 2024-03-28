#include "belformat.h"

void append_short_sequence(str *buffer, unsigned char a) {
  assert(a >= '0' && a <= '9');
  STR_APPEND(buffer, '\033');
  STR_APPEND(buffer, '[');
  STR_APPEND(buffer, a);
  STR_APPEND(buffer, 'm');
}

void append_long_sequence(str *buffer, unsigned char a, unsigned char b) {
  assert((a >= '0' && a <= '9') && (b >= '0' && a <= '9'));
  STR_APPEND(buffer, '\033');
  STR_APPEND(buffer, '[');
  STR_APPEND(buffer, a);
  STR_APPEND(buffer, b);
  STR_APPEND(buffer, 'm');
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
    if (*format == '#') {
      format++;
      steps++;
      int fg_hex_steps = append_hex_color(format, buffer, '3');
      format += fg_hex_steps;
      steps += fg_hex_steps;
    } else {
      int fg_steps = append_color(format, buffer, '3');
      format += fg_steps;
      steps += fg_steps;
    }
    assert(*format == '>' || *format == ';');
    if (*format == '>') {
      steps++;
    } else {
      format++;
      steps++;
      if (*format == '#') {
        format++;
        steps++;
        int bg_hex_steps = append_hex_color(format, buffer, '4');
        format += bg_hex_steps;
        steps += bg_hex_steps;
      } else {
        int bg_steps = append_color(format, buffer, '4');
        format += bg_steps;
        steps += bg_steps;
      }
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

// TODO #1: Extract `extract_primary_color` function to get
// red, green, and blue values.
// TODO #3: Extraact `STR_APPEND_RGB` macro to set RGB values.
int append_hex_color(const char *format, str *buffer, unsigned char mode) {
  int steps = 0;
  char hex_r[3];
  char hex_g[3];
  char hex_b[3];
  
  for (int i = 0; i < 2; i++) {
    assert(is_hex(*format));
    hex_r[i] = *format;
    format++;
    steps++;
  }
  hex_r[2] = '\0';
  char *int_r = strhex1b_to_strint1b(hex_r);

  for (int i = 0; i < 2; i++) {
    assert(is_hex(*format));
    hex_g[i] = *format;
    format++;
    steps++;
  }
  hex_g[2] = '\0';
  char *int_g = strhex1b_to_strint1b(hex_g);

  for (int i = 0; i < 2; i++) {
    assert(is_hex(*format));
    hex_b[i] = *format;
    format++;
    steps++;
  }
  hex_b[2] = '\0';
  char *int_b = strhex1b_to_strint1b(hex_b);

  STR_APPEND(buffer, '\033');
  STR_APPEND(buffer, '[');
  STR_APPEND(buffer, mode);
  STR_APPEND(buffer, '8');
  STR_APPEND(buffer, ';');
  STR_APPEND(buffer, '2');
  STR_APPEND(buffer, ';');
  for (int i = 0; i < strlen(int_r); i++) STR_APPEND(buffer, int_r[i]);
  STR_APPEND(buffer, ';');
  for (int i = 0; i < strlen(int_g); i++) STR_APPEND(buffer, int_g[i]);
  STR_APPEND(buffer, ';');
  for (int i = 0; i < strlen(int_b); i++) STR_APPEND(buffer, int_b[i]);
  STR_APPEND(buffer, 'm');

  free(int_r);
  free(int_g);
  free(int_b);

  return steps;
}

char *strhex1b_to_strint1b(const char *hex) {
  int hex_int = strtol(hex, NULL, 16);
  char *str_int = calloc(4, sizeof(char));
  snprintf(str_int, 4, "%d", hex_int);
  return str_int;
}

bool is_hex(const char c) {
  return ((c >= '0' && c <= '9') || (toupper(c) >= 'A' && toupper(c) <= 'F'));
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
  STR_START(buffer);

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
          if (*format == '#') {
            format++;
            format += append_hex_color(format, buffer, '3');
          } else {
            format += append_color(format, buffer, '3');
          }
          assert(*format == '>' || *format == ';');
          if (*format == '>') {
            format++;
          } else {
            format++;
            if (*format == '#') {
              format++;
              format += append_hex_color(format, buffer, '4');
            } else {
              format += append_color(format, buffer, '4');
            }
            assert(*format == '>');
            format++;
          }
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
          STR_APPEND(buffer, '<');
          break;
        }
      }
    } else {
      STR_APPEND(buffer, *format);
      format++;
    }
  }

  int result = vfprintf(stream, buffer->chars, args);
  STR_FREE(buffer);
  return result;
}
