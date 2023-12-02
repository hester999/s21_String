#include "s21_sscanf.h"



void s21_sscanf( char *input, const char *formatStr, ...) {
    FormatSpecifier specs[16];
    int numSpecs = parse(formatStr, specs, 16);

    va_list args;
    va_start(args, formatStr);

    char* pos = input;
    for (int i = 0; i < numSpecs; i++) {
        switch (specs[i].type) {
            case SPEC_INT: {
                int *p = va_arg(args, int*);
                *p = s21_atoi(input,&pos); // Преобразование строки в целое число
                input = pos;
                break;
            }
            case SPEC_FLOAT: {
                float *p = va_arg(args, float*);

                *p = s21_strtof(input,&pos);

                input = pos;

                break;
            }
            case SPEC_CHAR: {
                char *p = va_arg(args, char*);
                *p = *input++; // Считывание одного символа
                break;
            }
            case SPEC_STRING: {
                char *p = va_arg(args, char*);
                int j = 0;
                while (input[j] != ' ' && input[j] != '\0') {
                    p[j] = input[j];
                    j++;
                }
                p[j] = '\0';

                input += j;
                break;
            }
            case SPEC_SIGNED_INT: {
                int *p = va_arg(args, int *);

                *p = convert_str_to_int_auto_base(input, &pos);
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
                *p = octal_convert(input, &pos);
                input = pos;
                break;
            }
            case SPEC_UNSIGNED_INT:
                break;
            case SPEC_UNSIGNED_16X16_INT: {
                int *p = va_arg(args, int*);
                *p = hex_convert(input, &pos);
                input = pos;
                break;
            }
            case SPEC_UNSIGNED_16X16_INT_UPPER: {
                int *p = va_arg(args, int*);
                *p = hex_convert(input, &pos);
                input = pos;
                break;
            }
            case SPEC_POINTER:{
                void **p = va_arg(args, void**);

                *(void **)p = (void*)get_pointer(input, &pos);
                break;
            }
            case SPEC_COUNT_SIMBOL:
                break;
            case SPEC_long:
                break;
            case SPEC_LONG:
                break;
            case SPEC_short:
                break;
        }

        while (*input == ' ') input++;
    }

    va_end(args);

}
