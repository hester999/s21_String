#include "s21_string.h"
#include <stdio.h>
#include "s21_string.h"
#include "s21_sscanf.h"




int main() {

//    int res =0;
//    int res1 =0;
//    int res2 =0;
//    int res3 = 0;
//    s21_sscanf("100 1"," %d %o", &res, &res3);
//    printf("%d %d\n",res,res3);

    int res1;
    int res2 =0;
    int res3 =0;
    s21_sscanf("0xA", "%i", &res1,&res2,&res3);//1569325055


    printf("%d\n",res1);
    printf("%d\n",res2);
    printf("%d\n",res3);

    return 0;
}

