#include "s21_string.h"
#include <stdio.h>
#include "s21_string.h"
#include "s21_sscanf.h"
#include "limits.h"
#include "float.h"
#include <math.h>

// s21_test.c:761:F:SPEC d (SSCANF):sscanf_d_test7:0: Assertion 's21_sscanf("333abcde333", "%dabcde%d", &a, &b) == sscanf("333abcde333", "%dabcde%d", &c, &d)' failed: s21_sscanf("333abcde333", "%dabcde%d", &a, &b) == 1, sscanf("333abcde333", "%dabcde%d", &c, &d) == 2
//если добавить пробел между числом и строкой, то норм 

//хз как обработать невекрный ввод перед %, такой кейс работать не будет


//f,g,e вроде как 
//d вроде как
//x вроде как
//o тоже вроде да   
//p тоже вроде да
//u тоже вроде да 


int main() {
     
//      float a=0,b=0;
//      float a1=0,b1=0;
     int q,q1;
     int long long a=0,b=0,a1=0,b1=0;

    q = s21_sscanf("-9223372036854775808", "%lld", &a);
    q1 =sscanf("-9223372036854775808", "%lld", &a1);

     printf("%lld %lld\n%lld %lld\n",a,b,a1,b1);
     printf("%d %d\n",q,q1);

    if((a==a1)  && q==q1){
        printf("SUCCES\n");
    }else{
        printf("FAIL\n");
    }

    return 0;
}


