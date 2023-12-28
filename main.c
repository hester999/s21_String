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

    s21_sscanf("-123 -23","%2d %d",&a,&b);

    sscanf("-123 -23","%2d %d",&a1,&b1);

    printf("%d %d\n%d %d\n",a,b,a1,b1);



    return 0;

}

