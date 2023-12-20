#include "s21_convert.h"
#include "s21_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include <math.h>

long double s21_strtof(const char *str,char **pos,int *count_char) {
    long double result = 0.0;
    long double fraction = 1.0;
    int decimal_point = 0;
    int exp_part = 0;
    int exp_sign = 1;
    int negative = 0;

    // Пропуск пробелов
    while (*str == 32) {
        str++;
        (*count_char)++;
    }

    // Обработка знака
    if (*str == '-') {
        negative = 1;
        str++;
        (*count_char)++;
    } else if (*str == '+') {
        str++;
        (*count_char)++;
    }

    // Чтение числа до точки или экспоненциальной части
    for (; *str; str++) {
        if (*str >= 48 && *str <= 57) {
            result = result * 10.0 + (*str - 48);
            if (decimal_point) fraction *= 10.0;
        } else if (*str == '.' && !exp_part) {
            decimal_point = 1;
        } else if ((*str == 'e' || *str == 'E') && !exp_part) {
            exp_part = 1;
            str++;
            if (*str == '-') {
                exp_sign = -1;
                str++;
            } else if (*str == '+') {
                str++;
            }
            break;
        } else {
            break;
        }
        (*count_char)++;
    }

    // Чтение экспоненциальной части
    if (exp_part) {
        int exp_value = 0;
        for (; *str; str++) {
            if (*str >= 48 && *str <= 57) {
                exp_value = exp_value * 10 + (*str - 48);
            } else {
                break;
            }
            (*count_char)++;
        }
        result *= powl(10, exp_sign * exp_value);
    }
    *pos = (char*)(str+1);
    if (negative) result = -result;
    return result / fraction;
}







long long int s21_atoi(const char *str, char **pos,int *count_char) {
    s21_size_t counter = 0;
    int flag = 1;
    s21_size_t i = 0;

    // Обработка опционального знака
    int sign = 1;
    if (str[i] == '-') {
        sign = -1;
        i++;
        (*count_char)++;
    }else{
        (*count_char)++;
    }


    while ((flag) && (i < s21_strlen(str))) {
        if (!(str[i] >= '0' && str[i] <= '9')) {
            flag = 0;
        }
        if (flag) {
            counter++;
        }
        i++;
        (*count_char)++;
    }

    if (!counter) {
        return 0;
    }

    long long int number = 0;

    for (i = 0; i < counter; i++) {
        number = number * 10 + (str[i] - '0');
    }

    number *= sign;
    *pos = (char *)(str + counter);

    return number;
}


int s21_hex_convert(const char *str, char **pos,int *count_char) {
    int res = 0;
    int num = 0;
    int i = 0;
    int negative_num =1;

    // Пропуск начальных пробелов и знаков
    while (str[i] == ' ') {
        i++;
        (*count_char)++;
    }
    if (str[i] == '-') {
        negative_num = -1;
        i++;
        (*count_char)++;
    } else if (str[i] == '+') {
        i++;
        (*count_char)++;
    }
    if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X')) {
        i += 2;
        (*count_char)+=2;
    }
    for (; str[i] != '\0' && str[i] != ' '; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            num = str[i] - '0';
        } else if (str[i] >= 'a' && str[i] <= 'f') {
            num = 10 + (str[i] - 'a');
        } else if (str[i] >= 'A' && str[i] <= 'F') {
            num = 10 + (str[i] - 'A');
        } else {
            // Некорректный символ, прерываем обработку
            break;
        }
        (*count_char)++;
        res = res * 16 + num;
    }

    *pos = (char *)(str + i);
    res*=negative_num;
    return res;
}

int s21_octal_convert(const char *str, char **pos,int *count_char) {
    int res = 0;
    int num = 0;
    int i = 0;
    int negative_num = 1;
    // Пропуск начальных пробелов и знаков
    while (str[i] == ' ' || str[i] == '+' || str[i] == '-') {
        i++;
        (*count_char)++;
    }

    if (str[i] == '-') {
        negative_num = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    for (; str[i] != '\0' && str[i] != ' '; i++) {
        if (str[i] >= '0' && str[i] <= '7') {
            num = str[i] - '0';
        } else {
            // Некорректный символ, прерываем обработку
            break;
        }
        (*count_char)++;
        res = res * 8 + num;
    }

    *pos = (char *)(str + i);
    res *=negative_num;
    return res;
}


unsigned long  long  s21_get_pointer(const char*str,char **pos,int *count_char){

    unsigned long long res = 0;
        int num = 0;
        int i = 0;

        // Пропуск начальных пробелов и знаков
        while (str[i] == ' ' || str[i] == '+' || str[i] == '-') {
            i++;
            (*count_char)++;
        }
        if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X')) {
            i += 2;
            (*count_char)+=2;
        }
        for (; str[i] != '\0' && str[i] != ' '; i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                num = str[i] - '0';
            } else if (str[i] >= 'a' && str[i] <= 'f') {
                num = 10 + (str[i] - 'a');
            } else if (str[i] >= 'A' && str[i] <= 'F') {
                num = 10 + (str[i] - 'A');
            } else {
                // Некорректный символ, прерываем обработку
                break;
            }
            (*count_char)++;
            res = res * 16 + num;
        }

        *pos = (char *)(str + i);
        return res;
}


int s21_convert_str_to_int_auto_base(const char* str, char **pos,int *count_char){
    int result = 0;
    if (str[0] == '0') {
        if (str[1] == 'x' || str[1] == 'X') {
            // Число в шестнадцатеричной системе
            result = s21_hex_convert(str, pos,count_char);
        } else {
            // Число в восьмеричной системе
            result = s21_octal_convert(str, pos,count_char);
        }
    } else {
        // Число в десятичной системе
        result = s21_atoi(str, pos,count_char);
    }
    return result;
}

//unsigned long long get_unsigned_num(const char*str,char **pos){
//
//}