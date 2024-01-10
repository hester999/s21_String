#include "s21_sprintf.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

int to_number(const char **format);
int to_char_int(long int num, char *buf);
int to_char_unsigned(unsigned long int num, char *buf);
void set_format_spec(const char **format, va_list *arguments,

                     FormatSpecifier *temp_spec);
void get_spec(const char **format, FormatSpecifier *get_spec);
void print_to_str(char **str, FormatSpecifier *full_spec, va_list *arguments);
void print_to_str_decimal(FormatSpecifier *full_spec, char **str,
                          va_list *arguments, char *buf);
void print_to_str_unsigned(FormatSpecifier *full_spec, char **str,
                           va_list *arguments, char *buf);
void print_to_str_symbol(FormatSpecifier *full_spec, char **str,
                         va_list *arguments, char *buf);
void print_to_str_str(FormatSpecifier *full_spec, char **str,
                      va_list *arguments, char *buf);
void print_to_str_percent(FormatSpecifier *full_spec, char **str, char *buf);
void print_to_str_double(FormatSpecifier *full_spec, char **str,
                         va_list *arguments, char *buf);

void save_buf_no_reverse_to_str(char **str, char *buf);
void reverse(char *str);
void save_buf_to_str(char **str, char *buf);
void reverse_string(char *buf);

int s21_sprintf(char *str, const char *format, ...) {
  va_list arguments_to_format;
  va_start(arguments_to_format, format);
  char *str_begin = str;
  while (*format != '\0') {
    if (*format == '%') {
      FormatSpecifier format_spec = {0};
      set_format_spec(&format, &arguments_to_format, &format_spec);
      print_to_str(&str, &format_spec, &arguments_to_format);
    } else {
      *str = *format;
      format++;
      str++;
    }
  }
  *str = '\0';
  va_end(arguments_to_format);
  s21_size_t quantity = str - str_begin;
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
}

void print_to_str(char **str, FormatSpecifier *full_spec,
                  va_list *arguments) {  // X O G E P - пока не хватает
  char buf[7000];
  s21_memset(buf, 0, sizeof(buf));
  if (full_spec->sprintf_type == 'd' || full_spec->sprintf_type == 'i') {
    print_to_str_decimal(full_spec, str, arguments, buf);
  } else if (full_spec->sprintf_type == 'u') {
    print_to_str_unsigned(full_spec, str, arguments,
                          buf);  // Только спецификатор u
    // } else if (full_spec->sprintf_type == 'x' || full_spec->sprintf_type ==
    // 'X') { print_to_hex(full_spec, str, arguments, buf);
    // } else if (full_spec->sprintf_type == 'o') {
    // print_to_oct(full_spec, str, arguments, buf);
  } else if (full_spec->sprintf_type == 'c') {
    print_to_str_symbol(full_spec, str, arguments, buf);
  } else if (full_spec->sprintf_type == 's') {
    print_to_str_str(full_spec, str, arguments, buf);
    // } else if (full_spec->sprintf_type == 'p') {
    // print_to_str_unsigned(arguments, str, arguments, buf);
  } else if (full_spec->sprintf_type == 'n') {
    // int *n = (int *)va_arg(*arguments, int *);
    // *n = (int)(*str - str_begin);
  } else if (full_spec->sprintf_type == '%') {
    print_to_str_percent(full_spec, str, buf);
  } else if (full_spec->sprintf_type == 'f') {
    print_to_str_double(full_spec, str, arguments, buf);
  }
  // } else if (full_spec->sprintf_type == 'e' || full_spec->sprintf_type ==
  // 'E') { print_to_str_e(full_spec, str, arguments, buf);
  // } else if (full_spec->sprintf_type == 'g' || full_spec->sprintf_type ==
  // 'G') { print_to_str_g(full_spec, str, arguments, buf);
  // }
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
  long int len = (long int)s21_strlen(buf);
  // Обрабатываем точность
  if (full_spec->accuracy) {
    long int add_accurcy = full_spec->accuracy - len;
    while (add_accurcy-- > 0) {
      buf[len++] = '0';
    }
  }
  len = (long int)s21_strlen(buf);
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
    len = (long int)s21_strlen(buf);
  }
  if (full_spec->plus && !flag_minus) {
    buf[len] = '+';
    len++;
  }
  if (full_spec->space && !flag_minus) {
    buf[len] = ' ';
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

int to_char_double(FormatSpecifier *full_spec, long double num, char *buf) {
  int quantity_of_sym = 0;
  long double double_temp_acc = num;
  long double mul = 1.0;
  if (full_spec->accuracy == 0 && !full_spec->dot) {
    full_spec->accuracy = 6;
  }
  if (full_spec->dot) {
    for (int i = 0; i <= full_spec->accuracy; i++) {
      double_temp_acc = roundl(num * mul) / mul;
      mul = mul * 10.0;
    }
  }
  long int temp_num =
      (long int)double_temp_acc;  // Отдельно сохраняем целую часть
  char sym = '0';
  if (double_temp_acc < 0) {
    temp_num = temp_num * (-1);
  }
  // Преобразуем целую часть
  if (temp_num == 0) {
    buf[quantity_of_sym++] = '0';
  } else {
    while (temp_num > 0.0) {
      sym = temp_num % 10 + '0';
      temp_num = temp_num / 10;
      buf[quantity_of_sym++] = sym;
    }
  }
  reverse_string(buf);
  // Добавляем десятичную точку
  if (full_spec->accuracy != 0 ||
      (full_spec->accuracy == 0 && !full_spec->dot)) {
    buf[quantity_of_sym++] = '.';
  }
  float fractional_part = double_temp_acc - (long int)double_temp_acc;
  if (fractional_part < 0) {
    fractional_part = fractional_part * (-1);
  }
  for (int i = 0; i < full_spec->accuracy; i++) {
    fractional_part *= 10;
    char temp = fractional_part;
    sym = temp + 48;
    buf[quantity_of_sym++] = sym;
    fractional_part -= (long int)fractional_part;
  }
  // Возвращаем количество символов
  return quantity_of_sym;
}

void save_buf_to_str(char **str, char *buf) {
  long int len = (long int)s21_strlen(buf);
  for (int i = len - 1; i >= 0; i--) {
    *(*str)++ = buf[i];
  }
  s21_memset(buf, 0, sizeof(buf));
}

void print_to_str_unsigned(FormatSpecifier *full_spec, char **str,
                           va_list *arguments, char *buf) {
  long int number = 0;
  // int quantity = 0;
  // int flag_negative = false;
  if (full_spec->lenghtmode == 'l')
    number = (long int)va_arg(*arguments, long int);
  else if (full_spec->lenghtmode == 'h')
    number = (unsigned short int)va_arg(*arguments, unsigned int);
  else
    number = (int)va_arg(*arguments, int);
  if (number < 0) {
    number = (unsigned int)number;
  }
  to_char_unsigned(number, buf);
  if (full_spec->accuracy) {
    long int len = (long int)s21_strlen(buf);
    long int add_accurcy = full_spec->accuracy - len;
    while (add_accurcy-- > 0) {
      buf[len++] = '0';
    }
  }
  if (full_spec->width) {
    long int len = (long int)s21_strlen(buf);
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
  int len = 0;
  buf[0] = sym;
  if (full_spec->width && !full_spec->minus) {
    add_width = full_spec->width;
    for (int i = 1; i < add_width; i++) {
      if (full_spec->zero) {
        buf[i] = '0';
      } else {
        buf[i] = ' ';
      }
    }
  }
  len = (int)s21_strlen(buf);
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
  len = (long int)s21_strlen(buf);
  buf[len] = '\0';
  save_buf_to_str(str, buf);
}

void print_to_str_str(FormatSpecifier *full_spec, char **str,
                      va_list *arguments, char *buf) {
  char *str_arg = (char *)va_arg(*arguments, char *);
  long int add_width = 0;
  long int add_accuracy = 0;
  long int len = 0;
  len = (long int)s21_strlen(str_arg);

  if (full_spec->accuracy >= len ||
      !full_spec->dot) {  // Выставляем значение точности
    add_accuracy = len;
  } else if (full_spec->accuracy < len && full_spec->accuracy != 0) {
    add_accuracy = full_spec->accuracy;
  }
  if (add_accuracy != 0) {  // Обрабатываем точность
    int j = add_accuracy - 1;
    for (int i = 0; i < add_accuracy; i++) {
      buf[i] = str_arg[j--];
    }
  }
  len = (long int)s21_strlen(buf);
  add_width = full_spec->width - len;
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
  save_buf_to_str(str, buf);
}

void print_to_str_percent(FormatSpecifier *full_spec, char **str, char *buf) {
  long int add_width = 0;
  int len = 0;
  buf[0] = '%';
  if (full_spec->width && !full_spec->minus) {
    add_width = full_spec->width;
    for (int i = 1; i < add_width; i++) {
      if (full_spec->zero) {
        buf[i] = '0';
      } else {
        buf[i] = ' ';
      }
    }
  }
  len = (int)s21_strlen(buf);
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
  save_buf_to_str(str, buf);
}

void print_to_str_double(FormatSpecifier *full_spec, char **str,
                         va_list *arguments, char *buf) {
  long double number = 0;
  // int quantity = 0;
  int flag_minus = 0;
  long int add_width = 0;
  if (full_spec->lenghtmode == 'l') {
    number = (double)va_arg(*arguments, double);
  } else if (full_spec->lenghtmode == 'h') {
    number = (float)va_arg(*arguments, double);
  } else {
    number = (double)va_arg(*arguments, double);
  }

  if (number < 0) {
    // number = -number;
    flag_minus = 1;
  }
  to_char_double(full_spec, number, buf);
  reverse_string(buf);
  int len = (int)s21_strlen(buf);
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
    len = (long int)s21_strlen(buf);
  }
  if (full_spec->plus && !flag_minus) {
    buf[len] = '+';
    len++;
  }
  if (full_spec->space && !flag_minus) {
    buf[len] = ' ';
    len++;
  }
  if (flag_minus) {
    buf[len] = '-';
    len++;
  }
  while (add_width-- > 0 && !full_spec->zero && !full_spec->minus) {
    buf[len++] = ' ';
  }
  // buf[len] = '\0';
  save_buf_to_str(str, buf);
}

void reverse_string(char *buf) {
  int length = s21_strlen(buf);
  int start = 0;
  int end = length - 1;

  while (start < end) {
    char temp = buf[start];
    buf[start] = buf[end];
    buf[end] = temp;

    start++;
    end--;
  }
}