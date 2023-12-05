#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include <string.h>

#include "s21_string.h"

// TESTS FOR MEMCHR
START_TEST(memchr_test1) {
  char str[20] = "memchr_test";
  ck_assert_mem_eq(s21_memchr(str, 'c', 20), memchr(str, 'c', 20), 20);
}

START_TEST(memchr_test2) {
  char str[20] = "memchr_test";
  ck_assert_msg(s21_memchr(str, 'C', 11) == s21_NULL, "Fail: s21_memchr == s21_NULL");
}

START_TEST(memchr_test3) {
  char str[30] = "memchr_test";
  ck_assert_msg(s21_memchr(str, 'F', 11) == s21_NULL, "Fail: s21_memchr == s21_NULL");
}

START_TEST(memchr_test4) {
  char str[20] = "memchr_test";
  ck_assert_mem_eq(s21_memchr(str, 'm', 20), memchr(str, 'm', 20), 20);
}

START_TEST(memchr_test5) {
  char str[20] = "memchr_test";
  ck_assert_mem_eq(s21_memchr(str, 'm', 0), memchr(str, 'm', 0), 0);
}


// TESTS FOR MEMCMP
START_TEST(memcmp_test1) {
  char str1[20] = "memcmp_test";
  char str2[20] = "memcmp_test";
  ck_assert_int_eq(s21_memcmp(str1, str2, 11), memcmp(str1, str2, 11));
}

START_TEST(memcmp_test2) {
  char str1[20] = "memcmp_test!!!";
  char str2[20] = "memcmp_test";
  ck_assert_int_eq(s21_memcmp(str1, str2, 11), memcmp(str1, str2, 11));
}

START_TEST(memcmp_test3) {
  char str1[20] = "memcmp_test";
  char str2[20] = "memcmp_test!!!";
  ck_assert_int_eq(s21_memcmp(str1, str2, 11), memcmp(str1, str2, 11));
}

START_TEST(memcmp_test4) {
  char str1[20] = "";
  char str2[20] = "";
  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
}

START_TEST(memcmp_test5) {
  char str1[20] = "\n\n\n\n\n";
  char str2[20] = "\n\n\n\n\n";
  ck_assert_int_eq(s21_memcmp(str1, str2, 5), memcmp(str1, str2, 5));
}


// TESTS FOR MEMCPY
START_TEST(memcpy_test1) {
  char src[20] = "memcpy_test";
  char dest[20] = "";
  ck_assert_str_eq(s21_memcpy(dest, src, 11), memcpy(dest, src, 11));
}

START_TEST(memcpy_test2) {
  char src[20] = "memcpy_test";
  char dest[20] = "";
  ck_assert_str_eq(s21_memcpy(dest, src, 6), memcpy(dest, src, 6));
}

START_TEST(memcpy_test3) {
  char src[20] = "memcpy_test";
  char dest[20] = "";
  ck_assert_str_eq(s21_memcpy(dest, src, 0), memcpy(dest, src, 0));
}

START_TEST(memcpy_test4) {
  char src[20] = "memcpy_test";
  char dest[20] = "";
  ck_assert_str_eq(s21_memcpy(dest, src, 20), memcpy(dest, src, 20));
}

START_TEST(memcpy_test5) {
  char src[20] = "memcpy_test";
  char dest[20] = "";
  ck_assert_str_eq(s21_memcpy(src, dest, 6), memcpy(src, dest, 6));
}

// TESTS FOR MEMSET
START_TEST(memset_test1) {
  char str[20] = "1234567890";
  ck_assert_str_eq(s21_memset(str, '1', 10), memset(str, '1', 10));
}

START_TEST(memset_test2) {
  char str[20] = "1234567890";
  ck_assert_str_eq(s21_memset(str, '1', 20), memset(str, '1', 20));

}

START_TEST(memset_test3) {
  char str[20] = "1234567890";
  ck_assert_str_eq(s21_memset(str, '\n', 10), memset(str, '\n', 10));
}

START_TEST(memset_test4) {
  char str[20] = "1234567890";
  ck_assert_str_eq(s21_memset(str, ' ', 10), memset(str, ' ', 10));
}

START_TEST(memset_test5) {
  char str[20] = "1234567890";
  ck_assert_str_eq(s21_memset(str, 'A', 10), memset(str, 'A', 10));
}


// TESTS FOR STRNCAT
START_TEST(strncat_test1) {
  char dest[20] = "strncat";
  char src[20] = "_test";
  ck_assert_str_eq(s21_strncat(dest, src, 5), strncat(dest, src, 5));
}

START_TEST(strncat_test2) {
  char dest[20] = "strncat";
  char src[20] = "_test";
  ck_assert_str_eq(s21_strncat(dest, src, 1), strncat(dest, src, 1));
}

START_TEST(strncat_test3) {
  char dest[20] = "strncat";
  char src[20] = "_test";
  ck_assert_str_eq(s21_strncat(dest, src, 0), strncat(dest, src, 0));
}

START_TEST(strncat_test4) {
  char dest[20] = "123456";
  char src[20] = "7890";
  ck_assert_str_eq(s21_strncat(dest, src, 4), strncat(dest, src, 4));
}

START_TEST(strncat_test5) {
  char dest[20] = "strncat_test";
  char src[20] = "\n";
  ck_assert_str_eq(s21_strncat(dest, src, 1), strncat(dest, src, 1));
}


// TESTS FOR STRCHR
START_TEST(strchr_test1) {
  char str[20] = "strchr_test";
  ck_assert_str_eq(s21_strchr(str, 's'), strchr(str, 's'));
}

START_TEST(strchr_test2) {
  char str[20] = "strchr_test";
  ck_assert_str_eq(s21_strchr(str, 'c'), strchr(str, 'c'));
}

START_TEST(strchr_test3) {
  char str[20] = "strchr_test\n";
  ck_assert_str_eq(s21_strchr(str, '\n'), strchr(str, '\n'));
}

START_TEST(strchr_test4) {
  char str[20] = "strchr_test";
  ck_assert_str_eq(s21_strchr(str, '\0'), strchr(str, '\0'));
}

START_TEST(strchr_test5) {
  char str[20] = "";
  ck_assert_str_eq(s21_strchr(str, '\0'), strchr(str, '\0'));
}


// TESTS FOR STRNCMP
START_TEST(strncmp_test1) {
  char str1[20] = "strncat_test";
  char str2[20] = "strncat_test";
  ck_assert_int_eq(s21_strncmp(str1, str2, 11), strncmp(str1, str2, 11));
}

START_TEST(strncmp_test2) {
  char str1[20] = "strncat_test!!!";
  char str2[20] = "strncat_test";
  ck_assert_int_eq(s21_strncmp(str1, str2, 20), strncmp(str1, str2, 20));
}

START_TEST(strncmp_test3) {
  char str1[20] = "strncat_test";
  char str2[20] = "strncat_test!!!";
  ck_assert_int_eq(s21_strncmp(str1, str2, 20), strncmp(str1, str2, 20));
}

START_TEST(strncmp_test4) {
  char str1[20] = "";
  char str2[20] = "";
  ck_assert_int_eq(s21_strncmp(str1, str2, 0), strncmp(str1, str2, 0));
}

START_TEST(strncmp_test5) {
  char str1[20] = "strncat_test!";
  char str2[20] = "strncat_test";
  ck_assert_int_eq(s21_strncmp(str1, str2, 10), strncmp(str1, str2, 10));
}


// TESTS FOR STRNCPY
START_TEST(strncpy_test1) {
  char src[20] = "strncpy_test";
  char dest[20] = "";
  ck_assert_str_eq(s21_strncpy(dest, src, 11), strncpy(dest, src, 11));
}

START_TEST(strncpy_test2) {
  char src[20] = "strncpy_test";
  char dest[20] = "";
  ck_assert_str_eq(s21_strncpy(dest, src, 6), strncpy(dest, src, 6));
}

START_TEST(strncpy_test3) {
  char src[20] = "strncpy_test";
  char dest[20] = "";
  ck_assert_str_eq(s21_strncpy(dest, src, 0), strncpy(dest, src, 0));
}

START_TEST(strncpy_test4) {
  char src[20] = "strncpy_test";
  char dest[20] = "";
  ck_assert_str_eq(s21_strncpy(dest, src, 20), strncpy(dest, src, 20));
}

START_TEST(strncpy_test5) {
  char src[20] = "";
  char dest[20] = "strncpy_test";
  ck_assert_str_eq(s21_strncpy(dest, src, 20), strncpy(dest, src, 20));
}

// TESTS FOR STRCSPN
START_TEST(strcspn_test1) {
  char str1[20] = "abcdefg";
  char str2[20] = "01234";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}

START_TEST(strcspn_test2) {
  char str1[20] = "abcdefg";
  char str2[20] = "c";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}

START_TEST(strcspn_test3) {
  char str1[20] = "abcdefg";
  char str2[20] = "bg";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}

START_TEST(strcspn_test4) {
  char str1[20] = "abcdefg";
  char str2[20] = "\0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}

START_TEST(strcspn_test5) {
  char str1[20] = "Testing strcspn\n";
  char str2[20] = "\n";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}

// TESTS FOR STRERROR!! 


// TESTS FOR STRLEN
START_TEST(strlen_test1) {
  char str[20] = "a";
  ck_assert_msg(s21_strlen(str) == strlen(str), "Fail test at 1");
}

START_TEST(strlen_test2) {
  char str[20] = "abcd abcd";
  ck_assert_msg(s21_strlen(str) == strlen(str), "Fail test at 9");
}

START_TEST(strlen_test3) {
  char str[20] = "";
  ck_assert_msg(s21_strlen(str) == strlen(str), "Fail test at 0");
}

START_TEST(strlen_test4) {
  char str[20] = "          ";
  ck_assert_msg(s21_strlen(str) == strlen(str), "Fail test at 10");
}

START_TEST(strlen_test5) {
  char str[20] = "\n\n\n\n\n\n\n\n\n\n";
  ck_assert_msg(s21_strlen(str) == strlen(str), "Fail test at 10");
}


// TESTS FOR STRPBRK
START_TEST(strpbrk_test1) {
  char str1[20] = "strpbrk_test1";
  char str2[20] = "0123";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}

START_TEST(strpbrk_test2) {
  char str1[20] = "strpbrk_test1";
  char str2[20] = "STR";
  ck_assert_msg(s21_strpbrk(str1, str2) == strpbrk(str1, str2), "Fail s21_strpbrk = (null)"); 
}

START_TEST(strpbrk_test3) {
  char str1[20] = "strpbrk\ntest1";
  char str2[20] = "0123\n";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}

START_TEST(strpbrk_test4) {
  char str1[20] = "strpbrk_test1";
  char str2[20] = "";
  ck_assert_msg(s21_strpbrk(str1, str2) == strpbrk(str1, str2), "Fail s21_strpbrk = (null)"); 
}

START_TEST(strpbrk_test5) {
  char str1[20] = "";
  char str2[20] = "0123\n";
  ck_assert_msg(s21_strpbrk(str1, str2) == strpbrk(str1, str2), "Fail s21_strpbrk = (null)"); 
}


// TESTS FOR STRRCHR
START_TEST(strrchr_test1) {
  char str[20] = "strrchr_test";
  ck_assert_str_eq(s21_strrchr(str, 's'), strrchr(str, 's'));
}

START_TEST(strrchr_test2) {
  char str[20] = "strrchr_test";
  ck_assert_str_eq(s21_strrchr(str, 'c'), strrchr(str, 'c'));
}

START_TEST(strrchr_test3) {
  char str[20] = "strrchr_test\n";
  ck_assert_str_eq(s21_strrchr(str, '\n'), strrchr(str, '\n'));
}

START_TEST(strrchr_test4) {
  char str[20] = "strrchr_test";
  ck_assert_str_eq(s21_strrchr(str, '\0'), strrchr(str, '\0'));
}

START_TEST(strrchr_test5) {
  char str[20] = "";
  ck_assert_str_eq(s21_strrchr(str, '\0'), strrchr(str, '\0'));
}


// TESTS FOR STRSTR
START_TEST(strstr_test1) {
  char haystack[20] = "strstr_test";
  char needle[20] = "str";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}

START_TEST(strstr_test2) {
  char haystack[20] = "strstr_test";
  char needle[20] = "_";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}

START_TEST(strstr_test3) {
  char haystack[20] = "";
  char needle[20] = "s";
  ck_assert_msg(s21_strstr(haystack, needle) == strstr(haystack, needle), "Fail s21_strstr == (null)");
}

START_TEST(strstr_test4) {
  char haystack[20] = "strstr_test";
  char needle[20] = "";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}

START_TEST(strstr_test5) {
  char haystack[20] = "strstr_test";
  char needle[20] = "lalala";
  ck_assert_msg(s21_strstr(haystack, needle) == strstr(haystack, needle), "Fail s21_strstr == (null)");
}


// TESTS FOR STRTOK
START_TEST(strtok_test1) {
  char str[20] = "strtok_test";
  char delim[20] = "_";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}

START_TEST(strtok_test2) {
  char str[20] = "strtok_test";
  char delim[20] = "tok";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}

START_TEST(strtok_test3) {
  char str[20] = "strtok_test";
  char delim[20] = "";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}

START_TEST(strtok_test4) {
  char str[20] = "";
  char delim[20] = "tok";
  ck_assert_msg(s21_strtok(str, delim) == strtok(str, delim), "Fail s21_strtok == (null)");
}

START_TEST(strtok_test5) {
  char str[20] = "strtok_test";
  char delim[20] = "strtok_test";
  ck_assert_msg(s21_strtok(str, delim) == strtok(str, delim), "Fail s21_strtok == (null)");
}



Suite *string_suite() {
  Suite *s1 = suite_create("STRING_TESTS");
  TCase *memchr_tests = tcase_create("MEMCHR");
  suite_add_tcase(s1, memchr_tests);
  tcase_add_test(memchr_tests, memchr_test1); // error 
  tcase_add_test(memchr_tests, memchr_test2);
  tcase_add_test(memchr_tests, memchr_test3);
  tcase_add_test(memchr_tests, memchr_test4); // error
  tcase_add_test(memchr_tests, memchr_test5);

  TCase *memcmp_tests = tcase_create("MEMCMP");
  suite_add_tcase(s1, memcmp_tests);
  tcase_add_test(memcmp_tests, memcmp_test1);
  tcase_add_test(memcmp_tests, memcmp_test2);
  tcase_add_test(memcmp_tests, memcmp_test3);
  tcase_add_test(memcmp_tests, memcmp_test4);
  tcase_add_test(memcmp_tests, memcmp_test5);

  TCase *memcpy_tests = tcase_create("MEMCPY");
  suite_add_tcase(s1, memcpy_tests);
  tcase_add_test(memcpy_tests, memcpy_test1);
  tcase_add_test(memcpy_tests, memcpy_test2);
  tcase_add_test(memcpy_tests, memcpy_test3);
  tcase_add_test(memcpy_tests, memcpy_test4);
  tcase_add_test(memcpy_tests, memcpy_test5);

  TCase *memset_tests = tcase_create("MEMSET");
  suite_add_tcase(s1, memset_tests);
  tcase_add_test(memset_tests, memset_test1);
  tcase_add_test(memset_tests, memset_test2);
  tcase_add_test(memset_tests, memset_test3);
  tcase_add_test(memset_tests, memset_test4);
  tcase_add_test(memset_tests, memset_test5);

  TCase *strncat_tests = tcase_create("STRNCAT");
  suite_add_tcase(s1, strncat_tests);
  tcase_add_test(strncat_tests, strncat_test1);
  tcase_add_test(strncat_tests, strncat_test2);
  tcase_add_test(strncat_tests, strncat_test3);
  tcase_add_test(strncat_tests, strncat_test4);
  tcase_add_test(strncat_tests, strncat_test5);

  TCase *strchr_tests = tcase_create("STRCHR");
  suite_add_tcase(s1, strchr_tests);
  tcase_add_test(strchr_tests, strchr_test1);
  tcase_add_test(strchr_tests, strchr_test2);
  tcase_add_test(strchr_tests, strchr_test3);
  tcase_add_test(strchr_tests, strchr_test4);
  tcase_add_test(strchr_tests, strchr_test5);

  TCase *strncmp_tests = tcase_create("STRNCMP");
  suite_add_tcase(s1, strncmp_tests);
  tcase_add_test(strncmp_tests, strncmp_test1);
  tcase_add_test(strncmp_tests, strncmp_test2);
  tcase_add_test(strncmp_tests, strncmp_test3);
  tcase_add_test(strncmp_tests, strncmp_test4);
  tcase_add_test(strncmp_tests, strncmp_test5);

  TCase *strncpy_tests = tcase_create("STRNCPY");
  suite_add_tcase(s1, strncpy_tests);
  tcase_add_test(strncpy_tests, strncpy_test1);
  tcase_add_test(strncpy_tests, strncpy_test2);
  tcase_add_test(strncpy_tests, strncpy_test3);
  tcase_add_test(strncpy_tests, strncpy_test4);
  tcase_add_test(strncpy_tests, strncpy_test5);

  TCase *strcspn_tests = tcase_create("STRCSPN");
  suite_add_tcase(s1, strcspn_tests);  
  tcase_add_test(strcspn_tests, strcspn_test1);
  tcase_add_test(strcspn_tests, strcspn_test2);
  tcase_add_test(strcspn_tests, strcspn_test3);
  tcase_add_test(strcspn_tests, strcspn_test4);
  tcase_add_test(strcspn_tests, strcspn_test5);

  TCase *strlen_tests = tcase_create("STRLEN");
  suite_add_tcase(s1, strlen_tests);
  tcase_add_test(strlen_tests, strlen_test1);
  tcase_add_test(strlen_tests, strlen_test2);
  tcase_add_test(strlen_tests, strlen_test3);
  tcase_add_test(strlen_tests, strlen_test4);
  tcase_add_test(strlen_tests, strlen_test5);

  // TCase *strerror_tests = tcase_create("STRERROR");
  // suite_add_tcase(s1, strerror_tests);

  TCase *strpbrk_tests = tcase_create("STRPBRK");
  suite_add_tcase(s1, strpbrk_tests);
  tcase_add_test(strpbrk_tests, strpbrk_test1);
  tcase_add_test(strpbrk_tests, strpbrk_test2); 
  tcase_add_test(strpbrk_tests, strpbrk_test3);
  tcase_add_test(strpbrk_tests, strpbrk_test4); 
  tcase_add_test(strpbrk_tests, strpbrk_test5); 

  TCase *strrchr_tests = tcase_create("STRRCHR");
  suite_add_tcase(s1, strrchr_tests);
  tcase_add_test(strrchr_tests, strrchr_test1);
  tcase_add_test(strrchr_tests, strrchr_test2);
  tcase_add_test(strrchr_tests, strrchr_test3);
  tcase_add_test(strrchr_tests, strrchr_test4);
  tcase_add_test(strrchr_tests, strrchr_test5);

  TCase *strstr_tests = tcase_create("STRSTR");
  suite_add_tcase(s1, strstr_tests);
  tcase_add_test(strstr_tests, strstr_test1);
  tcase_add_test(strstr_tests, strstr_test2);
  tcase_add_test(strstr_tests, strstr_test3); 
  tcase_add_test(strstr_tests, strstr_test4);
  tcase_add_test(strstr_tests, strstr_test5); 

  TCase *strtok_tests = tcase_create("STRTOK");
  suite_add_tcase(s1, strtok_tests);
  tcase_add_test(strtok_tests, strtok_test1);
  tcase_add_test(strtok_tests, strtok_test2);
  tcase_add_test(strtok_tests, strtok_test3);
  tcase_add_test(strtok_tests, strtok_test4); 
  tcase_add_test(strtok_tests, strtok_test5);

  return s1;
}

int main() {
  Suite *s1 = string_suite();

  SRunner *runner_string = srunner_create(s1);

  int number_fails;
  srunner_run_all(runner_string, CK_NORMAL);
  number_fails = srunner_ntests_failed(runner_string);
  srunner_free(runner_string);

  return number_fails == 0 ? 0 : 1;
}