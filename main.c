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
     int flag=0;
    for(int i =0; i<= 3;i++){
         flag = 1 << 1;
         ~flag;
    }
    printf("%d\n",flag);
    return 0;
}


