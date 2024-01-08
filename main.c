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


    int q =s21_sscanf("0x1234567890", "%x", &a);
    int q1 = sscanf("0x1234567890", "%X", &b);
    printf("%d %d\n",q,q1);
    printf("%d %d",a,b);

    return 0;
}


