#include "../s21_string.h"

void* s21_trim(const char* src, const char* trim_chars) {
  char* st = s21_NULL;
  if (trim_chars == s21_NULL) return (char*)src;
  if (src != s21_NULL) {
    s21_size_t n = s21_strlen(src);
    char* start = (char*)src;
    char* end = (char*)src + n;
    for (; *start && s21_strchr(trim_chars, *start); start++)
      ;
    for (; end != start && s21_strchr(trim_chars, *(end - 1)); end--)
      ;
    st = malloc((end - start + 1) * sizeof(char));
    if (st != s21_NULL) {
      s21_strncpy(st, start, end - start);
      *(st + (end - start)) = '\0';
    }
  }
  return st;
}