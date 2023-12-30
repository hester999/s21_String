#include "extra.h"

int digits_count(int number) {
  if (number < 0) {
    return 1 + digits_count(-1 * number);
  }
  int res = 0;
  if (number == 0) return 1;
  while (number > 0) {
    res++;
    number /= 10;
  }
  return res;
}

void* custom_calloc(s21_size_t memory, s21_size_t size) {
  void* pointer = s21_NULL;
  pointer = calloc(memory, size);
  if (pointer == s21_NULL) {
    exit(1);
  }
  return pointer;
}