#include "s21_convert.h"
#include "s21_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float s21_strtof(const char *str, char** pos) {
    int negative_num = 1;
    float res = 0.0;
    int a = 0;
    int point_found = 0;
    int e_found = 0;
    int e_sign = 1;
    int e_value = 0;

    int i = 0;
    // Пропуск начальных пробелов
    while (str[i] == ' ') {
        i++;
    }

    // Обработка знака
    if (str[i] == '-') {
        negative_num = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }


    for (; str[i] != '\0'; i++) {
        if (str[i] == '.' && !e_found) {
            point_found = 1;
            continue;
        }

        if ((str[i] == 'e' || str[i] == 'E') && !e_found) {
            e_found = 1;
            i++;
            if (str[i] == '-') {
                e_sign = -1;
                i++;
            } else if (str[i] == '+') {
                i++;
            }
            continue;
        }

        if (e_found) {
            if (str[i] < '0' || str[i] > '9') break;
            e_value = e_value * 10 + (str[i] - '0');
        } else {
            if (str[i] < '0' || str[i] > '9') break;
            res = res * 10.0 + (str[i] - '0');
            if (point_found) {
                a++;
            }
        }
    }

    *pos = (char*)(str + i);

    while (a--) {
        res /= 10.0;
    }

    if (e_found) {
        res *= pow(10, e_sign * e_value);
    }

    res *= negative_num;
    return res;
}



int atoi_counter(const char *str) {
    int flag = 1;
    s21_size_t i= 0;
    int counter = 0;
    while ((flag) && (i < s21_strlen(str))) {
        if (!(str[i] >= '0' && str[i] <= '9')) {
            flag = 0;
        }
        if (flag) {
            counter++;
        }
        i++;
    }
    return counter;
}

int s21_atoi(const char *str,char** pos) {
    int counter = atoi_counter(str);
    if (!counter) {
        return 0;
    }
    char *s = calloc(counter + 1,sizeof (char*));
    s = s21_strncpy(s, str, counter);
    s[counter] = 0;
    int number = 0;
    int degree = 1;
    int c =0;
    for (int i = s21_strlen(s) - 1; i >= 0; i--) {
        number += ((s[i] - '0') * degree);
        degree *= 10;
        c++;
    }
    *pos = (char*)(str + c);
    free(s);
    return number;
}

int hex_convert(const char *str, char **pos) {
    int res = 0;
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

int octal_convert(const char *str, char **pos) {
    int res = 0;
    int num = 0;
    int i = 0;

    // Пропуск начальных пробелов и знаков
    while (str[i] == ' ' || str[i] == '+' || str[i] == '-') {
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
    return res;
}


unsigned long  long  get_pointer(const char*str,char **pos ){

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


int convert_str_to_int_auto_base(char* str, char **pos){
    int result = 0;
    if (str[0] == '0') {
        if (str[1] == 'x' || str[1] == 'X') {
            // Число в шестнадцатеричной системе
            result = hex_convert(str, pos);
        } else {
            // Число в восьмеричной системе
            result = octal_convert(str, pos);
        }
    } else {
        // Число в десятичной системе
        result = s21_atoi(str, pos);
    }
    return result;
}
