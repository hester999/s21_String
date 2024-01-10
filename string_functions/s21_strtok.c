#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *last_token = s21_NULL;

  if (str == s21_NULL) {
    str = last_token;
  }
  if (str == s21_NULL || *str == '\0' || delim == s21_NULL) {
    return s21_NULL;
  }

  while (*str && s21_strchr(delim, *str) != s21_NULL) {
    str++;
  }

  if (*str == '\0') {
    last_token = s21_NULL;
    return s21_NULL;
  }

  char *start_token = str;
  str += s21_strcspn(str, delim);

  if (*str != '\0') {
    *str = '\0';
    last_token = str + 1;
  } else {
    last_token = s21_NULL;
  }

  return start_token;
}