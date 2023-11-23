#include <stdlib.h>
#ifndef EXTRA_H
#define EXTRA_H

#define s21_NULL (void*)0
typedef unsigned long long s21_size_t;

int digits_count(int number);
void* custom_calloc(s21_size_t memory, s21_size_t size);

#endif