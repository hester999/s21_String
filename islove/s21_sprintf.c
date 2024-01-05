#include "s21_sprintf.h"
#include "s21_string.h"
#include "string.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int to_number(const char **format);
int to_char_int(int num, char *buf);
int to_char_unsigned(unsigned int num, char *buf);
void set_format_spec(const char **format, va_list *arguments,
                     FormatSpecifier *temp_spec);
void get_spec(const char **format, FormatSpecifier *get_spec);
void print_to_str(char **str, FormatSpecifier *full_spec, va_list *arguments,
                  char *str_begin);
void print_to_str_decimal(FormatSpecifier *full_spec, char **str,
                          va_list *arguments, char *buf);
void print_to_str_unsigned(FormatSpecifier *full_spec, char **str,
                           va_list *arguments, char *buf);
void print_to_str_e(FormatSpecifier *full_spec, char **str,
                          va_list *arguments, char *buf);
void save_buf_to_str(char **str, char *buf);
void double_to_str_exp(double number, int prec, char *str);
double s21_round(double number, int prec);

int main() {
  char str1[1000], str2[1000];
  double test_num = 0.123456;
  sprintf(str1, "%.4e", test_num);
  double_to_str_exp(test_num, 4, str2);
  printf("Orig: %s\n", str1);
  printf("Copy: %s\n", str2);
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
      print_to_str(&str, &format_spec, &arguments_to_format, str_begin);
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
  get_spec(format, temp_spec);
}

double s21_round(double number, int prec) {
    double factor = 1;
    for (int i = 0; i < prec; ++i) {
        factor *= 10;
    }
    double rounded = number * factor;
    double integral = (double)((int)rounded);
    double decimal = rounded - integral;
    if (decimal >= 0.5) {
        integral += 1.0;
    }
    return integral / factor;
}

void double_to_str_exp(double number, int prec, char *str) {
    if (number < 0) {
        *(str++) = '-';
        number = -number;
    }
    int power = 0;
    if (number >= 10) {
        while (number >= 10) {
            power++;
            number /= 10;
        }
    } else {
        while (number < 1) {
            power--;
            number *= 10;
        }
    }
    number = s21_round(number, prec);
    int number_int = (int)number;
    double number_frac = number - number_int;
    char temp_str[20];
    int index = 0;
    while (number_int > 0) {
        temp_str[index++] = (char)((number_int % 10) + '0');
        number_int /= 10;
    }
    if (index == 0) {
        temp_str[index++] = '0';
    }
    while (index > 0) {
        *(str++) = temp_str[--index];
    }
    *(str++) = '.';
    for (int i = 0; i < prec; ++i) {
        number_frac *= 10;
        int digit = (int)number_frac;
        *(str++) = (char)(digit + '0');
        number_frac -= digit;
    }
    *(str++) = 'e';
    if (power >= 0) {
        *(str++) = '+';
    } else {
        *(str++) = '-';
        power = -power;
    }
    if (power < 10) {
        *(str++) = '0';
    }
    int exp_index = 0;
    while (power > 0) {
        temp_str[exp_index++] = (char)((power % 10) + '0');
        power /= 10;
    }
    if (exp_index == 0) {
        temp_str[exp_index++] = '0';
    }
    while (exp_index > 0) {
        *(str++) = temp_str[--exp_index];
    }
    *str = 0;
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

void print_to_str(char **str, FormatSpecifier *full_spec, va_list *arguments,
                  char *str_begin) {
  char buf[7000];
  if (full_spec->sprintf_type == 'd' || full_spec->sprintf_type == 'i') {
    print_to_str_decimal(full_spec, str, arguments, buf);
  } else if (full_spec->sprintf_type == 'u' || full_spec->sprintf_type == 'o' ||
             full_spec->sprintf_type == 'x' || full_spec->sprintf_type == 'X') {
    print_to_str_unsigned(full_spec, str, arguments, buf);//Только спецификатор u 
  } else if (full_spec->sprintf_type == 'c') {
    // print_to_str_symbol(full_spec, str, arguments);
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
  int quantity = 0;
  int flag_minus = false;
  if (full_spec->lenghtmode == 'l')
    number = (long int)va_arg(*arguments, long int);
  else if (full_spec->lenghtmode =='h')
    number = (int)va_arg(*arguments, int);
  else
    number = (int)va_arg(*arguments, int);
  if (number < 0) {
    number = number * (-1);
  }
  quantity = to_char_int(number, buf);
  if (full_spec->space)
    buf[quantity] = ' ';
  if (full_spec->plus && !flag_minus)
    buf[quantity] = '+';
  if (flag_minus)
    buf[quantity] = '-';
  if (full_spec->accuracy) {
    long int len = (long int)strlen(buf);
    printf("len:%ld\n", len);
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

int to_char_int(int  num, char *buf) {
  int quantity_of_sym = 0;
  int temp_num = num;
  char sym = '0';
  if (temp_num == 0) {
    buf[quantity_of_sym] = '0';
    quantity_of_sym++;
  } else {
    while (temp_num > 0) {
      sym = temp_num % 10 + 48;
      // printf("sym:%c\n temp_num:%d\n",sym,temp_num);
      temp_num = temp_num / 10;
      buf[quantity_of_sym] = sym;
      quantity_of_sym++;
    }
  }
  //printf("buff:%s\n",buf);
  return quantity_of_sym;
}

int to_char_unsigned(unsigned int num, char *buf) {
  int quantity_of_sym = 0;
  // if (full_spec->lenghtmode == 'l')
  //   number = (long int)va_arg(*arguments, long int);
  // else if (full_spec->lenghtmode =='h')
  //   number = (int)va_arg(*arguments, int);
  unsigned int temp_num = num;
  char sym = '0';
  if (temp_num == 0) {
    buf[quantity_of_sym] = '0';
    quantity_of_sym++;
  } else {
    while (temp_num > 0) {
      sym = temp_num % 10 + 48;
      //printf("sym:%c\n temp_num:%d\n",sym,temp_num);
      temp_num = (temp_num / 10);
      buf[quantity_of_sym] = sym;
      quantity_of_sym++;
    }
  }
  //printf("buff:%s\n",buf);
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
  if (format_spec->sprintf_type == 'o')
    format_spec->number_system = 8;
}

void print_to_str_unsigned(FormatSpecifier *full_spec, char **str,
                           va_list *arguments, char *buf) { 
  long int number = 0;
  int quantity = 0;
  if (full_spec->lenghtmode == 'l')
    number = (long int)va_arg(*arguments, long int);
  else if (full_spec->lenghtmode =='h')
    number = (int)va_arg(*arguments, int);
  else
    number = (int)va_arg(*arguments, int);
  if (number < 0) {
    number = (unsigned int)number;
  }
  quantity = to_char_unsigned(number, buf);
  if (full_spec->space)
    buf[quantity] = ' ';
  if (full_spec->accuracy) {
    long int len = (long int)strlen(buf);
    printf("len:%ld\n", len);
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

// void print_to_str_e(FormatSpecifier *full_spec, char **str,
//                     va_list *arguments, char *buf) {
  
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