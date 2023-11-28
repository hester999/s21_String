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

    printf("%d\n", atoi("123"));
    printf("%d\n", atoi("123.21"));
    printf("%d\n", atoi("12s3.21"));
    printf("%d\n", atoi("asfwg3r12s3.21"));
    printf("---------------------------------\n");
    printf("%d\n", s21_atoi("123"));
    printf("%d\n", s21_atoi("123.21"));
    printf("%d\n", s21_atoi("12s3.21"));
    printf("%d\n", s21_atoi("asfwg3r12s3.21"));
    return 0;
}



