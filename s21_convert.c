#include "s21_convert.h"
#include <stdio.h>
#include <stdlib.h>
#include "math.h"
float s21_strtof(const char *str,char** pos) {
    int negativ_num = 1;
    float res = 0.0;
    int a = 0;
    int point_found = 0;
    int e_found = 0;
    int e_sign = 1;
    int e_value = 0;


    int i =0;
    for (; str[i] != ' '; i++) {

        if (i == 0 && str[i] == '-') {
            negativ_num = -1;
            continue;
        }

        if (str[i] == '.' && !e_found) {
            point_found = 1;
            continue;
        }

        if ((str[i] == 'e' || str[i] == 'E') && !e_found) {
            e_found = 1;
            if (str[i + 1] == '-') {
                e_sign = -1;
                i++;
            } else if (str[i + 1] == '+') {
                i++;
            }
            continue;
        }

        if (e_found) {
            if (str[i] >= '0' && str[i] <= '9') {
                e_value = e_value * 10 + (str[i] - '0');
            }
        } else {
            if (str[i] >= '0' && str[i] <= '9') {
                res = res * 10.0 + (str[i] - '0');
                if (point_found) {
                    a++;
                }
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

    res *= negativ_num;
    return res;
}



