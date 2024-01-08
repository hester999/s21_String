#include "s21_sscanf.h"
#include "stdio.h"
#include "s21_string.h"

int s21_sscanf( const char *str, const char *format, ...) {
    int size = 10;

    FormatSpecifier *specs = calloc(size, sizeof (FormatSpecifier));

    int numSpecs = parse(format, &specs, &size);
    char const * begin = str;

    va_list args;
    va_start(args, format);
    int width = 0;
    int isstar =0;
    int flag=0;
    char* pos;
    int count_spec=0;
    for (int i = 0; i < numSpecs; i++) {
        switch (specs[i].type) {
            case SPEC_INT: {
                if(specs[i].is_star_flag == 1){
                    width = specs[i].width;
                    s21_atoi(str,&pos,width,&count_spec);
                    count_spec--;
                    isstar = 1;
                }


                else if(specs[i].lenghtmode == 0){
                    int *p = va_arg(args, int*);
                    width = specs[i].width;
                    *p = s21_atoi(str, &pos,width,&count_spec);

                }
                else if(specs[i].lenghtmode ==1){
                    short int *p = va_arg(args, short int*);
                    width = specs[i].width;
                    *p = s21_atoi(str,&pos,width,&count_spec);


                }
                else if(specs[i].lenghtmode ==2){
                    long int *p = va_arg(args, long int*);
                    width = specs[i].width;
                    *p = s21_atoi(str,&pos,width,&count_spec);

                }
                else if(specs[i].lenghtmode ==3){
                    long long int *p = va_arg(args, long long  int*);
                    width = specs[i].width;
                    *p = s21_atoi(str,&pos,width,&count_spec);

                }
                str = pos;

                break;
            }



            case SPEC_FLOAT: {
                if(specs[i].is_star_flag == 1){
                    width = specs[i].width;
                    s21_strtof(str,&pos,width,&count_spec);
//                    str = pos;
                    count_spec--;
                    
                }
                else if(specs[i].lenghtmode ==0 ){
                    float *p = va_arg(args, float *);
                    width = specs[i].width;
                    *p = s21_strtof(str,&pos,width,&count_spec);

                }
                else if(specs[i].lenghtmode ==2){
                    double *p = va_arg(args, double*);
                    width = specs[i].width;
                    *p = s21_strtof(str,&pos,width,&count_spec);

                }
                else if(specs[i].lenghtmode ==4){
                    long double *p = va_arg(args, long double*);
                    width = specs[i].width;
                    *p = s21_strtof(str,&pos,width,&count_spec);

                }
                str = pos;
                break;
            }

            case SPEC_CHAR: {
                char *p = NULL;
                int width = specs[i].width > 0 ? specs[i].width : 1; // Получение ширины, используйте 1, если ширина не указана

                if (specs[i].is_star_flag != 1) {
                    p = va_arg(args, char*);
                }

                for (int j = 0; j < width && *str != '\0'; j++) {
                    if (p != NULL) {
                        *p++ = *str; // Сохранение символа и переход к следующему месту в буфере
                    }
                    str++;
                }

                pos = (char*)str;
                count_spec++;
                break;
            }




            case SPEC_STRING: {
                char *p = s21_NULL;
                width = specs[i].width;
                int len = 0;
                int readIndex = 0, writeIndex = 0;

                if (specs[i].is_star_flag != 1) {
                    p = va_arg(args, char*);
                }

                // Вычисляем длину слова в строке
                for (int k = 0; str[k] != ' ' && str[k] != '\0'; k++) {
                    len++;
                }

                // Устанавливаем width равным длине слова, если не задано иное
                if (width == -100 || width > len || width == 0) {
                    width = len;
                }

                // Чтение и копирование строки
                while (str[readIndex] != ' ' && str[readIndex] != '\0' && width > 0) {
                    if (specs[i].is_star_flag != 1 && p != s21_NULL) {
                        p[writeIndex] = str[readIndex];
                        writeIndex++;
                    }
                    readIndex++;
                    width--;
                }

                // Закрываем строку нулевым символом, если это необходимо
                if (p != s21_NULL && specs[i].is_star_flag != 1) {
                    p[writeIndex] = '\0';
                }

                // Двигаем указатель str на прочитанные символы
                str += readIndex;
                if (*str == ' ') {
                    str++;
                }
                pos = (char*)str;
                count_spec++;
                break;
            }




            case SPEC_SIGNED_INT: {
                if(specs[i].is_star_flag == 1){
                    width = specs[i].width;
                    s21_convert_str_to_int_auto_base(str, &pos,width,&count_spec);
                    str = pos;
                    count_spec--;
                    isstar = 1;
                    
                }else{
                    
                    int *p = va_arg(args, int *);
                    width = specs[i].width;
                    *p = s21_convert_str_to_int_auto_base(str, &pos,width,&count_spec);
                    str = pos;
                }
                break;
            }



            case SPEC_EXP:{
                if(specs[i].is_star_flag==1){
                    width = specs[i].width;
                    s21_strtof(str,&pos,width,&count_spec);
                    count_spec--;
                    isstar = 1;
                }
                else if(specs[i].lenghtmode ==0 ){
                    float *p = va_arg(args, float *);
                    width = specs[i].width;
                    *p = s21_strtof(str,&pos,width,&count_spec);

                }
                else if(specs[i].lenghtmode ==2){
                    double *p = va_arg(args, double*);
                    width = specs[i].width;
                    *p = s21_strtof(str,&pos,width,&count_spec);

                }
                else if(specs[i].lenghtmode ==4){
                    long double *p = va_arg(args, long double*);
                    width = specs[i].width;
                    *p = s21_strtof(str,&pos,width,&count_spec);

                }
                str = pos;
                break;
            }




            case SPEC_EXP_WITH_E:{
                if(specs[i].is_star_flag == 1){
                    width = specs[i].width;
                    s21_strtof(str,&pos,width,&count_spec);
                    count_spec--;
                    isstar = 1;
            
                }
                else if(specs[i].lenghtmode ==0 ){
                    float *p = va_arg(args, float *);
                    width = specs[i].width;
                    *p = s21_strtof(str,&pos,width,&count_spec);

                }
                else if(specs[i].lenghtmode ==2){
                    double *p = va_arg(args, double*);
                    width = specs[i].width;
                    *p = s21_strtof(str,&pos,width,&count_spec);

                }
                else if(specs[i].lenghtmode ==4){
                    long double *p = va_arg(args, long double*);
                    width = specs[i].width;
                    *p = s21_strtof(str,&pos,width,&count_spec);

                }
                str = pos;
                break;
            }




            case SPEC_SORT_DEC:{
                if(specs[i].is_star_flag==1){
                    width = specs[i].width;
                    s21_strtof(str,&pos,width,&count_spec);
                    count_spec--;
                }
                else if(specs[i].lenghtmode ==0 ){
                    float *p = va_arg(args, float *);
                    width = specs[i].width;
                    *p = s21_strtof(str,&pos,width,&count_spec);

                }
                else if(specs[i].lenghtmode ==2){
                    double *p = va_arg(args, double*);
                    width = specs[i].width;
                    *p = s21_strtof(str,&pos,width,&count_spec);

                }
                else if(specs[i].lenghtmode ==4){
                    long double *p = va_arg(args, long double*);
                    width = specs[i].width;
                    *p = s21_strtof(str,&pos,width,&count_spec);

                }
                str = pos;
                break;
            }



            case SPEC_UNSIGNED_8X8_INT:{
                if(specs[i].is_star_flag ==1){
                    width = specs[i].width;
                    s21_octal_convert(str, &pos,width,&count_spec);
                    count_spec--;
                    isstar = 1;
                }else{
                    int *p = va_arg(args, int*);
                    width = specs[i].width;
                    *p = s21_octal_convert(str, &pos,width,&count_spec);

                }
                str = pos;
                break;
            }



            case SPEC_UNSIGNED_INT:{
                if(specs[i].is_star_flag ==1 ){
                    width = specs[i].width;
                    s21_get_unsigned_num(str, &pos,width,&count_spec);
                    count_spec--;
                    isstar = 1;
                }
                else if(specs[i].lenghtmode == 0){
                    unsigned int *p = va_arg(args, unsigned int *);
                    width = specs[i].width;
                    *p = s21_get_unsigned_num(str, &pos,width,&count_spec);
                    count_spec++;
                }
                else if(specs[i].lenghtmode == 1){
                    unsigned short int *p = va_arg(args, unsigned short int *);
                     width = specs[i].width;
                    *p = s21_get_unsigned_num(str, &pos,width,&count_spec);
                    count_spec++;
                }

                else if(specs[i].lenghtmode == 2){
                    unsigned long int *p = va_arg(args,unsigned long int * );
                     width = specs[i].width;
                    *p = s21_get_unsigned_num(str, &pos,width,&count_spec);
                    count_spec++;
                }

                else if(specs[i].lenghtmode == 3){
                    unsigned long long int *p = va_arg(args,unsigned long long  int * );
                    width = specs[i].width;
                    *p = s21_get_unsigned_num(str, &pos,width,&count_spec);
                    count_spec++;
                }

                str = pos;
                break;
            }




            case SPEC_UNSIGNED_16X16_INT: {
                if(width ==0 && flag == 0 ){
                    width= specs[i].width;
                    flag =1 ;
                }else{
                    flag = 0;
                }

                if(specs[i].is_star_flag==1){
                    s21_hex_convert(str, &pos,&width,&count_spec);
                    str = pos;
                    count_spec--;
                    isstar = 1;
                }
                else{
                    int *p = va_arg(args, int*);
                    *p = s21_hex_convert(str, &pos,&width,&count_spec);
                    str = pos;
                }
                break;
            }





            case SPEC_UNSIGNED_16X16_INT_UPPER: {

                if(specs[i].is_star_flag==1){
                    width = specs[i].width;
                    s21_hex_convert(str, &pos, &width,&count_spec);
                    str = pos;
                    count_spec--;
                    isstar = 1;
                }
                else{
                    int *p = va_arg(args, int*);
                    width = specs[i].width;
                    *p = s21_hex_convert(str, &pos,&width,&count_spec);
                    str = pos;
                }
                break;
            }




            case SPEC_POINTER:{
                if(specs[i].is_star_flag == 1){
                    width = specs[i].width;
                    void **a =NULL;
                    *(void **)a = (void*)s21_get_pointer(str, &pos,width,&count_spec);
                    if(a){};
                    count_spec--;
                    isstar = 1;
                
                }else{  
                    void **p = va_arg(args, void**);
                    width = specs[i].width;
                    *(void **)p = (void*)s21_get_pointer(str, &pos,width,&count_spec);
                }
                str = pos;
        
                break;
            }
            case SPEC_PERCENT: {
                if (s21_strchr(str, '%') == s21_NULL) {
                    return count_spec;
                }
                str++;
                break;
            }
            case SPEC_COUNT_SIMBOL:{
                if (specs[i].is_star_flag !=1){
                    int *p = va_arg(args, int*);
                    *p = pos - begin;
                }
                break;
            }

        }
        while (*str == ' ') {
            str++;
            pos++;
        }
    }

    free(specs);
    va_end(args);
    if(count_spec == 0 && isstar != 1){
        count_spec = -1;
    }
    return  count_spec;
}
