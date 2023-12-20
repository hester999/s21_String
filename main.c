#include "s21_string.h"
#include <stdio.h>
#include "s21_string.h"
#include "s21_sscanf.h"
#include "limits.h"
#include "float.h"
int main() {


    double a,b,c;

    s21_sscanf("12345e6","%lg",&a);
    s21_sscanf("123.456","%lf",&b);
    s21_sscanf("3.14e-2","%le",&c);
    printf("%lf %lf %lf",a,b,c);




    return 0;

}

