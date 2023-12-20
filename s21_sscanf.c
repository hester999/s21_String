#include "s21_sscanf.h"
#include "stdio.h"
void s21_sscanf( const char *str, const char *format, ...) {
    int size = 10;
    FormatSpecifier *specs = calloc(size, sizeof (FormatSpecifier));

    int numSpecs = parse(format, &specs, &size);
    char const * begin = str;

    va_list args;
    va_start(args, format);
    char* pos;
    for (int i = 0; i < numSpecs; i++) {
        switch (specs[i].type) {
            case SPEC_INT: {
                if(specs[i].lenghtmode ==0 ){
                    int *p = va_arg(args, int*);
                    *p = s21_atoi(str,&pos);

                }
                if(specs[i].lenghtmode ==1){
                    short int *p = va_arg(args, short int*);
                    *p = s21_atoi(str,&pos);

                }
                if(specs[i].lenghtmode ==2){
                    long int *p = va_arg(args, long int*);
                    *p = s21_atoi(str,&pos);
                }
                if(specs[i].lenghtmode ==3){
                    long long int *p = va_arg(args, long long  int*);
                    *p = s21_atoi(str,&pos);
                }

                str = pos;
                break;
            }
            case SPEC_FLOAT: {

                if(specs[i].lenghtmode ==0 ){
                    float *p = va_arg(args, float *);
                    *p = s21_strtof(str,&pos);

                }
                if(specs[i].lenghtmode ==2){
                    double *p = va_arg(args, double*);
                    *p = s21_strtof(str,&pos);

                }
                if(specs[i].lenghtmode ==4){
                    long double *p = va_arg(args, long double*);
                    *p = s21_strtof(str,&pos);
                }
                str = pos;
                break;
            }
            case SPEC_CHAR: {

                char *p = va_arg(args, char*);
                *p = *str++; // Считывание одного символа
                pos = (char*)str;
                break;
            }
            case SPEC_STRING: {

                char *p = va_arg(args, char*);
                int j = 0;
                while (str[j] != ' ' && str[j] != '\0') {
                    p[j] = str[j];
                    j++;

                }
                p[j] = '\0';

                str += j;
                pos = (char*)str;
                break;
            }
            case SPEC_SIGNED_INT: {

                int *p = va_arg(args, int *);
                *p = s21_convert_str_to_int_auto_base(str, &pos);
                str = pos;
                break;
            }
            case SPEC_EXP:{
                if(specs[i].lenghtmode ==0 ){
                    float *p = va_arg(args, float *);
                    *p = s21_strtof(str,&pos);

                }
                if(specs[i].lenghtmode ==2){
                    double *p = va_arg(args, double*);
                    *p = s21_strtof(str,&pos);

                }
                if(specs[i].lenghtmode ==4){
                    long double *p = va_arg(args, long double*);
                    *p = s21_strtof(str,&pos);
                }
                str = pos;
                break;
        }
            case SPEC_EXP_WITH_E:{
                if(specs[i].lenghtmode ==0 ){
                    float *p = va_arg(args, float *);
                    *p = s21_strtof(str,&pos);

                }
                if(specs[i].lenghtmode ==2){
                    double *p = va_arg(args, double*);
                    *p = s21_strtof(str,&pos);

                }
                if(specs[i].lenghtmode ==4){
                    long double *p = va_arg(args, long double*);
                    *p = s21_strtof(str,&pos);
                }
                str = pos;
                break;
            }
            case SPEC_SORT_DEC:{
                if(specs[i].lenghtmode ==0 ){
                    float *p = va_arg(args, float *);
                    *p = s21_strtof(str,&pos);

                }
                if(specs[i].lenghtmode ==2){
                    double *p = va_arg(args, double*);
                    *p = s21_strtof(str,&pos);

                }
                if(specs[i].lenghtmode ==4){
                    long double *p = va_arg(args, long double*);
                    *p = s21_strtof(str,&pos);
                }
                str = pos;
                break;
            }

            case SPEC_UNSIGNED_8X8_INT:{

                int *p = va_arg(args, int*);
                *p = s21_octal_convert(str, &pos);
                str = pos;
                break;
            }
            case SPEC_UNSIGNED_INT:{
                if(specs[i].lenghtmode == 0){
                    unsigned int *p = va_arg(args, unsigned int *);
                    *p = s21_get_unsigned_num(str, &pos);
                }
                if(specs[i].lenghtmode == 1){
                    unsigned short int *p = va_arg(args, unsigned short int *);
                    *p = s21_get_unsigned_num(str, &pos);
                }

                if(specs[i].lenghtmode == 2){
                    unsigned long int *p = va_arg(args,unsigned long int * );
                    *p = s21_get_unsigned_num(str, &pos);
                }

                if(specs[i].lenghtmode == 3){
                    unsigned long long int *p = va_arg(args,unsigned long long  int * );
                    *p = s21_get_unsigned_num(str, &pos);
                }

                str = pos;
                break;


            }

            case SPEC_UNSIGNED_16X16_INT: {

                int *p = va_arg(args, int*);
                *p = s21_hex_convert(str, &pos);
                str = pos;
                break;
            }
            case SPEC_UNSIGNED_16X16_INT_UPPER: {

                int *p = va_arg(args, int*);
                *p = s21_hex_convert(str, &pos);
                str = pos;
                break;
            }
            case SPEC_POINTER:{
                void **p = va_arg(args, void**);
                *(void **)p = (void*)s21_get_pointer(str, &pos);
                str = pos;
                break;
            }
            case SPEC_COUNT_SIMBOL:{
                int *p = va_arg(args, int*);
                *p =  pos - begin;
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
}

