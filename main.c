#include "s21_string.h"
#include <stdio.h>
#include "s21_string.h"
#include "s21_sscanf.h"
#include "limits.h"
#include "float.h"
int main() {



    unsigned long long a;
    int n =0;
    s21_sscanf("18446744073709551615", "%llu %n", &a,&n);

    printf("%d", n);




    return 0;

}

