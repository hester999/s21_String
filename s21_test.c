#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include <string.h>

#include "s21_string.h"

START_TEST(strlen_test1) {
  char str[] = "Hello, World";
  ck_assert_msg(s21_strlen(str) == strlen(str), "Fail test 1");
}

Suite *example_suite() {
  Suite *s1 = suite_create("Example_test");
  Tcase *strlen_tests = tcase_create("STRLEN");
  suite_add_tcase(s1, strlen_tests);
  tcase_add_test(strlen_tests, strlen_test1);

  return s1;
}

int main() {
  Suite *s1 = example_suite();

  Srunner *runner = srunner_create(s1);

  int number_fails;
  srunner_run_all(runner, CK_NORMAL);
  number_fails = srunner_ntests_failed(runner);
  srunner_free(runner);

  return number_fails == 0 ? 0 : 1;
}