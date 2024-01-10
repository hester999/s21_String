#include "../s21_sprintf.h"
#include "../s21_string.h"

char *s21_strerror(int errnum) {
  static char *errlist[] = ERRLIST;
  static char unknown_error[64];
  char *error = s21_NULL;
  if (errnum >= 0 && errnum <= ERRLIST_LEN) {
    error = (char *)errlist[errnum];
  } else {
#if defined(__APPLE__)
    s21_strncpy(unknown_error, "Unknown error: ", (s21_size_t)15);
#elif defined(__linux__)
    s21_strncpy(unknown_error, "Unknown error ", (s21_size_t)14);
#endif
    char unknown_error_code[10];
    s21_sprintf(unknown_error_code, "%d", errnum);
    s21_strncat(unknown_error, unknown_error_code, digits_count(errnum));
    error = unknown_error;
  }
  return error;
}