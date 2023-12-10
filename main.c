#include "s21_string.h"
#include <stdio.h>
#include "s21_string.h"
#include "s21_sscanf.h"
#include "limits.h"
#include "float.h"
int main() {


    int n = 0;
    int a =0 ;
    int a1 =0 ;


    s21_sscanf("123    32","%d%d%n",&a,&a1,&n);
    printf("%d",n);
    return 0;

}

