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
    
    // void *a,*b;
    // void *a1,*b1;
    // s21_sscanf("-0xFF 0xAAA", "%3p %p", &a,&a1);
    // sscanf("-0xFF 0xAAA", "%3p %p", &b,&b1);
    // printf("%p %p\n%p %p\n",a,a1,b,b1);


    unsigned long long a = 0, b = 0;

    s21_sscanf("18446744073709551615", "%2llu", &a);
    sscanf("18446744073709551615", "%2llu", &b);

    printf("%llu\n%llu", a,b);
//    unsigned int a,b;
//    s21_sscanf("-123","%d",&a);
//    sscanf("-123","%d",&b);
//    printf("%u\n%u",a,b);
    //18446744073709551615
    return 0;
}


