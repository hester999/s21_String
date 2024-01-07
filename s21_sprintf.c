#include "s21_sprintf.h"

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"
#include "string.h"

int to_number(const char **format);
int to_char_int(long int num, char *buf);
int to_char_unsigned(unsigned long int num, char *buf);
void set_format_spec(const char **format, va_list *arguments,
                     FormatSpecifier *temp_spec);
void get_spec(const char **format, FormatSpecifier *get_spec);
void print_to_str(char **str, FormatSpecifier *full_spec, va_list *arguments,
                  char *str_begin);
void print_to_str_decimal(FormatSpecifier *full_spec, char **str,
                          va_list *arguments, char *buf);
void print_to_str_unsigned(FormatSpecifier *full_spec, char **str,
                           va_list *arguments, char *buf);
void print_to_str_symbol(FormatSpecifier *full_spec, char **str,
                         va_list *arguments, char *buf);
void print_to_str_str(FormatSpecifier *full_spec, char **str,
                      va_list *arguments, char *buf);
void save_buf_to_str(char **str, char *buf);
void off_on_specificators(FormatSpecifier *format_spec);

/*
int main() {
  char str[1000];
  char str1[1000];
  // int val = 3015;
  // int val2 = -7126;
  // int val3 = -99;
  // int val4 = -2939;
  //int val4 =2147483647;
  //printf("kklk%d\n",__INT_MAX__);
  // sprintf(str1, "Hello %010u %hd %+024d", 10, 253, -7);
  //sprintf(str1, "%10.20d Test %-8d Test %-7d TEST %d", val, val2, val3, val4);
  sprintf(str1, "Hello %c %d",'y', 110);
  printf("%s\n", str1);
  //s21_sprintf(str, "Hello %010u %hd %+024d", 10, 253, -7);
  //s21_sprintf(str, "%10.20d Test %-8d Test %-7d TEST %d", val, val2, val3,
val4);
  //s21_sprintf(str, "%10d Test %8d Test %7d TEST %d", val, val2, val3, val4);
  //s21_sprintf(str, "%10d Test %8d Test %7d TEST %d", val, val2, val3, val4);
  s21_sprintf(str, "Hello %c %d", 'y', 110);
  printf("%s\n", str);
  return 0;
}
*/

int s21_sprintf(char *str, const char *format, ...) {
  va_list arguments_to_format;
  va_start(arguments_to_format, format);
  char *str_begin = str;
  while (*format != '\0') {
    if (*format == '%') {
      FormatSpecifier format_spec = {0};
      set_format_spec(&format, &arguments_to_format, &format_spec);
      print_to_str(&str, &format_spec, &arguments_to_format, str_begin);
    } else {
      *str = *format;
      format++;
      str++;
    }
  }
  *str = '\0';

  s21_size_t quantity = (int)(str - str_begin);
  return quantity;
}

void set_format_spec(const char **format, va_list *arguments,
                     FormatSpecifier *temp_spec) {
  (*format)++;
  while (s21_strchr("-+ #0", **format)) {
    switch (**format) {  // Заменить потом на if
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
  get_spec(format, temp_spec);
}

int to_number(const char **format) {
  int res = 0;
  while (**format > 47 && **format < 58) {
    res = res * 10 + (**format - 48);
    (*format)++;
  }
  return res;
}

void get_spec(const char **format, FormatSpecifier *get_spec) {
  if (s21_strchr("cdieEfFgGosuxXpn%", **format)) {
    get_spec->sprintf_type = **format;
    (*format)++;
  }
  // off_on_specificators(get_spec);//Делаем настройку для спецификаторов,
  // убираем ненужные флаги
}

void print_to_str(char **str, FormatSpecifier *full_spec, va_list *arguments,
                  char *str_begin) {
  char buf[7000];
  s21_memset(buf, 0, sizeof(buf));
  if (full_spec->sprintf_type == 'd' || full_spec->sprintf_type == 'i') {
    print_to_str_decimal(full_spec, str, arguments, buf);
  } else if (full_spec->sprintf_type == 'u' || full_spec->sprintf_type == 'o' ||
             full_spec->sprintf_type == 'x' || full_spec->sprintf_type == 'X') {
    print_to_str_unsigned(full_spec, str, arguments,
                          buf);  // Только спецификатор u
  } else if (full_spec->sprintf_type == 'c') {
    print_to_str_symbol(full_spec, str, arguments, buf);
  } else if (full_spec->sprintf_type == 's') {
    // print_to_str_str(full_spec, str, arguments);
  } else if (full_spec->sprintf_type == 'p') {
    // print_to_str_unsigned(arguments, str, arguments, buf);
  } else if (full_spec->sprintf_type == 'n') {
    int *n = (int *)va_arg(*arguments, int *);
    *n = (int)(*str - str_begin);
  } else if (full_spec->sprintf_type == '%') {
    // print_to_str_percent(full_spec, str, buf);
  } else if (full_spec->sprintf_type == 'f' || full_spec->sprintf_type == 'F') {
    // print_to_str_double(full_spec, str, arguments, buf);
  } else if (full_spec->sprintf_type == 'e' || full_spec->sprintf_type == 'E') {
    // print_to_str_e(full_spec, str, arguments, buf);
  } else if (full_spec->sprintf_type == 'g' || full_spec->sprintf_type == 'G') {
    // print_to_str_g(full_spec, str, arguments, buf);
  }
}

void print_to_str_decimal(FormatSpecifier *full_spec, char **str,
                          va_list *arguments, char *buf) {
  long int number = 0;
  int flag_minus = false;
  long int add_width = 0;
  if (full_spec->lenghtmode == 'l')
    number = (long int)va_arg(*arguments, long int);
  else if (full_spec->lenghtmode == 'h')
    number = (int)va_arg(*arguments, int);
  else
    number = (int)va_arg(*arguments, int);
  if (number < 0) {  // сохраняем отрицательный знак
    flag_minus = true;
  }
  to_char_int(number, buf);
  long int len = (long int)strlen(buf);
  // Обрабатываем точность
  if (full_spec->accuracy) {
    long int add_accurcy = full_spec->accuracy - len;
    while (add_accurcy-- > 0) {
      buf[len++] = '0';
    }
  }
  len = (long int)strlen(buf);
  // Обрабатываем ширину
  if ((flag_minus || full_spec->plus) && (full_spec->zero)) {
    add_width = full_spec->width - len - 1;
  } else {
    add_width = full_spec->width - len;
  }
  while (add_width-- > 0 && full_spec->zero && !full_spec->minus) {
    buf[len++] = '0';
  }
  // Ширина со знаком минус
  if (full_spec->minus && add_width > 0 &&
      full_spec->width) {  // Ширина со знаком минус
    int add = (int)(add_width);
    for (int i = len - 1; i >= 0; i--) {
      buf[i + add] = buf[i];
    }
    for (int i = 0; i < add_width; i++) {
      buf[i] = ' ';
    }
    len = (long int)strlen(buf);
  }
  if (full_spec->plus && !flag_minus) {
    buf[len] = '+';
    len++;
  }
  if (flag_minus) {
    buf[len] = '-';
    len++;
  }
  while (add_width-- > 0 && !full_spec->zero && !full_spec->minus) {
    buf[len++] = ' ';
  }
  buf[len] = '\0';
  save_buf_to_str(str, buf);
}

int to_char_int(long int num, char *buf) {
  int quantity_of_sym = 0;
  long int temp_num = num;
  if (num < 0) {
    temp_num = temp_num * (-1);
  }
  char sym = '0';
  if (temp_num == 0) {
    buf[quantity_of_sym] = '0';
    quantity_of_sym++;
  } else {
    while (temp_num > 0) {
      sym = temp_num % 10 + 48;
      temp_num = temp_num / 10;
      buf[quantity_of_sym] = sym;
      quantity_of_sym++;
    }
  }
  return quantity_of_sym;
}

int to_char_unsigned(unsigned long int num, char *buf) {
  int quantity_of_sym = 0;
  unsigned long int temp_num = num;
  char sym = '0';
  if (temp_num == 0) {
    buf[quantity_of_sym] = '0';
    quantity_of_sym++;
  } else {
    while (temp_num > 0) {
      sym = temp_num % 10 + 48;
      temp_num = (temp_num / 10);
      buf[quantity_of_sym] = sym;
      quantity_of_sym++;
    }
  }
  return quantity_of_sym;
}

void save_buf_to_str(char **str, char *buf) {
  long int len = (long int)strlen(buf);
  for (int i = len - 1; i >= 0; i--) {
    *(*str)++ = buf[i];
  }
  s21_memset(buf, 0, sizeof(buf));
}

void set_number_system(FormatSpecifier *format_spec) {
  if (s21_strchr("dieEfFgGu", format_spec->sprintf_type))
    format_spec->number_system = 10;
  if (s21_strchr("xXp", format_spec->sprintf_type))
    format_spec->number_system = 16;
  if (format_spec->sprintf_type == 'o') format_spec->number_system = 8;
}

void print_to_str_unsigned(FormatSpecifier *full_spec, char **str,
                           va_list *arguments, char *buf) {
  long int number = 0;
  int quantity = 0;
  if (full_spec->lenghtmode == 'l')
    number = (long int)va_arg(*arguments, long int);
  else if (full_spec->lenghtmode == 'h')
    number = (unsigned short int)va_arg(*arguments, unsigned int);
  else
    number = (int)va_arg(*arguments, int);
  if (number < 0) {
    number = (unsigned int)number;
  }
  quantity = to_char_unsigned(number, buf);
  if (full_spec->space) buf[quantity] = ' ';
  if (full_spec->accuracy) {
    long int len = (long int)strlen(buf);
    long int add_accurcy = full_spec->accuracy - len;
    while (add_accurcy-- > 0) {
      buf[len++] = '0';
    }
  }
  if (full_spec->width) {
    long int len = (long int)strlen(buf);
    long int add_width = full_spec->width - len;
    if (full_spec->minus && add_width > 0) {
      for (int i = len - 1; i >= 0; i--) {
        buf[i + add_width] = buf[i];
      }
      for (int i = 0; i < add_width; i++) {
        buf[i] = ' ';
      }
    } else {
      while (add_width-- > 0) {
        if (full_spec->zero) {
          buf[len++] = '0';
        } else {
          buf[len++] = ' ';
        }
      }
    }
  }
  save_buf_to_str(str, buf);
}

void print_to_str_symbol(FormatSpecifier *full_spec, char **str,
                         va_list *arguments, char *buf) {
  char sym = (int)va_arg(*arguments, int);
  long int add_width = 0;
  long int len = 0;
  buf[0] = sym;
  if (full_spec->width && !full_spec->minus) {
    add_width = full_spec->width;
    for (int i = 1; i < add_width; i++) {
      buf[i] = ' ';
    }
  }
  len = (long int)strlen(buf);
  if (full_spec->width &&
      full_spec->minus) {  // Обрабатываем ширину со знаком минус
    add_width = full_spec->width - 1;
    for (int i = len - 1; i >= 0; i--) {
      buf[i + add_width] = buf[i];
    }
    for (int i = 0; i < add_width; i++) {
      buf[i] = ' ';
    }
  }
  len = (long int)strlen(buf);
  buf[len] = '\0';
  save_buf_to_str(str, buf);
}

// void print_to_str_str(FormatSpecifier *full_spec, char **str, va_list
// *arguments,char *buf){

// }
// настройка под разные спецификаторы, убираем флаги которые не используются
void off_on_specificators(FormatSpecifier *format_spec) {
  if (s21_strchr("oxXu", format_spec->sprintf_type)) {
    format_spec->plus = 0;
    format_spec->space = 0;
  }
  if (format_spec->sprintf_type == 'c') {
    format_spec->plus = 0;
    format_spec->space = 0;
    format_spec->dot = 0;
    format_spec->accuracy = 0;
  }
  if (format_spec->sprintf_type == 's') {
    format_spec->plus = 0;
    format_spec->space = 0;
    format_spec->dot = 0;
  }
  if (format_spec->sprintf_type == 'p') {
    format_spec->dot = 1;
    format_spec->plus = 0;
    format_spec->space = 0;
    format_spec->lenghtmode = 'l';
    format_spec->sprintf_type = 'x';
  }
  if (format_spec->sprintf_type == '%') {
    format_spec->plus = 0;
    format_spec->space = 0;
    format_spec->dot = 0;
    format_spec->accuracy = 0;
  }
}
