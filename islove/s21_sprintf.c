#include "s21_sprintf.h"
#include "s21_string.h"
#include <stdio.h>
#include <stdbool.h>
void set_format_spec(const char **format);
int main() {
  char str[1000];
  s21_sprintf(str, "%-+0#d %+ d %0f %-c", 500, 300, 23.56, "h");
  //printf("%s",str);
  return 0;
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list arguments_to_format;

  va_start(arguments_to_format, format);
  char *str_begin = str;
  while (*format != '\0') {
    if (*format == '%') {
      set_format_spec(&format);
    }
    else{
      *str = *format;
      format++;
      str++;
    }
  }
  *str = '\0';
  return 0;
}

void set_format_spec(const char **format){
FormatSpecifier temp_spec = {0};
  (*format)++;
  while(s21_strchr("-+ #0",**format)){
     switch(**format){//Заменить потом на if
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
  printf("% d %d %d %d %d",temp_spec.minus,temp_spec.plus,temp_spec.space,temp_spec.hash,temp_spec.zero);
  }