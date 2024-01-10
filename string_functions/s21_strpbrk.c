#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  s21_size_t i = 0;
  s21_size_t k = 0;
  s21_size_t str1_len = s21_strlen(str1);
  s21_size_t str2_len = s21_strlen(str2);
  char *res = s21_NULL;
  for (i = 0; i < str1_len; i++) {
    for (k = 0; k < str2_len; k++) {
      if (str1[i] == str2[k]) {
        res = (char *)&str1[i];
        return res;
      }
    }
  }
  return res;
}