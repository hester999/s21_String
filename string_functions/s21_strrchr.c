#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  int len = (int)s21_strlen(str);
  char *res = s21_NULL;

  for (int i = len; i >= 0; i--) {
    if (str[i] == c) {
      res = (char *)&str[i];
      break;
    }
  }
  return res;
}