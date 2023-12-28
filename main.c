#include "s21_string.h"
#include <stdio.h>
#include "s21_string.h"
#include "s21_sscanf.h"
#include "limits.h"
#include "float.h"

int main() {


    int a = 0;
    int b = 0;
    int a1=0;
    int b1=0;

    s21_sscanf("0xFA AF","%2x %x",&a,&b);

    sscanf("0xFA AF","%2x %x",&a1,&b1);

    printf("%d %d\n%d %d",a,b,a1,b1);



    return 0;

}

