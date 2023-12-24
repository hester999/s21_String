#include "s21_string.h"
#include <stdio.h>
#include "s21_string.h"
#include "s21_sscanf.h"
#include "limits.h"
#include "float.h"

int main() {


//    float a = 0;
//    float a1 = 0;
//    float b = 0;
//    float c = 0;
//    int q,w,q1,w1 =0;
//
//    s21_sscanf("100 12","%1*d %d ",&q,&w);
//    sscanf("100 12","%*1d %d",&q1,&w1);
//    printf("%d %d\n%d %d\n",q,w,q1,w1);
//
//
//    s21_sscanf("123.4567 89.01", "%3f %f",&a,&a1);
//    sscanf("123.4567 89.01", "%3f %f",&b,&c);
//    printf("%f %f\n%f %f",a,a1,b,c);


    int a = 0;
    int b =0;
    int a1=0,b1=0,c1 =0;

    s21_sscanf("FA  AF","%1x %x",&a,&b);

    sscanf("FA  AF","%1x %x",&a1,&b1);
    printf("%d %d\n%d %d %d",a,b,a1,b1,c1);

    return 0;

}

