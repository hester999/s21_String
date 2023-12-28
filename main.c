#include <string.h>
#include "s21_string.h"
#include <stdio.h>
#include <stdlib.h>
#include "s21_sscanf.h"



int main() {
    int aaa = 0;

    s21_sscanf("abd", "%d", &aaa);

    printf("%d", aaa);

    return 0;
}