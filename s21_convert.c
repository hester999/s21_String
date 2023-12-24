#include "s21_convert.h"
#include "s21_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "limits.h"


long double s21_strtof(const char *str, char **pos, int width) {
    long double result = 0.0;
    long double fraction = 1.0;
    int decimal_point = 0;
    int exp_part = 0;
    int exp_sign = 1;
    int negative = 0;
    int temp =0;

    while(str[temp] != ' ' && str[temp] !='\0'){
        temp++;
    }

    if(width<=0){
        width = temp;
    }


    int i=0;
    // Пропуск пробелов
    while (str[i] == ' ' && (width == -1 || i < (s21_size_t)width)) {
        i++;
    }

    // Проверка на отрицательный знак
    if ((str[i] == '-' || *str == '+') && (width == -1 || i < (s21_size_t)width)) {
        negative = (*str == '-');
        i++;

    }

    // Обработка специальных строк (inf, infinity, nan)
    if ((str[0] == 'i' || str[0] == 'I') &&
        (str[1] == 'n' || str[1] == 'N') &&
        (str[2] == 'f' || str[2] == 'F') &&
        (width == -1 || i + 3 <= (s21_size_t)width)) {
        result = INFINITY;
        i += 3;
        // Проверка на "infinity"
        if ((str[0] == 'i' || str[0] == 'I') &&
            (str[1] == 'n' || str[1] == 'N') &&
            (str[2] == 'i' || str[2] == 'I') &&
            (str[3] == 't' || str[3] == 'T') &&
            (str[4] == 'y' || str[4] == 'Y') &&
            (width == -1 || i + 5 <= (s21_size_t)width)) {
            i += 5;

        }
    } else if ((str[0] == 'n' || str[0] == 'N') &&
               (str[1] == 'a' || str[1] == 'A') &&
               (str[2] == 'n' || str[2] == 'N') &&
               (width == -1 || i + 3 <= (s21_size_t)width)) {
        result = NAN;
        i += 3;
    } else {
        // Чтение числа до точки или экспоненциальной части
        while (str[i] && (width == -1 || i < (s21_size_t)width)) {
            if (str[i] >= '0' && str[i] <= '9') {
                result = result * 10.0 + (str[i] - '0');
                if (decimal_point) fraction *= 10.0;
            } else if (str[i] == '.' && !exp_part) {
                decimal_point = 1;
            } else if ((str[i] == 'e' || str[i] == 'E') && !exp_part) {
                exp_part = 1;
                i++;

                if ((str[i] == '-' || str[i] == '+') && (width == -1 || i < (s21_size_t)width)) {
                    i++;
                }
                break;
            } else {
                break;
            }
            i++;

        }

        // Чтение экспоненциальной части
        if (exp_part) {
            int exp_value = 0;
            while (str[i] && (width == -1 || i < (s21_size_t)width)) {
                if (str[i] >= '0' && str[i] <= '9') {
                    exp_value = exp_value * 10 + (str[i] - '0');
                    i++;

                } else {
                    break;
                }
            }
            result *= powl(10, exp_sign * exp_value);
        }
        if (negative) result = -result;
        result = result / fraction;
    }

    *pos = (char *)str+i;


    return result;
}


long long int s21_atoi(const char *str, char **pos, int width) {
    long long int number = 0;
    int sign = 1;
    s21_size_t i = 0;
    int temp = 0;

    while (str[temp] != '\0' && (str[temp] >= '0' && str[temp] <= '9' || str[temp] == '+' || str[temp] == '-')) {
        temp++;
    }

    if (width <= 0 || width > temp) {
        width = temp;
    }

    if (str[i] == '-') {
        sign = -1;
        i++;
        if (width > 0) {
            width--;
        }
    }

    s21_size_t digits_count = 0;

    while (str[i] >= '0' && str[i] <= '9' && digits_count < width) {
        number = number * 10 + (str[i] - '0');
        if (number > (LLONG_MAX - number) / 10) {

            number = (sign == 1) ? LLONG_MAX : LLONG_MIN;
            break; //
        }
        i++;
        digits_count++;
    }


    *pos = (char *)(str + i);

    return number * sign;
}



int s21_hex_convert(const char *str, char **pos, int width) {
    unsigned int res = 0;
    int num = 0;
    int i = 0;
    int hex_digits_read = 0;
    int temp = 0;
    int negative = 1;
    while(str[temp]!= ' ' && str[temp] != '\0'){
        temp ++;
    }

    if(width  <= 0){
        width =temp;
    }

    // Пропуск начальных пробелов
    while (str[i] == ' ') {
        i++;
    }
    if (str[i] == '-') {
        negative = -1;
        i++;

    } else if (str[i] == '+') {
        i++;

    }
    // Проверка на префикс 0x или 0X
    int prefix = (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'));
    if (prefix) {
        i += 2; // Пропускаем "0x" или "0X"
    }

    // Если ширина позволяет прочитать только префикс (или не весь префикс), возвращаем 0
     if (prefix &&  width <= 2)  {
        if (pos != NULL) {
            *pos = (char *)(str + i);
        }
        return 0;
    }

    // Обработка шестнадцатеричных символов
    while (str[i] != '\0' && (width == -1 || hex_digits_read < width - (prefix ? 2 : 0))) {
        if (str[i] >= '0' && str[i] <= '9') {
            num = str[i] - '0';
        } else if (str[i] >= 'a' && str[i] <= 'f') {
            num = 10 + (str[i] - 'a');
        } else if (str[i] >= 'A' && str[i] <= 'F') {
            num = 10 + (str[i] - 'A');
        } else {
            break; // Некорректный символ, прерываем обработку
        }

        res = res * 16 + num;
        i++;
        hex_digits_read++;
    }

    if (pos != NULL) {
        *pos = (char *)(str + i);
    }

    res*=negative;
    return res;
}


int s21_octal_convert(const char *str, char **pos) {
    int res = 0;
    int num = 0;
    int i = 0;
    int negative_num = 1;
    // Пропуск начальных пробелов и знаков
    while (str[i] == ' ' || str[i] == '+' || str[i] == '-') {
        i++;

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

        res = res * 8 + num;
    }

    *pos = (char *)(str + i);
    res *=negative_num;
    return res;
}


unsigned long  long  s21_get_pointer(const char*str,char **pos){

    unsigned long long res = 0;
        int num = 0;
        int i = 0;

        // Пропуск начальных пробелов и знаков
        while (str[i] == ' ' || str[i] == '+' || str[i] == '-') {
            i++;

        }
        if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X')) {
            i += 2;

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

            res = res * 16 + num;
        }

        *pos = (char *)(str + i);
        return res;
}


int s21_convert_str_to_int_auto_base(const char* str, char **pos,int width){
    int result = 0;
    if (str[0] == '0') {
        if (str[1] == 'x' || str[1] == 'X') {
            // Число в шестнадцатеричной системе
            result = s21_hex_convert(str, pos,width);
        } else {
            // Число в восьмеричной системе
            result = s21_octal_convert(str, pos);
        }
    } else {
        // Число в десятичной системе
        result = s21_atoi(str, pos,width);
    }
    return result;
}

unsigned long long s21_get_unsigned_num(const char *str, char **pos) {
    unsigned long long result = 0;

    // Пропуск начальных пробелов
    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r') {
        str++;
    }

    // Чтение числа
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    // Обновление pos
    if (pos != NULL) {
        *pos = (char *)str;
    }

    return result;
}
