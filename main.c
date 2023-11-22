#include <string.h>
#include "s21_string.h"
#include <stdio.h>
#include "s21_string.h"
#include <stdlib.h>
#include <math.h>



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

int test_sscnaf(char* buff, char* spec,FormatSpecifier specs,...);
int parse(const char* format,FormatSpecifier *specs,int maxSpecs);

int main() {

    FormatSpecifier specs;
    char str[80];
    int i;
    char *buff = "123 1";


    printf("%d", sscanf(buff, "%s", str));

    return 0;
}


int test_sscnaf(char* buff, char* spec,FormatSpecifier specs,...){

    int count_param=0;

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
