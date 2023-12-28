#include "s21_sprintf.h"
#include "s21_string.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int to_number(const char **format);
void set_format_spec(const char **format, va_list *arguments,
                     FormatSpecifier *temp_spec);
void get_spec(const char **format,FormatSpecifier *get_spec);
void  print_to_str(char **str,FormatSpecifier *full_spec,va_list *arguments,char *str_begin);
int main() {
  char str[1000];
  s21_sprintf(str, "%-+0#1000.4ld i% hd i%06.5f i%-.*Lc", 500700, 500, 300, 23.56,
              "h");
  printf("main str:%s",str);
  return 0;
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list arguments_to_format;
  va_start(arguments_to_format, format);
  char *str_begin = str;
  while (*format != '\0') {
    if (*format == '%') {
      FormatSpecifier format_spec = {0};
      set_format_spec(&format, &arguments_to_format, &format_spec);
      printf("%c minus:%d plus:%d space:%d hash:%d  zero:%d width:%d accuracy:%d\n lengh:%c\n type:%c\n",
       *format, format_spec.minus, format_spec.plus, format_spec.space,
       format_spec.hash, format_spec.zero, format_spec.width,
       format_spec.accuracy,format_spec.lenghtmode,format_spec.type);
      print_to_str(&str,&format_spec,&arguments_to_format,str_begin);
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

void set_format_spec(const char **format, va_list *arguments,
                     FormatSpecifier *temp_spec) {
  (*format)++;
  while (s21_strchr("-+ #0", **format)) {
    switch (**format) { // Заменить потом на if
    case '-':
      temp_spec->minus = true;
      break;
    case '+':
      temp_spec->plus = true;
      break;
    case ' ':
      temp_spec->space = true;
      break;
    case '#':
      temp_spec->hash = true;
      break;
    case '0':
      temp_spec->zero = true;
      break;
    }
    (*format)++;
  }
  temp_spec->space = (temp_spec->space && !temp_spec->plus);
  temp_spec->zero = (temp_spec->zero && !temp_spec->minus);
  if (**format == '*') {
    temp_spec->width = va_arg(*arguments, unsigned long long);
    (*format)++;
  } else {
    temp_spec->width = to_number(format);
  }
  if (**format == '.') {
    temp_spec->dot = true;
    (*format)++;
    if (**format == '*') {
      temp_spec->accuracy = va_arg(*arguments, unsigned long long);
      (*format)++;
    } else {
      temp_spec->accuracy = to_number(format);
    }
  }
  if (s21_strchr("hlL", **format)) {
    temp_spec->lenghtmode = **format;
    (*format)++;
  }
   get_spec(format,temp_spec);
}

int to_number(const char **format) {
  int res = 0;
  int mull_ten = 10;
  int more_than_one = false;
  while (**format > 47 && **format < 58) {
    res = res * 10 + (**format - 48);
    (*format)++;
  }
  return res;
}

void get_spec(const char **format,FormatSpecifier *get_spec){
  char array_spec[18]="cdieEfFgGosuxXpn%";
if (s21_strchr("cdieEfFgGosuxXpn%", **format)) {
    get_spec->type= **format;
    (*format)++;
  }
}

void print_to_str(char **str,FormatSpecifier *full_spec,va_list *arguments,char *str_begin){
char buf[7000];
if (full_spec->type == 'd' || full_spec->type == 'i') {
    //print_to_str_decimal(full_spec, str,arguments, buf);
  } else if (full_spec->type == 'u'||  full_spec->type == 'o' ||
             full_spec->type == 'x' || full_spec->type == 'X') {
    //print_to_str_unsigned(full_spec, str,arguments, buf);
  } else if (full_spec->type == 'c') {
    //print_to_str_symbol(full_spec, str, arguments);
  } else if (full_spec->type == 's') {
    //print_to_str_str(full_spec, str, arguments);
  } else if (full_spec->type == 'p') {
    //print_to_str_unsigned(arguments, str, arguments, buf);
  } else if (full_spec->type == 'n') {
    // int *n = (int *)va_arg(*arguments, int *);
    // *n = (int)(*str - str_begin);
  } else if (full_spec->type == '%') {
    //print_to_str_percent(full_spec, str, buf);
  } else if (full_spec->type == 'f' || full_spec->type == 'F') {
    //print_to_str_double(full_spec, str, arguments, buf);
  } else if (full_spec->type == 'e' || full_spec->type == 'E') {
    //print_to_str_e(full_spec, str, arguments, buf);
  } else if (full_spec->type == 'g' || full_spec->type == 'G') {
    //print_to_str_g(full_spec, str, arguments, buf);
  }
}