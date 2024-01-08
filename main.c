#include "s21_string.h"
#include <stdio.h>
#include "s21_string.h"
#include "s21_sscanf.h"
#include "limits.h"
#include "float.h"
#include <math.h>

// доделать ширину и проверить кейсы со ззнаками, так же добавить в кейсы с is_star ширину и проверить работы * c width
// проверить все случаи с шириной 1
// подумать над nan и inf c шириной



int main() {
//    double a,b;
//    double a1,b1;
//    int o1= s21_sscanf("3.14 32.332","%*lf %lf",&a,&b);
//    int o2 = sscanf("3.14 32.332","%*lf %lf",&a1,&b1);
//    printf("%d\n%d\n",o1,o2);
    char str[100];
   int a=  s21_sscanf("qwe","%2c",str);
    printf("%d\n%s",a,str);

    return 0;
}


