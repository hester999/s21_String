#include "../s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t count = 0;
  s21_size_t i;

  for (i = 0; str[i] != '\0'; i++) {
    count++;
  }
  return count;
}