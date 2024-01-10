#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  do {
    if (*str == c) {
      return (char *)str;
    }
  } while (*str++);
  return (0);
}