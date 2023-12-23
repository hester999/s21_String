#include <string.h>
#include "s21_string.h"
#include <stdio.h>
#include <stdlib.h>
#include "s21_sscanf.h"



int main() {
    int aaa;

    s21_sscanf("-10", "%d", &aaa);

    printf("%d", aaa);

    return 0;
}