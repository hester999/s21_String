#ifndef S21_CONVERT_H
#define  S21_CONVERT_H

long double s21_strtof(const char *str, char** pos,int *count_char);
long long int s21_atoi(const char *str, char **pos,int *count_char);
int s21_hex_convert(const char *str,char** pos,int *count_char);
int s21_octal_convert(const char *str, char **pos,int *count_char);
unsigned long  long  s21_get_pointer(const char*str,char **pos,int *count_char );
int s21_convert_str_to_int_auto_base(const char* str, char **pos,int *count_char);
unsigned long long get_unsigned_num(const char*str,char **pos,int *count_char);

#endif