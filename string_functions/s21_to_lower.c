#include "../s21_string.h"

void *s21_to_lower(const char *str) {
  s21_size_t length = 0;
  s21_size_t i = 0;
  char *buff = s21_NULL;
  if (str) {
    length = s21_strlen(str);
    buff = (char *)custom_calloc(length + 1, 1);
  }
  if (str) {
    for (; i < length; i++)
      if (str[i] >= 'A' && str[i] <= 'Z') {
        buff[i] = str[i] + 32;
      } else {
        buff[i] = str[i];
      }
  }
  return buff;
}