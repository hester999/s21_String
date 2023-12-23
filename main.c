#include "s21_string.h"
#include <stdio.h>
#include "s21_string.h"
#include "s21_sscanf.h"
#include "limits.h"
#include "float.h"
int main() {

    char c[10];
    int a;
    sscanf("10","%100d",&a);
    printf("%d",a);
    return 0;

}

