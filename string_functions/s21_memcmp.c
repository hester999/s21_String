#include "../s21_string.h"

int s21_memcmp(const void *arr1, const void *arr2, s21_size_t n) {
  s21_size_t i;
  int flag = 0;
  const unsigned char *a1 = arr1;
  const unsigned char *a2 = arr2;

  for (i = 0; i < n; i++) {
    if (a1[i] == a2[i]) {
      flag = 0;
    }
    if (a1[i] > a2[i]) {
      flag = a1[i] - a2[i];
      break;
    }
    if (a2[i] > a1[i]) {
      flag = a1[i] - a2[i];
      break;
    }
  }
  return flag;
}