#ifndef S21_PARSE_H_
#define S21_PARSE_H_

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

} SpecifierType;

typedef struct {
    SpecifierType type;
    int width;
    int lenghtmode;
    int is_star_flag;
} FormatSpecifier;

int parse(const char* format,FormatSpecifier **specs,int *len);

#endif