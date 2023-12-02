#ifndef S21_CONVERT_H
#define  S21_CONVERT_H

float s21_strtof(const char *str, char** pos);
int atoi_counter(const char *str);
int s21_atoi(const char *str,char** pos);
int hex_convert(const char *str,char** pos);
int octal_convert(const char *str, char **pos);
unsigned long  long  get_pointer(const char*str,char **pos );
int convert_str_to_int_auto_base(char* str, char **pos);


#endif