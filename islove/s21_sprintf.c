#include "s21_sprintf.h"
#include "s21_string.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
int to_number(const char **format);
void set_format_spec(const char **format, va_list *arguments,
                     FormatSpecifier *temp_spec);
void get_spec(const char **format,FormatSpecifier *get_spec);
void  print_to_str(char **str,FormatSpecifier *full_spec,va_list *arguments,char *str_begin);
void print_to_str_decimal(FormatSpecifier *full_spec,char **str,va_list *arguments,char *buf);
int main() {
  char str[1000];
  s21_sprintf(str, "%.4d",4);
  printf("main str:%s",str);
    printf("\n%.4d",4);
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
    get_spec->sprintf_type= **format;
    (*format)++;
  }
}

void print_to_str(char **str,FormatSpecifier *full_spec,va_list *arguments,char *str_begin){
char buf[7000];
if (full_spec->sprintf_type == 'd' || full_spec->sprintf_type == 'i') {
    print_to_str_decimal(full_spec, str,arguments, buf);
  } else if (full_spec->sprintf_type == 'u'||  full_spec->sprintf_type == 'o' ||
             full_spec->sprintf_type == 'x' || full_spec->sprintf_type == 'X') {
    //print_to_str_unsigned(full_spec, str,arguments, buf);
  } else if (full_spec->sprintf_type == 'c') {
    //print_to_str_symbol(full_spec, str, arguments);
  } else if (full_spec->sprintf_type == 's') {
    //print_to_str_str(full_spec, str, arguments);
  } else if (full_spec->sprintf_type == 'p') {
    //print_to_str_unsigned(arguments, str, arguments, buf);
  } else if (full_spec->sprintf_type == 'n') {
    // int *n = (int *)va_arg(*arguments, int *);
    // *n = (int)(*str - str_begin);
  } else if (full_spec->sprintf_type == '%') {
    //print_to_str_percent(full_spec, str, buf);
  } else if (full_spec->sprintf_type == 'f' || full_spec->sprintf_type == 'F') {
    //print_to_str_double(full_spec, str, arguments, buf);
  } else if (full_spec->sprintf_type == 'e' || full_spec->sprintf_type == 'E') {
    //print_to_str_e(full_spec, str, arguments, buf);
  } else if (full_spec->sprintf_type == 'g' || full_spec->sprintf_type == 'G') {
    //print_to_str_g(full_spec, str, arguments, buf);
  }
}

void print_to_str_decimal(FormatSpecifier *full_spec,char **str,va_list *arguments,char *buf){
 long int number = 0;
 char *buf_start = buf;
if(full_spec->lenghtmode == 'l'){
number = (long int)va_arg(*arguments,long int);
}
else if(full_spec->lenghtmode='h'){
//number = (short int)va_arg(*arguments,short int);
}{
number = (int)va_arg(*arguments,int);
}
//  set_accuracy();
//  set_with();
//buf[0]=number;
if(full_spec->accuracy){
long int len = s21_strlen(buf);
int i =0;
long int add_accurcy = len-full_spec->accuracy;
//printf("%d",add_accurcy);
while(add_accurcy-->0){
  buf[i]=0;
  i=i+1;
}
printf("%d",i);
//printf("%d",len);
for(int i = 0; i<=*buf_start-*buf;i++){
  printf("%d",*buf);
}
//*str = buf;
}
}