#include "s21_convert.h"
#include "s21_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "limits.h"


long double s21_strtof(const char *str, char **pos, int width,int *count_spec) {
    long double result = 0.0;
    long double fraction = 1.0;
    int decimal_point = 0;
    int exp_part = 0;
    int exp_sign = 1;
    int negative = 0;
    int temp = 0;
    int wrong_write = 0;
    int local_count = 0; 
    int empty_str = 0;

    if (str == s21_NULL || *str == '\0') {
        empty_str =1;
    }


    int i = 0;
    while (str[i] == ' ') {
        i++;
    }
    
    temp = i;
    // Определение длины числа в строке
    while (str[temp] != '\0' && str[temp] != ' ') {
        temp++;
    }

    if(str[i] =='\0'){
        empty_str =1;
    }

    if (width == -100 || width > temp) {
        width = temp;
    }else{
        width+=i;
    }
   


    if ((str[i] == '-' || str[i] == '+') && (width > 0)) {
        negative = (str[i] == '-');
        i++;
        width--;
    }

    // Обработка специальных значений (inf, infinity, nan)
    if ((str[i] == 'i' || str[i] == 'I') && (str[i + 1] == 'n' || str[i + 1] == 'N') && (str[i + 2] == 'f' || str[i + 2] == 'F') && (width > 0)) {
        result = INFINITY;
        i += 3;
        width -= 3;
        if ((str[i] == 'i' || str[i] == 'I') && (str[i + 1] == 'n' || str[i + 1] == 'N') && (str[i + 2] == 'i' || str[i + 2] == 'I') && (str[i + 3] == 't' || str[i + 3] == 'T') && (str[i + 4] == 'y' || str[i + 4] == 'Y') && (width > 0)) {
            i += 5;
            width -= 5;
        }
        if (negative) result = -result;
    } else if ((str[i] == 'n' || str[i] == 'N') && (str[i + 1] == 'a' || str[i + 1] == 'A') && (str[i + 2] == 'n' || str[i + 2] == 'N') && (width > 0)) {
        result = NAN;
        i += 3;
        width -= 3;
        if (negative) result = -result;
    } else {
        while (str[i] && (width == -1 || i < width)) {
            if (str[i] >= '0' && str[i] <= '9') {
                result = result * 10.0 + (str[i] - '0');
                if (decimal_point) fraction *= 10.0;
            } else if (str[i] == '.' && !exp_part) {
                decimal_point = 1;
            } else if ((str[i] == 'e' || str[i] == 'E') && !exp_part) {
                exp_part = 1;
                i++;
                if ((str[i] == '-' || str[i] == '+') && (width == -1 || i < width)) {
                    exp_sign = (str[i] == '-') ? -1 : 1;
                    i++;
                }
                break;
            } else {
                wrong_write =1;
                break;
            }
            i++;
        }
        if (exp_part) {
            int exp_value = 0;
            while (str[i] && (width == -1 || i < width)) {
                if (str[i] >= '0' && str[i] <= '9') {
                    exp_value = exp_value * 10 + (str[i] - '0');
                    i++;
                } else {
                    wrong_write = 1;
                    break;
                }
            }
            result *= powl(10, exp_sign * exp_value);
        }
        if (negative) result = -result;
        result = result / fraction;
    }

    if (wrong_write) {
        while (str[i] != '\0' && str[i] != ' ' && ((str[i-1] >= '0' && str[i-1]<='9') || str[i-1]=='.')) {
            if ((str[i] >= 'a' ) && (str[i] <= 'z')) {
                wrong_write = 0;
                break;
            }
            i++;
        }
    }

    if (pos != s21_NULL) {
        *pos = (char *)str + i;
    }


    if(!wrong_write){
        local_count +=1;
    }
  
    if (local_count > 0 && empty_str == 0) {
        *count_spec += local_count; 
    } 
    if(empty_str == 1){
        *count_spec = -1;
    }

    return result;
}


long long int s21_atoi(const char *str, char **pos, int width,int *count_spec) {
    
    long long int number = 0;
    int sign = 1;
    int i = 0;
    int temp = 0;
    int no_width = 0;
    int full_str = 0;
    int no_width_2 = width == 0;
    int wrong_write = 0;
    int local_count = 0; 
    int empty_str = 0;

  
    
    if (str == s21_NULL || *str == '\0') {
        empty_str =1;
    }

    // Пропуск пробельных символов
    while (str[i] == ' ') {
        i++;
        
    }
    

    if (str[i] == '\0') {
        empty_str = 1;
        
    }
    temp = i;
    // Определение длины числа в строке
    while (str[temp] != '\0' && str[temp] != ' ') {
        temp++;
    }

    if (width >= temp) {
        full_str = 1;
    }

    if (width == -100) {
        width = temp;
        no_width = 1;
    }

    // Обработка знака
    if (str[i] == '-') {
        
        sign = -1;
        i++;
        width--;
    }else if(str[i] == '+'){
       
        sign = 1;
        i++;
        width--;
    }

   

    if (no_width) {
        width = temp;
    }
    if (full_str) {
        width = temp;
    }

   
    
    for (; str[i] != '\0' && str[i] != ' ' && (width > 0 || no_width_2); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            number = number * 10 + (str[i] - '0');
            if (number > (LLONG_MAX - number) / 10) {
                number = (sign == 1) ? LLONG_MAX : LLONG_MIN;
                break; 
            }
        } else {
            wrong_write =1;
            break;
        }
        width--;
    }


    if (wrong_write) {
        while (str[i] != '\0' && str[i] != ' ' && (str[i-1] >= '0' && str[i-1]<='9')) {
            if ((str[i] >= 'a' ) && (str[i] <= 'z')) {
                wrong_write = 0;
                break;
            }
            i++;
        }
    }




    if(!wrong_write){
        local_count +=1;
    }
  
    if (local_count > 0 && empty_str == 0) {
        *count_spec += local_count; 
    } 
    if(empty_str == 1){
        *count_spec = -1;
    }
    *pos = (char *)(str + i);
  
    return number * sign;
}





int s21_hex_convert(const char *str, char **pos, int width, int *count_spec) {
    int res = 0;
    int num = 0;
    int i = 0;
    int negative_num = 1;
    int temp = 0;
    int wrong_write = 0;
    int local_count = 0;
    int effective_width = width;

    int empty_str = 0;

    if (str == s21_NULL || *str == '\0') {
        empty_str =1;
    }


    // Пропуск начальных пробелов
    while (str[i] == ' ') {
        i++;
    }

    if(str[i] =='\0'){
        empty_str = 1;
    }

    temp = i;
    while (str[temp] != ' ' && str[temp] != '\0') {
        temp++;
    }

    // Обновление effective_width
    if (width == -100 || width > temp - i) {
        effective_width = temp - i;
    } else {
        effective_width = width;
    }

    // Обработка знака
    if ((str[i] == '-' || str[i] == '+') && (effective_width > 0)) {
        negative_num = (str[i] == '-') ? -1 : 1;
        i++;
        effective_width--;
    }

    // Обработка префикса 0x или 0X
    if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X') && (effective_width > 0)) {
        i += 2;
        effective_width -= 2;
    }

    // Цикл преобразования числа
    for (; str[i] != '\0' && str[i] != ' ' && effective_width > 0; i++, effective_width--) {
        if (str[i] >= '0' && str[i] <= '9') {
            num = str[i] - '0';
        } else if (str[i] >= 'a' && str[i] <= 'f') {
            num = 10 + (str[i] - 'a');
        } else if (str[i] >= 'A' && str[i] <= 'F') {
            num = 10 + (str[i] - 'A');
        } else {
            wrong_write = 1;
            break;
        }
        res = res * 16 + num;
    }

    // Обновление результатов
    if (!wrong_write) {
        local_count++;
    }

    res *= negative_num;
    if (local_count > 0 && empty_str == 0) {
        *count_spec += local_count;
    }else if(empty_str == 1){
        *count_spec = -1;
    }
    *pos = (char *)(str + i);
    return res;
}









int s21_octal_convert(const char *str, char **pos,int width,int *count_spec) {
    int res = 0;
    int num = 0;
    int i = 0;
    int negative_num = 1;
    int temp=0;
    int wrong_write = 0;
    int local_count = 0;
    int empty_str =0;
    // Пропуск начальных пробелов и знаков

    if(str == s21_NULL || *str=='\0'){
        empty_str =1;
    }
    while (str[i] == ' ') {
        i++;

    }

    if(str[i]=='\0'){
        empty_str =1;
    }


    temp = i;
    for(int i=0; str[i]!=' ' && str[i] != '\0';i++){
        temp++;
    }

    if(width ==-100 || width > temp){
        width = temp;
    }

 

    if (str[i] == '-') {
        negative_num = -1;
        i++;
        width--;
    } else if (str[i] == '+') {
        i++;
        width--;
    }


    if(str[i] == '0'){
        i++;
        width--;
    }

    for (; str[i] != '\0' && str[i] != ' '&&(width >0); i++) {
        if (str[i] >= '0' && str[i] <= '7') {
            num = str[i] - '0';
        } else {
            wrong_write = 1;
            break;
        }

        res = res * 8 + num;
        width--;
    }

    *pos = (char *)(str + i);
    res *=negative_num;

    if(!wrong_write){
        local_count++;
    }

    if (local_count > 0 && empty_str == 0) {
        *count_spec += local_count;
    }else if(empty_str == 1){
        *count_spec = -1;
    }
    return res;
}










unsigned long long s21_get_pointer(const char *str, char **pos, int width,int *count_spec) {
    unsigned long long res = 0;
    int num = 0;
    int i = 0;
    int temp = 0;
    int no_width = 0;
    int full_str = 0;
    int no_width_2 = width == 0;
    int isNegative = 0;  // Флаг для отрицательного числа
    int wrong_write = 0;
    int local_count = 0;
    int empty_str = 0;
    
    
    if(str == s21_NULL || *str=='\0'){
        empty_str =1;
    }

    while (str[i] == ' ') {
        i++;
    }

    if(str[i]=='\0'){
        empty_str = 1;
    }

    // Проверка на отрицательный знак
    if (str[i] == '-') {
        isNegative = 1;
        i++;
        if (width != -100) width--; // Уменьшаем width, если он задан
    }

    temp = i;
    while (str[temp] != '\0' && str[temp] != ' ') {
        temp++;
    }

    if (width >= temp) {
        full_str = 1;
    }

    if (width == -100) {
        width = temp;
        no_width = 1;
    }

    if (no_width) {
        width = temp;
    }
    if (full_str) {
        width = temp;
    }

    if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X') && (i < width)) {
        i += 2;
        width -= 2;
    }
    for (; str[i] != '\0' && str[i] != ' ' && (width > 0 || no_width_2); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            num = str[i] - '0';
        } else if (str[i] >= 'a' && str[i] <= 'f') {
            num = 10 + (str[i] - 'a');
        } else if (str[i] >= 'A' && str[i] <= 'F') {
            num = 10 + (str[i] - 'A');
        } else {
            wrong_write =1;
            break; // Некорректный символ, прерываем обработку
        }
        width--;
        res = res * 16 + num;
    }

    // Преобразование в отрицательное значение, если необходимо
    if (isNegative) {
        res = ~(res - 1);
    }
    if(!wrong_write){
        local_count++;
    }
  
    if(local_count>0 && empty_str ==0){
        *count_spec+=1;
    }else if(empty_str ==1){
        *count_spec = -1;
    }


    *pos = (char *)(str + i);
    return res;
}






int s21_convert_str_to_int_auto_base(const char* str, char **pos,int width,int *count_spec){
    int result = 0;
    int i=0;
    while (str[i] == ' ' || str[i] == '+' || str[i] == '-') {
        i++;
    }

    if (str[i] == '0') {
        if (str[i+1] == 'x' || str[i+1] == 'X') {
            // Число в шестнадцатеричной системе
            result = s21_hex_convert(str, pos,width,count_spec);
        } else {
            // Число в восьмеричной системе
            result = s21_octal_convert(str, pos,width,count_spec);
        }
    } else {
        // Число в десятичной системе
        result = s21_atoi(str, pos,width,count_spec);
    }
    return result;
}












unsigned long long s21_get_unsigned_num(const char *str, char **pos, int width,int *count_spec) {
    unsigned long long result = 0;
    int temp = 0;
    int negative = 0;
    int local_count = 0;
    int wrong_write =0;
    int empty_str =0;

    if(str == s21_NULL || *str =='\0'){
        empty_str =1;
    }


    while (*str == ' ') {
        str++;
    }

    if(*str == '\0'){
        empty_str = 1;
    }

    if (*str == '-') {
        negative = 1;
        str++;
    }

   
    for (int i = 0; str[i] != ' ' && str[i] != '\0'; i++) {
        temp++;
    }

    if (width == -100 || width > temp) {
        width = temp;
    }

    int check = s21_support_to_ull(str); //если сразу максимальное число, то ширина не должна работать 

    if(check ==1){
        result = ULLONG_MAX;
        *pos = (char *)str+temp;
        return result;
    }

    while (*str >= '0' && *str <= '9' && (width > 0)) {
        // Проверка на переполнение перед умножением
        if (result > ULLONG_MAX / 10 || (result == ULLONG_MAX / 10 && (unsigned long long)(*str - '0') > ULLONG_MAX % 10)) {
            // Обработка переполнения
            result = ULLONG_MAX;
            break;
        }
    
        result = result * 10 + (*str - '0');
        str++;
        width--;

        if (*str < '0' || *str > '9') {
        wrong_write = 1;
    }
     
    }

    // В случае отрицательного числа, возвращаем ULLONG_MAX
    if (negative) {
        result = ULLONG_MAX;
    }

    if (pos != s21_NULL) {
        *pos = (char *)str;
    }
    
    if(!wrong_write){
        local_count+=1;
    }

    if(local_count>0 && empty_str ==0){
        *count_spec+=local_count;
    }else if(empty_str ==1){
        *count_spec = -1;
    }
    
    
    return result;
}




int s21_support_to_ull(const char *str) {
    unsigned long long result = 0;

    
    while (*str == ' ') {
        str++;
    }

    
    while (*str >= '0' && *str <= '9') {
       
        if (result > ULLONG_MAX / 10 || (result == ULLONG_MAX / 10 && (unsigned long long)(*str - '0') > ULLONG_MAX % 10)) {
            return 1; 
        }

        result = result * 10 + (*str - '0');
        str++;
    }

    return 0; 
}

