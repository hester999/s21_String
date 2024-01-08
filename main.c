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
    int a,b;
    int c,d;
    int n,n1;
    int q = s21_sscanf("10%24", "%d%%%d %n", &a, &b,&n);
    int q1 = sscanf("10%24 ", "%d%%%d %n", &c,&d,&n1);
    printf("%d\n%d\n",q,q1);
    printf("%d %d\n%d %d\n",a,b,c,d);
    printf("%d\n%d\n",n,n1);

//    int a = 0, b = 0, c = 0, d = 0;

//   int q= s21_sscanf("111%111", "%d%%%d", &a, &b);
//   int q1 =  sscanf("111%111", "%d%%%d", &c, &d);
//    printf("%d %d\n",q,q1);
//    printf("%d %d\n%d %d",a,b,c,d);
    return 0;
}


