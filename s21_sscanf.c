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
                if(specs[i].is_star_flag == 1){
                    s21_atoi(str,&pos);
//                    str = pos;
                }
                else if(specs[i].lenghtmode == 0){
                    int *p = va_arg(args, int*);
                    *p = s21_atoi(str, &pos);

                }
                else if(specs[i].lenghtmode ==1){
                    short int *p = va_arg(args, short int*);
                    *p = s21_atoi(str,&pos);

                }
                else if(specs[i].lenghtmode ==2){
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
                if(specs[i].is_star_flag == 1){
                    s21_strtof(str,&pos);
//                    str = pos;
                }
                else if(specs[i].lenghtmode ==0 ){
                    float *p = va_arg(args, float *);
                    *p = s21_strtof(str,&pos);

                }
                else if(specs[i].lenghtmode ==2){
                    double *p = va_arg(args, double*);
                    *p = s21_strtof(str,&pos);

                }
                else if(specs[i].lenghtmode ==4){
                    long double *p = va_arg(args, long double*);
                    *p = s21_strtof(str,&pos);
                }
                str = pos;
                break;
            }
            case SPEC_CHAR: {

                char *p = NULL;
                if (specs[i].is_star_flag != 1) {
                    p = va_arg(args, char*);
                }
                if (*str != '\0') {
                    if (p != NULL) {
                        *p = *str;
                    }
                    str++;
                }
                pos = (char*)str;

                break;
            }
            case SPEC_STRING: {
                char *p = NULL;
                if (specs[i].is_star_flag != 1) {
                    p = va_arg(args, char*);
                }
                int j = 0;
                while (str[j] != ' ' && str[j] != '\0') {
                    if (p != NULL) {
                        p[j] = str[j];
                    }
                    j++;
                }
                if (p != NULL) {
                    p[j] = '\0';
                }
                str += j;
                if (*str == ' ') {
                    str++;
                }
                pos = (char*)str;
                break;
            }

            case SPEC_SIGNED_INT: {
                if(specs[i].is_star_flag == 1){
                    s21_convert_str_to_int_auto_base(str, &pos);
                    str = pos;
                }else{
                    int *p = va_arg(args, int *);
                    *p = s21_convert_str_to_int_auto_base(str, &pos);
                    str = pos;
                }
                break;
            }
            case SPEC_EXP:{
                if(specs[i].is_star_flag==1){
                    s21_strtof(str,&pos);
                }
                else if(specs[i].lenghtmode ==0 ){
                    float *p = va_arg(args, float *);
                    *p = s21_strtof(str,&pos);

                }
                else if(specs[i].lenghtmode ==2){
                    double *p = va_arg(args, double*);
                    *p = s21_strtof(str,&pos);

                }
                else if(specs[i].lenghtmode ==4){
                    long double *p = va_arg(args, long double*);
                    *p = s21_strtof(str,&pos);
                }
                str = pos;
                break;
            }
            case SPEC_EXP_WITH_E:{
                if(specs[i].is_star_flag == 1){
                    s21_strtof(str,&pos);
                }
                else if(specs[i].lenghtmode ==0 ){
                    float *p = va_arg(args, float *);
                    *p = s21_strtof(str,&pos);

                }
                else if(specs[i].lenghtmode ==2){
                    double *p = va_arg(args, double*);
                    *p = s21_strtof(str,&pos);

                }
                else if(specs[i].lenghtmode ==4){
                    long double *p = va_arg(args, long double*);
                    *p = s21_strtof(str,&pos);
                }
                str = pos;
                break;
            }
            case SPEC_SORT_DEC:{
                if(specs[i].is_star_flag==1){
                    s21_strtof(str,&pos);
                }
                else if(specs[i].lenghtmode ==0 ){
                    float *p = va_arg(args, float *);
                    *p = s21_strtof(str,&pos);
                }
                else if(specs[i].lenghtmode ==2){
                    double *p = va_arg(args, double*);
                    *p = s21_strtof(str,&pos);

                }
                else if(specs[i].lenghtmode ==4){
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
                if(specs[i].is_star_flag ==1 ){
                    s21_get_unsigned_num(str, &pos);
                }
                else if(specs[i].lenghtmode == 0){
                    unsigned int *p = va_arg(args, unsigned int *);
                    *p = s21_get_unsigned_num(str, &pos);
                }
                else if(specs[i].lenghtmode == 1){
                    unsigned short int *p = va_arg(args, unsigned short int *);
                    *p = s21_get_unsigned_num(str, &pos);
                }

                else if(specs[i].lenghtmode == 2){
                    unsigned long int *p = va_arg(args,unsigned long int * );
                    *p = s21_get_unsigned_num(str, &pos);
                }

                else if(specs[i].lenghtmode == 3){
                    unsigned long long int *p = va_arg(args,unsigned long long  int * );
                    *p = s21_get_unsigned_num(str, &pos);
                }

                str = pos;
                break;
            }

            case SPEC_UNSIGNED_16X16_INT: {
                if(specs[i].is_star_flag==1){
                    s21_hex_convert(str, &pos);
                    str = pos;
                }
                else{
                    int *p = va_arg(args, int*);
                    *p = s21_hex_convert(str, &pos);
                    str = pos;
                }

                break;
            }
            case SPEC_UNSIGNED_16X16_INT_UPPER: {

                if(specs[i].is_star_flag==1){
                    s21_hex_convert(str, &pos);
                    str = pos;
                }
                else{
                    int *p = va_arg(args, int*);
                    *p = s21_hex_convert(str, &pos);
                    str = pos;
                }
                break;
            }
            case SPEC_POINTER:{
                void **p = va_arg(args, void**);
                *(void **)p = (void*)s21_get_pointer(str, &pos);
                str = pos;
                break;
            }
            case SPEC_COUNT_SIMBOL:{
                if (specs[i].is_star_flag != 1 ){
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
}