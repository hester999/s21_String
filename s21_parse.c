#include "s21_parse.h"

#include "s21_string.h"
#include "stdlib.h"

int parse(const char *format, FormatSpecifier **specs, int *len) {
  int numSpecs = 0;
  while (*format != '\0') {
    if (numSpecs >= *len) {
      *len *= 2;
      FormatSpecifier *tmp =
          (FormatSpecifier *)realloc(*specs, sizeof(FormatSpecifier) * *len);
      if (tmp == s21_NULL) {
        free(specs);
        exit(1);
      }
      *specs = tmp;
    }
    if (*format == '%') {
      format++;
      (*specs)[numSpecs].is_star_flag = 0;
      int incrementFormat = 0;
      (*specs)[numSpecs].width = -100;

      if (*format == '*') {
        (*specs)[numSpecs].is_star_flag = 1;
        format++;
      }


      if (*format >= '0' && *format <= '9') {
        while (*format >= '0' && *format <= '9') {
          (*specs)[numSpecs].width = 0;
          (*specs)[numSpecs].width =
              (*specs)[numSpecs].width * 10 + (*format - '0');
          format++;
        }
      }
      if (s21_strchr("lLh", *format) != s21_NULL) {
        (*specs)[numSpecs].lenghtmode = 0;
        if (*format == 'h') {
          (*specs)[numSpecs].lenghtmode = 1;
        }

        if (*format == 'l') {
          if (*(format + 1) == 'l') {  
            (*specs)[numSpecs].lenghtmode = 3;
            incrementFormat = 1;
            format++;
          } else {
            (*specs)[numSpecs].lenghtmode = 2;
          }
        }
        if (*format == 'L') {
          (*specs)[numSpecs].lenghtmode = 4;
        }

        if (incrementFormat == 0) {
          format++;
        }
      }
    }
//  }else if(*format!=' ' && *format!='%' && s21_strchr("lLh0123456789",*format)!=s21_NULL){
//        break;
//    }

    switch (*format) {
      case 'c':
        (*specs)[numSpecs++].type = SPEC_CHAR;
        break;

      case 'd':
        (*specs)[numSpecs++].type = SPEC_INT;
        break;

      case 'i':
        (*specs)[numSpecs++].type = SPEC_SIGNED_INT;
        break;

      case 'e':
        (*specs)[numSpecs++].type = SPEC_EXP;
        break;

      case 'E':
        (*specs)[numSpecs++].type = SPEC_EXP_WITH_E;
        break;

      case 'f':
        (*specs)[numSpecs++].type = SPEC_FLOAT;
        break;

      case 'g':
        (*specs)[numSpecs++].type = SPEC_SORT_DEC;
        break;

      case 'G':
        (*specs)[numSpecs++].type = SPEC_SORT_DEC;
        break;

      case 'o':
        (*specs)[numSpecs++].type = SPEC_UNSIGNED_8X8_INT;
        break;

      case 's':
        (*specs)[numSpecs++].type = SPEC_STRING;
        break;

      case 'u':
        (*specs)[numSpecs++].type = SPEC_UNSIGNED_INT;
        break;

      case 'x':
        (*specs)[numSpecs++].type = SPEC_UNSIGNED_16X16_INT;
        break;

      case 'X':
        (*specs)[numSpecs++].type = SPEC_UNSIGNED_16X16_INT_UPPER;
        break;

      case 'p':
        (*specs)[numSpecs++].type = SPEC_POINTER;
        break;

      case 'n':
        (*specs)[numSpecs++].type = SPEC_COUNT_SIMBOL;
        break;

        case '%':
            (*specs)[numSpecs++].type = SPEC_PERCENT;
            break;
    }

    format++;
  }
  return numSpecs;
}