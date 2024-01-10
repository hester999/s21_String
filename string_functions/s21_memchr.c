#include "../s21_string.h"

void *s21_memchr(const void *arr, int c, s21_size_t n) {
  int flag = 0;
  s21_size_t i;
  for (i = 0; i < n; i++) {
    if (*((char *)arr + i) == c) {
      flag = 1;
      break;
    }
  }
  if (flag == 1) {
    arr = (char *)arr + i;
  } else {
    arr = s21_NULL;
  }
  return (char *)arr;
}