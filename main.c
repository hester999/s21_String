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


// Main function to run the tests
int main() {

    // float a,b,c,a1,b1,c1;
    // s21_sscanf("32.23 3.14 34.56","%*3f %2f %f",&a,&b,&c);
    // sscanf("32.23 3.14 34.56","%*3f %f %2f",&a1,&b1,&c1);
    // printf("%f %f %f\n%f %f %f\n",a,b,c,a1,b1,c1);
    float a,b,a1,b1;
    s21_sscanf("nan 3.13","%2f %f",&a,&b);
    sscanf("nan 3.13","%3f %f",&a1,&b1);
    printf("%f %f\n%f %f\n",a,b,a1,b1);

    return 0;
}


