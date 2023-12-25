#include "s21_sprintf.h"
#include "s21_string.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int to_number(const char **format);
void set_format_spec(const char **format, va_list *arguments);
int main() {
  char str[1000];
  s21_sprintf(str, "%-+0#1000.4d % d %06.5f %-.*c", 500700, 500, 300, 23.56, "h");
  // printf("%s",str);
  return 0;
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list arguments_to_format;
  va_start(arguments_to_format, format);
  char *str_begin = str;
  while (*format != '\0') {
    if (*format == '%') {
      set_format_spec(&format, &arguments_to_format);
    } else {
      *str = *format;
      format++;
      str++;
    }
  }
  *str = '\0';
  s21_size_t quantity = *str_begin - *str;
  return quantity;
}

void set_format_spec(const char **format, va_list *arguments) {
  FormatSpecifier temp_spec = {0};
  (*format)++;
  while (s21_strchr("-+ #0", **format)) {
    switch (**format) { // Заменить потом на if
    case '-':
      temp_spec.minus = true;
      break;
    case '+':
      temp_spec.plus = true;
      break;
    case ' ':
      temp_spec.space = true;
      break;
    case '#':
      temp_spec.hash = true;
      break;
    case '0':
      temp_spec.zero = true;
      break;
    }
    (*format)++;
  }
  temp_spec.space = (temp_spec.space && !temp_spec.plus);
  temp_spec.zero = (temp_spec.zero && !temp_spec.minus);
  if (**format == '*') {
    temp_spec.width = va_arg(*arguments, unsigned long long);
    (*format)++;
  } else {
    temp_spec.width = to_number(format);
  }
  if (**format == '.') {
    temp_spec.dot = true;
    (*format)++;
    if (**format == '*') {
      temp_spec.accuracy = va_arg(*arguments, unsigned long long);
      (*format)++;
    } else {
      temp_spec.accuracy = to_number(format);
    }
  }
  printf("%c minus:%d plus:%d space:%d hash:%d  zero:%d width:%d accuracy:%d\n",
         **format, temp_spec.minus, temp_spec.plus, temp_spec.space,
         temp_spec.hash, temp_spec.zero, temp_spec.width, temp_spec.accuracy);
}

int to_number(const char **format){
    int res = 0;
    int mull_ten=10;
    int more_than_one = false;
    while(**format>47&&**format<58){
      res = res*10 + (**format - 48);
      (*format)++;
    }
    return res;
} 
