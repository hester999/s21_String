#include "s21_string.h"
#include <stdio.h>
#include "s21_string.h"
#include "s21_sscanf.h"
#include "limits.h"
#include "float.h"
int main() {

    char c[10];
    int b,n,n1=0;
    float  a;
   // sscanf("10 12","%d %d %*n %n",&a,&b,&n,&n1);
    s21_sscanf("","%f",&a);
    printf("%f",a);
    return 0;

}

