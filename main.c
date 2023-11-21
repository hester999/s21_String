#include <string.h>
#include "s21_string.h"
#include <stdio.h>
#include <stdlib.h>



int main() {
    char s1[] = "qwe-zxc"; // Используем массив символов, а не строковый литерал
    char *s2 = "-";

    char *res = s21_strtok(s1, s2);

    while (res != NULL) {
        printf("%s\n", res);
        res = s21_strtok(NULL, s2);
    }

    for (int i = 0; i < 140; i++) {
        printf("%s\n", s21_strerror(i));
    }

    return 0;
}



