#include <string.h>
#include "s21_string.h"
#include <stdio.h>
#include "s21_string.h"
#include <stdlib.h>
#include <math.h>
#include "stdarg.h"
#include "s21_convert.h"


typedef enum {
    SPEC_CHAR,
    SPEC_INT,
    SPEC_SIGNED_INT, //i
    SPEC_EXP, // e
    SPEC_EXP_WITH_E, //E
    SPEC_FLOAT, //f
    SPEC_SORT_DEC, //G,g
    SPEC_UNSIGNED_8X8_INT, //o
    SPEC_STRING, //s
    SPEC_UNSIGNED_INT, //u
    SPEC_UNSIGNED_16X16_INT, //x
    SPEC_UNSIGNED_16X16_INT_UPPER, //X
    SPEC_POINTER, //p
    SPEC_COUNT_SIMBOL, //n
    SPEC_long, // l
    SPEC_LONG, // L
    SPEC_short // h
} SpecifierType;

typedef struct {
    SpecifierType type;
    int width;

} FormatSpecifier;



void s21_sscanf( char *input, const char *formatStr, ...);

int main() {

    float res;
    float res1;
    float res2;



    s21_sscanf("3.14 4.45 1.1555", "%f %f %f", &res,&res1,&res2); // ожидаемый вывод 3.14 56.12
    printf("res1:%f res2:%f res3:%f\n", res,res1,res2);


    return 0;
}


int parse(const char* format,FormatSpecifier *specs,int maxSpecs){

    int numSpecs = 0;

    while(*format != '\0' && numSpecs < maxSpecs) {
        if (*format == '%') {
            *format++;
        }
        switch (*format) {
            case 'c':
                specs[numSpecs++].type = SPEC_CHAR;
                break;

            case 'd':
                specs[numSpecs++].type = SPEC_INT;
                break;

            case 'i':
                specs[numSpecs++].type = SPEC_SIGNED_INT;
                break;

            case 'e':
                specs[numSpecs++].type = SPEC_EXP;
                break;

            case 'E':
                specs[numSpecs++].type = SPEC_EXP_WITH_E;
                break;

            case 'f':
                specs[numSpecs++].type = SPEC_FLOAT;
                break;

            case 'g':
                specs[numSpecs++].type = SPEC_SORT_DEC;
                break;

            case 'G':
                specs[numSpecs++].type = SPEC_SORT_DEC;
                break;

            case 'o':
                specs[numSpecs++].type = SPEC_UNSIGNED_8X8_INT;
                break;

            case 's':
                specs[numSpecs++].type = SPEC_STRING;
                break;

            case 'u':
                specs[numSpecs++].type = SPEC_UNSIGNED_INT;
                break;

            case 'x':
                specs[numSpecs++].type = SPEC_UNSIGNED_16X16_INT;
                break;

            case 'X':
                specs[numSpecs++].type = SPEC_UNSIGNED_16X16_INT_UPPER;
                break;

            case 'p':
                specs[numSpecs++].type = SPEC_POINTER;
                break;

            case 'n':
                specs[numSpecs++].type = SPEC_COUNT_SIMBOL;
                break;

            case 'h':
                specs[numSpecs++].type = SPEC_short;
                break;

            case 'l':
                specs[numSpecs++].type = SPEC_long;
                break;

            case 'L':
                specs[numSpecs++].type = SPEC_LONG;
                break;
        }
        *format++;
    }
    return numSpecs;
}

void s21_sscanf( char *input, const char *formatStr, ...) {
    FormatSpecifier specs[16];
    int numSpecs = parse(formatStr, specs, 16);

    va_list args;
    va_start(args, formatStr);

    char* pos;
    for (int i = 0; i < numSpecs; i++) {
        switch (specs[i].type) {

            case SPEC_INT: {
                int *p = va_arg(args, int*);
                *p = strtol(input, (char **)&input, 10); // Преобразование строки в целое число
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
                *p = *input++;

                break;
            }
        }

        while (*input == ' ') input++;
    }

    va_end(args);

}
