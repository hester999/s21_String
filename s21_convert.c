#include "s21_convert.h"
#include "s21_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <math.h>

#include <math.h>

long double s21_strtof(const char *str, char **pos) {
    long double result = 0.0;
    long double fraction = 1.0;
    int decimal_point = 0;
    int exp_part = 0;
    int exp_sign = 1;
    int negative = 0;

    // Пропуск пробелов
    while (*str == ' ') {
        str++;
    }

    // Проверка на отрицательный знак
    if (*str == '-') {
        negative = 1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    // Обработка специальных строк (inf, infinity, nan)
    if ((str[0] == 'i' || str[0] == 'I') &&
        (str[1] == 'n' || str[1] == 'N') &&
        (str[2] == 'f' || str[2] == 'F')) {
        result = INFINITY;
        str += 3;

        // Проверка на "infinity"
        if ((str[0] == 'i' || str[0] == 'I') &&
            (str[1] == 'n' || str[1] == 'N') &&
            (str[2] == 'i' || str[2] == 'I') &&
            (str[3] == 't' || str[3] == 'T') &&
            (str[4] == 'y' || str[4] == 'Y')) {
            str += 5;
        }
    } else if ((str[0] == 'n' || str[0] == 'N') &&
               (str[1] == 'a' || str[1] == 'A') &&
               (str[2] == 'n' || str[2] == 'N')) {
        result = NAN;
        str += 3;
    } else {
        // Обработка знака
        if (negative) {
            negative = 0; // Сброс флага отрицательного знака
            str--;
        }

        // Чтение числа до точки или экспоненциальной части
        for (; *str; str++) {
            if (*str >= '0' && *str <= '9') {
                result = result * 10.0 + (*str - '0');
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
        }

        // Чтение экспоненциальной части
        if (exp_part) {
            int exp_value = 0;
            for (; *str; str++) {
                if (*str >= '0' && *str <= '9') {
                    exp_value = exp_value * 10 + (*str - '0');
                } else {
                    break;
                }
            }
            result *= powl(10, exp_sign * exp_value);
        }
        if (negative) result = -result;
        result = result / fraction;
    }


    *pos = (char *)str;
    return result;
}


long long int s21_atoi(const char *str, char **pos) {
    s21_size_t counter = 0;
    int flag = 1;
    s21_size_t i = 0;

    // Обработка опционального знака
    int sign = 1;
    if (str[i] == '-') {
        sign = -1;
        i++;
    }


    while ((flag) && (i < s21_strlen(str))) {
        if (!(str[i] >= '0' && str[i] <= '9')) {
            flag = 0;
        }
        if (flag) {
            counter++;
        }
        i++;

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


int s21_hex_convert(const char *str, char **pos) {
    int res = 0;
    int num = 0;
    int i = 0;
    int negative_num =1;

    // Пропуск начальных пробелов и знаков
    while (str[i] == ' ') {
        i++;

    }
    if (str[i] == '-') {
        negative_num = -1;
        i++;

    } else if (str[i] == '+') {
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
    res*=negative_num;
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


int s21_convert_str_to_int_auto_base(const char* str, char **pos){
    int result = 0;
    if (str[0] == '0') {
        if (str[1] == 'x' || str[1] == 'X') {
            // Число в шестнадцатеричной системе
            result = s21_hex_convert(str, pos);
        } else {
            // Число в восьмеричной системе
            result = s21_octal_convert(str, pos);
        }
    } else {
        // Число в десятичной системе
        result = s21_atoi(str, pos);
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
