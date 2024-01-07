#include "s21_convert.h"
#include "s21_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "limits.h"


long double s21_strtof(const char *str, char **pos, int width) {

    long double result = 0.0;
    long double fraction = 1.0;
    int decimal_point = 0;
    int exp_part = 0;
    int exp_sign = 1;
    int negative = 0;
    int temp =0;


    while(str[temp] != ' ' && str[temp] !='\0'){
        temp++;
    }

    if(width ==-100 || width >temp){
        width = temp;
    }


    int i=0;
    // Пропуск пробелов
    while (str[i] == ' ') {
        i++;
    }

    // Проверка на отрицательный знак
    if ((str[i] == '-' || *str == '+') && (width > 0)) {
        negative = (*str == '-');
        i++;
        width--;
    }

    // Обработка специальных строк (inf, infinity, nan)
    if ((str[0] == 'i' || str[0] == 'I') && (str[1] == 'n' || str[1] == 'N') && (str[2] == 'f' || str[2] == 'F') && (width>0)) {
        result = INFINITY;
        i += 3;
        width-=3;
        // Проверка на "infinity"
        if ((str[0] == 'i' || str[0] == 'I') &&
            (str[1] == 'n' || str[1] == 'N') &&
            (str[2] == 'i' || str[2] == 'I') &&
            (str[3] == 't' || str[3] == 'T') &&
            (str[4] == 'y' || str[4] == 'Y') &&
            (width>0)) {
            i += 5;
            width-=5;
        }
    } else if ((str[0] == 'n' || str[0] == 'N') &&
               (str[1] == 'a' || str[1] == 'A') &&
               (str[2] == 'n' || str[2] == 'N') &&
               (width > 0)) {
        result = NAN;
        i += 3;
        width -=3;
    } else {
        // Чтение числа до точки или экспоненциальной части
        while (str[i] && (width == -1 || i < (s21_size_t)width)) {
            if (str[i] >= '0' && str[i] <= '9') {
                result = result * 10.0 + (str[i] - '0');
                if (decimal_point) fraction *= 10.0;
            } else if (str[i] == '.' && !exp_part) {
                decimal_point = 1;
            } else if ((str[i] == 'e' || str[i] == 'E') && !exp_part) {
                exp_part = 1;
                i++;

                if ((str[i] == '-' || str[i] == '+') && (width == -1 || i < (s21_size_t)width)) {
                    i++;
                }
                break;
            } else {
                break;
            }
            i++;

        }

        // Чтение экспоненциальной части
        if (exp_part) {
            int exp_value = 0;
            while (str[i] && (width > 0)) {
                if (str[i] >= '0' && str[i] <= '9') {
                    exp_value = exp_value * 10 + (str[i] - '0');
                    i++;

                } else {
                    break;
                }
            }
            result *= powl(10, exp_sign * exp_value);
        }
        if (negative) result = -result;
        result = result / fraction;
    }

    *pos = (char *)str+i;


    return result;
}


long long int s21_atoi(const char *str, char **pos, int width) {
    long long int number = 0;
    int sign = 1;
    int i = 0;
    int temp = 0;
    int no_width = 0;
    int full_str = 0;
    int no_width_2 = width == 0;

    // Пропуск пробельных символов
    while (str[i] == ' ') {
        i++;
    }

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
            
            break;
        }
        width--;
    }

    *pos = (char *)(str + i);

    return number * sign;
}





int s21_hex_convert(const char *str, char **pos,int* width) {


    int res = 0;
    int num = 0;
    int i = 0;
    int test =0;
    int negative_num =1;
    int temp =0;
    int no_width = 0;
    int full_str = 0;
    int no_width_2=*width==0;
  

    while(str[temp] !=' ' && str[temp]!= '\0'){
        temp++;
    }
    if(*width >= temp){
        full_str =1;
    }

    if(*width == -100){
        *width = temp;
        no_width =1;
    }


    // Пропуск начальных пробелов и знаков
    while (str[i] == ' ') {
        i++;

    }
    if (str[i] == '-') {
        negative_num = -1;
        i++;
        (*width)--;

    } else if (str[i] == '+') {
        i++;

    }

    if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X') && (i< *width )) {
        i += 2;
        *width-=2;

    }

    if(no_width ){
        *width = temp;
    }
    if(full_str){
        *width = temp;
    }
   

    for (; str[i] != '\0' && str[i] != ' ' && (*width>0 || no_width_2); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            num = str[i] - '0';
        } else if (str[i] >= 'a' && str[i] <= 'f') {
            num = 10 + (str[i] - 'a');
        } else if (str[i] >= 'A' && str[i] <= 'F') {
            num = 10 + (str[i] - 'A');
        } else {
            break;
        }
        (*width)--;
        res = res * 16 + num;
    }

   *pos = (char *)(str +i);
    res*=negative_num;
    return res;
}








int s21_octal_convert(const char *str, char **pos,int width) {
    int res = 0;
    int num = 0;
    int i = 0;
    int negative_num = 1;
    int temp=0;
    // Пропуск начальных пробелов и знаков
    while (str[i] == ' ') {
        i++;

    }

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
            // Некорректный символ, прерываем обработку
            break;
        }

        res = res * 8 + num;
        width--;
    }
    
    
    *pos = (char *)(str + i);
    res *=negative_num;
    return res;
}










unsigned long long s21_get_pointer(const char *str, char **pos, int width) {
    unsigned long long res = 0;
    int num = 0;
    int i = 0;
    int temp = 0;
    int no_width = 0;
    int full_str = 0;
    int no_width_2 = width == 0;
    int isNegative = 0;  // Флаг для отрицательного числа

    while (str[i] == ' ') {
        i++;
    }

    // Проверка на отрицательный знак
    if (str[i] == '-') {
        isNegative = 1;
        i++;
        if (width != -100) width--; // Уменьшаем width, если он задан
    }

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
            break; // Некорректный символ, прерываем обработку
        }
        width--;
        res = res * 16 + num;
    }

    // Преобразование в отрицательное значение, если необходимо
    if (isNegative) {
        res = ~(res - 1);
    }

    *pos = (char *)(str + i);
    return res;
}









int s21_convert_str_to_int_auto_base(const char* str, char **pos,int width){
    int result = 0;
    int i=0;
    while (str[i] == ' ' || str[i] == '+' || str[i] == '-') {
        i++;
    }

    if (str[i] == '0') {
        if (str[i+1] == 'x' || str[i+1] == 'X') {
            // Число в шестнадцатеричной системе
            result = s21_hex_convert(str, pos,&width);
        } else {
            // Число в восьмеричной системе
            result = s21_octal_convert(str, pos,width);
        }
    } else {
        // Число в десятичной системе
        result = s21_atoi(str, pos,width);
    }
    return result;
}












unsigned long long s21_get_unsigned_num(const char *str, char **pos, int width) {
    unsigned long long result = 0;
    int temp = 0;
    int negative = 0;

    while (*str == ' ') {
        str++;
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

    int check = s21_support_to_ull(str);

    if(check ==1){
        result = ULLONG_MAX;
        *pos = (char *)str+temp;
        return result;
    }

    while (*str >= '0' && *str <= '9' && (width > 0)) {
        // Проверка на переполнение перед умножением
        if (result > ULLONG_MAX / 10 || (result == ULLONG_MAX / 10 && (*str - '0') > ULLONG_MAX % 10)) {
            // Обработка переполнения
            result = ULLONG_MAX;
            break;
        }

        result = result * 10 + (*str - '0');
        str++;
        width--;
    }

    // В случае отрицательного числа, возвращаем ULLONG_MAX
    if (negative) {
        result = ULLONG_MAX;
    }

    if (pos != s21_NULL) {
        *pos = (char *)str;
    }

    return result;
}




int s21_support_to_ull(const char *str) {
    unsigned long long result = 0;

    // Пропуск начальных пробелов
    while (*str == ' ') {
        str++;
    }

    // Чтение и конвертация числа
    while (*str >= '0' && *str <= '9') {
        // Проверка на переполнение перед умножением
        if (result > ULLONG_MAX / 10 || (result == ULLONG_MAX / 10 && (*str - '0') > ULLONG_MAX % 10)) {
            return 1; // Переполнение обнаружено
        }

        result = result * 10 + (*str - '0');
        str++;
    }

    return 0; // Переполнение не обнаружено
}

