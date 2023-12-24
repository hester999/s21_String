#include "s21_string.h"
#include <stdio.h>
#include "s21_string.h"
#include "s21_sscanf.h"
#include "limits.h"
#include "float.h"

int main() {


    float a = 0;
    float a1 = 0;
    float b = 0;
    float c = 0;

//   s21_sscanf("10 12 ","%d %d",&a,&b);
//   printf("%d %d",a,b);

//    s21_sscanf("123.4567 89.01", "%5f %f",&a,&a1);
//    sscanf("123.4567 89.01", "%5f %f",&b,&c);
//    printf("%f %f\n%f %f",a,a1,b,c);

    sscanf("123.4567 89.01", "%5f %f",&b,&c);
    printf("its b-%f its c-%f",b,c);
    return 0;

}

