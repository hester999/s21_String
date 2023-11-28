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

    for (int i = 132; i < 135; i++) {
        printf("%s\n", s21_strerror(i));
    }

    char *s3 = "123Q";
    s3 = s21_insert(s3, "abobu$", 2);
    printf("%s\n", s3);
    free(s3);
    char *s4 = "bk1 2 3 hoee abbbbbbbbkkkk ";
    s4 = s21_trim(s4, " kb");
    printf("%s\n", s4);
    free(s4);
    return 0;
}



