#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_sscanf.h"
#include "s21_string.h"

int main() {
  printf("%s\n", strerror(-1));
  printf("%s", s21_strerror(-1));

  return 0;
}