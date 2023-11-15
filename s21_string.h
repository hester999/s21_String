#include <stdio.h>
#ifndef S21_STRING_H
#define S21_STRING_H

#define s21_NULL (void*)0
typedef unsigned long long s21_size_t;

void *s21_memchr(const void *arr, int c, s21_size_t n);
int s21_memcmp(const void *arr1, const void *arr2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
#endif