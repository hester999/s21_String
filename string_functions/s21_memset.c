#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *a1 = str;

  for (s21_size_t i = 0; i < n; i++) {
    a1[i] = (char)c;
  }
  return a1;
}