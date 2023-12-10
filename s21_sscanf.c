#include "s21_sscanf.h"
#include "stdio.h"
void s21_sscanf( const char *str, const char *format, ...) {
    FormatSpecifier specs[16];

    int numSpecs = parse(format, specs, 16);
    int count_char =0;
    va_list args;
    va_start(args, format);
    char* pos;
    for (int i = 0; i < numSpecs; i++) {
        switch (specs[i].type) {
            case SPEC_INT: {

                if(specs[i].lenghtmode ==0 ){
                    int *p = va_arg(args, int*);
                    *p = s21_atoi(str,&pos,&count_char);

                }
                if(specs[i].lenghtmode ==1){
                    short int *p = va_arg(args, short int*);
                    *p = s21_atoi(str,&pos,&count_char);

                }
                if(specs[i].lenghtmode ==2){
                    long int *p = va_arg(args, long int*);
                    *p = s21_atoi(str,&pos,&count_char);
                }

                str = pos;
                break;
            }
            case SPEC_FLOAT: {

                if(specs[i].lenghtmode ==0 ){
                    float *p = va_arg(args, float *);
                    *p = s21_strtof(str,&pos,&count_char);

                }
                if(specs[i].lenghtmode ==2){
                    double *p = va_arg(args, double*);
                    *p = s21_strtof(str,&pos,&count_char);

                }
                if(specs[i].lenghtmode ==3){
                    long double *p = va_arg(args, long double*);
                    *p = s21_strtof(str,&pos,&count_char);
                }
                str = pos;
                break;
            }
            case SPEC_CHAR: {

                char *p = va_arg(args, char*);
                *p = *str++; // Считывание одного символа
                count_char++;
                break;
            }
            case SPEC_STRING: {

                char *p = va_arg(args, char*);
                int j = 0;
                while (str[j] != ' ' && str[j] != '\0') {
                    p[j] = str[j];
                    j++;
                    count_char++;
                }
                p[j] = '\0';

                str += j;
                break;
            }
            case SPEC_SIGNED_INT: {

                int *p = va_arg(args, int *);
                *p = s21_convert_str_to_int_auto_base(str, &pos,&count_char);
                str = pos;
                break;
            }
            case SPEC_EXP:
                break;
            case SPEC_EXP_WITH_E:
                break;
            case SPEC_SORT_DEC:
                break;
            case SPEC_UNSIGNED_8X8_INT:{

                int *p = va_arg(args, int*);
                *p = s21_octal_convert(str, &pos,&count_char);
                str = pos;
                break;
            }
            case SPEC_UNSIGNED_INT:
                break;
            case SPEC_UNSIGNED_16X16_INT: {

                int *p = va_arg(args, int*);
                *p = s21_hex_convert(str, &pos,&count_char);
                str = pos;
                break;
            }
            case SPEC_UNSIGNED_16X16_INT_UPPER: {

                int *p = va_arg(args, int*);
                *p = s21_hex_convert(str, &pos,&count_char);
                str = pos;
                break;
            }
            case SPEC_POINTER:{

                void **p = va_arg(args, void**);
                *(void **)p = (void*)s21_get_pointer(str, &pos,&count_char);
                break;
            }
            case SPEC_COUNT_SIMBOL:{
                int *p = va_arg(args, int*);
                *p =  count_char;
                break;
            }

        }
        while (*str == ' ') {
            str++;
            count_char++;
        }
    }

    va_end(args);

}

