#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include <string.h>

#include "s21_string.h"
#include "s21_sscanf.h"

// TESTS FOR MEMCHR
START_TEST(memchr_test1) {
  char str[20] = "memchr_test";
  ck_assert_mem_eq(s21_memchr(str, 'c', 20), memchr(str, 'c', 20), 20);
}
END_TEST

START_TEST(memchr_test2) {
  char str[20] = "memchr_test";
  ck_assert_msg(s21_memchr(str, 'C', 11) == s21_NULL, "Fail: s21_memchr == s21_NULL");
}
END_TEST

START_TEST(memchr_test3) {
  char str[30] = "memchr_test";
  ck_assert_msg(s21_memchr(str, 'F', 11) == s21_NULL, "Fail: s21_memchr == s21_NULL");
}
END_TEST

START_TEST(memchr_test4) {
  char str[20] = "memchr_test";
  ck_assert_mem_eq(s21_memchr(str, 'm', 20), memchr(str, 'm', 20), 20);
}
END_TEST

START_TEST(memchr_test5) {
  char str[20] = "memchr_test";
  ck_assert_mem_eq(s21_memchr(str, 'm', 0), memchr(str, 'm', 0), 0);
}
END_TEST


// TESTS FOR MEMCMP
START_TEST(memcmp_test1) {
  char str1[20] = "memcmp_test";
  char str2[20] = "memcmp_test";
  ck_assert_int_eq(s21_memcmp(str1, str2, 11), memcmp(str1, str2, 11));
}
END_TEST

START_TEST(memcmp_test2) {
  char str1[20] = "memcmp_test!!!";
  char str2[20] = "memcmp_test";
  ck_assert_int_eq(s21_memcmp(str1, str2, 11), memcmp(str1, str2, 11));
}
END_TEST

START_TEST(memcmp_test3) {
  char str1[20] = "memcmp_test";
  char str2[20] = "memcmp_test!!!";
  ck_assert_int_eq(s21_memcmp(str1, str2, 11), memcmp(str1, str2, 11));
}
END_TEST

START_TEST(memcmp_test4) {
  char str1[20] = "";
  char str2[20] = "";
  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
}
END_TEST

START_TEST(memcmp_test5) {
  char str1[20] = "\n\n\n\n\n";
  char str2[20] = "\n\n\n\n\n";
  ck_assert_int_eq(s21_memcmp(str1, str2, 5), memcmp(str1, str2, 5));
}
END_TEST


// TESTS FOR MEMCPY
START_TEST(memcpy_test1) {
  char src[20] = "memcpy_test";
  char dest[20] = "";
  ck_assert_str_eq(s21_memcpy(dest, src, 11), memcpy(dest, src, 11));
}
END_TEST

START_TEST(memcpy_test2) {
  char src[20] = "memcpy_test";
  char dest[20] = "";
  ck_assert_str_eq(s21_memcpy(dest, src, 6), memcpy(dest, src, 6));
}
END_TEST

START_TEST(memcpy_test3) {
  char src[20] = "memcpy_test";
  char dest[20] = "";
  ck_assert_str_eq(s21_memcpy(dest, src, 0), memcpy(dest, src, 0));
}
END_TEST

START_TEST(memcpy_test4) {
  char src[20] = "memcpy_test";
  char dest[20] = "";
  ck_assert_str_eq(s21_memcpy(dest, src, 20), memcpy(dest, src, 20));
}
END_TEST

START_TEST(memcpy_test5) {
  char src[20] = "memcpy_test";
  char dest[20] = "";
  ck_assert_str_eq(s21_memcpy(src, dest, 6), memcpy(src, dest, 6));
}
END_TEST

// TESTS FOR MEMSET
START_TEST(memset_test1) {
  char str[20] = "1234567890";
  ck_assert_str_eq(s21_memset(str, '1', 10), memset(str, '1', 10));
}
END_TEST

START_TEST(memset_test2) {
  char str[20] = "1234567890";
  ck_assert_str_eq(s21_memset(str, '1', 20), memset(str, '1', 20));
}
END_TEST

START_TEST(memset_test3) {
  char str[20] = "1234567890";
  ck_assert_str_eq(s21_memset(str, '\n', 10), memset(str, '\n', 10));
}
END_TEST

START_TEST(memset_test4) {
  char str[20] = "1234567890";
  ck_assert_str_eq(s21_memset(str, ' ', 10), memset(str, ' ', 10));
}
END_TEST

START_TEST(memset_test5) {
  char str[20] = "1234567890";
  ck_assert_str_eq(s21_memset(str, 'A', 10), memset(str, 'A', 10));
}
END_TEST


// TESTS FOR STRNCAT
START_TEST(strncat_test1) {
  char dest[20] = "strncat";
  char src[20] = "_test";
  ck_assert_str_eq(s21_strncat(dest, src, 5), strncat(dest, src, 5));
}
END_TEST

START_TEST(strncat_test2) {
  char dest[20] = "strncat";
  char src[20] = "_test";
  ck_assert_str_eq(s21_strncat(dest, src, 1), strncat(dest, src, 1));
}
END_TEST

START_TEST(strncat_test3) {
  char dest[20] = "strncat";
  char src[20] = "_test";
  ck_assert_str_eq(s21_strncat(dest, src, 0), strncat(dest, src, 0));
}
END_TEST

START_TEST(strncat_test4) {
  char dest[20] = "123456";
  char src[20] = "7890";
  ck_assert_str_eq(s21_strncat(dest, src, 4), strncat(dest, src, 4));
}
END_TEST

START_TEST(strncat_test5) {
  char dest[20] = "strncat_test";
  char src[20] = "\n";
  ck_assert_str_eq(s21_strncat(dest, src, 1), strncat(dest, src, 1));
}
END_TEST


// TESTS FOR STRCHR
START_TEST(strchr_test1) {
  char str[20] = "strchr_test";
  ck_assert_str_eq(s21_strchr(str, 's'), strchr(str, 's'));
}
END_TEST

START_TEST(strchr_test2) {
  char str[20] = "strchr_test";
  ck_assert_str_eq(s21_strchr(str, 'c'), strchr(str, 'c'));
}
END_TEST

START_TEST(strchr_test3) {
  char str[20] = "strchr_test\n";
  ck_assert_str_eq(s21_strchr(str, '\n'), strchr(str, '\n'));
}
END_TEST

START_TEST(strchr_test4) {
  char str[20] = "strchr_test";
  ck_assert_str_eq(s21_strchr(str, '\0'), strchr(str, '\0'));
}
END_TEST

START_TEST(strchr_test5) {
  char str[20] = "";
  ck_assert_str_eq(s21_strchr(str, '\0'), strchr(str, '\0'));
}
END_TEST


// TESTS FOR STRNCMP
START_TEST(strncmp_test1) {
  char str1[20] = "strncat_test";
  char str2[20] = "strncat_test";
  ck_assert_int_eq(s21_strncmp(str1, str2, 11), strncmp(str1, str2, 11));
}
END_TEST

START_TEST(strncmp_test2) {
  char str1[20] = "strncat_test!!!";
  char str2[20] = "strncat_test";
  ck_assert_int_eq(s21_strncmp(str1, str2, 20), strncmp(str1, str2, 20));
}
END_TEST

START_TEST(strncmp_test3) {
  char str1[20] = "strncat_test";
  char str2[20] = "strncat_test!!!";
  ck_assert_int_eq(s21_strncmp(str1, str2, 20), strncmp(str1, str2, 20));
}
END_TEST

START_TEST(strncmp_test4) {
  char str1[20] = "";
  char str2[20] = "";
  ck_assert_int_eq(s21_strncmp(str1, str2, 0), strncmp(str1, str2, 0));
}
END_TEST

START_TEST(strncmp_test5) {
  char str1[20] = "strncat_test!";
  char str2[20] = "strncat_test";
  ck_assert_int_eq(s21_strncmp(str1, str2, 10), strncmp(str1, str2, 10));
}
END_TEST


// TESTS FOR STRNCPY
START_TEST(strncpy_test1) {
  char src[20] = "strncpy_test";
  char dest[20] = "";
  ck_assert_str_eq(s21_strncpy(dest, src, 11), strncpy(dest, src, 11));
}
END_TEST

START_TEST(strncpy_test2) {
  char src[20] = "strncpy_test";
  char dest[20] = "";
  ck_assert_str_eq(s21_strncpy(dest, src, 6), strncpy(dest, src, 6));
}
END_TEST

START_TEST(strncpy_test3) {
  char src[20] = "strncpy_test";
  char dest[20] = "";
  ck_assert_str_eq(s21_strncpy(dest, src, 0), strncpy(dest, src, 0));
}
END_TEST

START_TEST(strncpy_test4) {
  char src[20] = "strncpy_test";
  char dest[20] = "";
  ck_assert_str_eq(s21_strncpy(dest, src, 20), strncpy(dest, src, 20));
}
END_TEST

START_TEST(strncpy_test5) {
  char src[20] = "";
  char dest[20] = "strncpy_test";
  ck_assert_str_eq(s21_strncpy(dest, src, 20), strncpy(dest, src, 20));
}
END_TEST


// TESTS FOR STRCSPN
START_TEST(strcspn_test1) {
  char str1[20] = "abcdefg";
  char str2[20] = "01234";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_test2) {
  char str1[20] = "abcdefg";
  char str2[20] = "c";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_test3) {
  char str1[20] = "abcdefg";
  char str2[20] = "bg";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_test4) {
  char str1[20] = "abcdefg";
  char str2[20] = "\0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_test5) {
  char str1[20] = "Testing strcspn\n";
  char str2[20] = "\n";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST


// TESTS FOR STRERROR
START_TEST(strerror_test1) {
  #if defined (__APPLE__)
  for (int i = 0; i < 107; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }

  #elif defined (__linux__)
    for (int i = 0; i < 133; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
  #endif
}
END_TEST


// TESTS FOR STRLEN
START_TEST(strlen_test1) {
  char str[20] = "a";
  ck_assert_msg(s21_strlen(str) == strlen(str), "Fail test at 1");
}
END_TEST

START_TEST(strlen_test2) {
  char str[20] = "abcd abcd";
  ck_assert_msg(s21_strlen(str) == strlen(str), "Fail test at 9");
}
END_TEST

START_TEST(strlen_test3) {
  char str[20] = "";
  ck_assert_msg(s21_strlen(str) == strlen(str), "Fail test at 0");
}
END_TEST

START_TEST(strlen_test4) {
  char str[20] = "          ";
  ck_assert_msg(s21_strlen(str) == strlen(str), "Fail test at 10");
}
END_TEST

START_TEST(strlen_test5) {
  char str[20] = "\n\n\n\n\n\n\n\n\n\n";
  ck_assert_msg(s21_strlen(str) == strlen(str), "Fail test at 10");
}
END_TEST


// TESTS FOR STRPBRK
START_TEST(strpbrk_test1) {
  char str1[20] = "strpbrk_test1";
  char str2[20] = "0123";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_test2) {
  char str1[20] = "strpbrk_test1";
  char str2[20] = "STR";
  ck_assert_msg(s21_strpbrk(str1, str2) == strpbrk(str1, str2), "Fail s21_strpbrk = (null)"); 
}
END_TEST

START_TEST(strpbrk_test3) {
  char str1[20] = "strpbrk\ntest1";
  char str2[20] = "0123\n";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_test4) {
  char str1[20] = "strpbrk_test1";
  char str2[20] = "";
  ck_assert_msg(s21_strpbrk(str1, str2) == strpbrk(str1, str2), "Fail s21_strpbrk = (null)"); 
}
END_TEST

START_TEST(strpbrk_test5) {
  char str1[20] = "";
  char str2[20] = "0123\n";
  ck_assert_msg(s21_strpbrk(str1, str2) == strpbrk(str1, str2), "Fail s21_strpbrk = (null)"); 
}
END_TEST


// TESTS FOR STRRCHR
START_TEST(strrchr_test1) {
  char str[20] = "strrchr_test";
  ck_assert_str_eq(s21_strrchr(str, 's'), strrchr(str, 's'));
}
END_TEST

START_TEST(strrchr_test2) {
  char str[20] = "strrchr_test";
  ck_assert_str_eq(s21_strrchr(str, 'c'), strrchr(str, 'c'));
}
END_TEST

START_TEST(strrchr_test3) {
  char str[20] = "strrchr_test\n";
  ck_assert_str_eq(s21_strrchr(str, '\n'), strrchr(str, '\n'));
}
END_TEST

START_TEST(strrchr_test4) {
  char str[20] = "strrchr_test";
  ck_assert_str_eq(s21_strrchr(str, '\0'), strrchr(str, '\0'));
}
END_TEST

START_TEST(strrchr_test5) {
  char str[20] = "";
  ck_assert_str_eq(s21_strrchr(str, '\0'), strrchr(str, '\0'));
}
END_TEST


// TESTS FOR STRSTR
START_TEST(strstr_test1) {
  char haystack[20] = "strstr_test";
  char needle[20] = "str";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_test2) {
  char haystack[20] = "strstr_test";
  char needle[20] = "_";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_test3) {
  char haystack[20] = "";
  char needle[20] = "s";
  ck_assert_msg(s21_strstr(haystack, needle) == strstr(haystack, needle), "Fail s21_strstr == (null)");
}
END_TEST

START_TEST(strstr_test4) {
  char haystack[20] = "strstr_test";
  char needle[20] = "";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_test5) {
  char haystack[20] = "strstr_test";
  char needle[20] = "lalala";
  ck_assert_msg(s21_strstr(haystack, needle) == strstr(haystack, needle), "Fail s21_strstr == (null)");
}
END_TEST


// TESTS FOR STRTOK
START_TEST(strtok_test1) {
  char str[20] = "strtok_test";
  char delim[20] = "_";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_test2) {
  char str[20] = "strtok_test";
  char delim[20] = "tok";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_test3) {
  char str[20] = "strtok_test";
  char delim[20] = "";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_test4) {
  char str[20] = "";
  char delim[20] = "tok";
  ck_assert_msg(s21_strtok(str, delim) == strtok(str, delim), "Fail s21_strtok == (null)");
}
END_TEST

START_TEST(strtok_test5) {
  char str[20] = "strtok_test";
  char delim[20] = "strtok_test";
  ck_assert_msg(s21_strtok(str, delim) == strtok(str, delim), "Fail s21_strtok == (null)");
}
END_TEST


// TESTS FOR TO_UPPER
START_TEST(to_upper_test1) {
 char str[20] = "to_upper_test";
 ck_assert_str_eq(s21_to_upper(str), "TO_UPPER_TEST");
}
END_TEST

START_TEST(to_upper_test2) {
  char str[20] = "123 aBc 456";
  ck_assert_str_eq(s21_to_upper(str), "123 ABC 456");
}
END_TEST

START_TEST(to_upper_test3) {
  char str[20] = "";
  ck_assert_str_eq(s21_to_upper(str), "");
}
END_TEST

START_TEST(to_upper_test4) {
  char str[20] = "\n\n\n";
  ck_assert_str_eq(s21_to_upper(str), "\n\n\n");
}
END_TEST

START_TEST(to_upper_test5) {
  char str[20] = "Hello, World!";
  ck_assert_str_eq(s21_to_upper(str), "HELLO, WORLD!");
}
END_TEST


// TESTS FOR TO_LOWER
START_TEST(to_lower_test1) {
 char str[20] = "TO_LOWER_TEST";
 ck_assert_str_eq(s21_to_lower(str), "to_lower_test");
}
END_TEST

START_TEST(to_lower_test2) {
  char str[20] = "123 AbC 456";
  ck_assert_str_eq(s21_to_lower(str), "123 abc 456");
}
END_TEST

START_TEST(to_lower_test3) {
  char str[20] = "";
  ck_assert_str_eq(s21_to_lower(str), "");
}
END_TEST

START_TEST(to_lower_test4) {
  char str[20] = "\n\n\n";
  ck_assert_str_eq(s21_to_lower(str), "\n\n\n");
}
END_TEST

START_TEST(to_lower_test5) {
  char str[20] = "Hello, World!";
  ck_assert_str_eq(s21_to_lower(str), "hello, world!");
}
END_TEST


// TESTS FOR INSERT
START_TEST(insert_test1) {
 char src[20] = "insert_test";
 ck_assert_str_eq(s21_insert(src, "test_", 0), "test_insert_test");
}
END_TEST

START_TEST(insert_test2) {
 char src[20] = "insert_test";
 ck_assert_str_eq(s21_insert(src, "1234", 1), "i1234nsert_test");
}
END_TEST

START_TEST(insert_test3) {
 char src[20] = "insert_test";
 ck_assert_str_eq(s21_insert(src, "1234", 11), "insert_test1234");
}
END_TEST

START_TEST(insert_test4) {
 char src[20] = "\n\n\n";
 ck_assert_str_eq(s21_insert(src, "1234", 2), "\n\n1234\n");
}
END_TEST

START_TEST(insert_test5) {
 char src[20] = "";
 ck_assert_msg(s21_insert(src, "1234", 2) == s21_NULL, "Fail s21_insert == NULL");
}
END_TEST


// TESTS FOR TRIM
START_TEST(trim_test1) {
 char src[20] = "123trim_456test789";
 char trim_char[20] = "123456789";
 ck_assert_str_eq(s21_trim(src, trim_char), "trim_456test"); 
}
END_TEST

START_TEST(trim_test2) {
 char src[20] = "   trim_test   ";
 char trim_char[20] = " 1234";
 ck_assert_str_eq(s21_trim(src, trim_char), "trim_test"); 
}
END_TEST

START_TEST(trim_test3) {
 char src[20] = "\n\n\ntrim_test*\n*\n\n";
 char trim_char[20] = "\n";
 ck_assert_str_eq(s21_trim(src, trim_char), "trim_test*\n*"); 
}
END_TEST

START_TEST(trim_test4) {
 char src[20] = "trim_test";
 char trim_char[20] = "trimes";
 ck_assert_str_eq(s21_trim(src, trim_char), "_"); 
}
END_TEST

START_TEST(trim_test5) {
 char src[20] = "trim_test***";
 char trim_char[20] = "*!=";
 ck_assert_str_eq(s21_trim(src, trim_char), "trim_test"); 
}
END_TEST


// TESTS FOR SSCANF
// SPECIFIER C
START_TEST(sscanf_c_test1) {
  char format[] = "%c";
  char str[] = "a b c d";
  char c1, c2;

  // int res1 = s21_sscanf(str, format, &c1);
  // int res2 = sscanf(str, format, &c2);

  s21_sscanf(str, format, &c1);
  sscanf(str, format, &c2);

  // ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

// SPECIFIER D
START_TEST(sscanf_d_test1) {
  char format[] = "%d";
  char str[] = "123";
  signed char d1, d2;

  s21_sscanf(str, format, &d1);
  sscanf(str, format, &d2);

  // int res1 = s21_sscanf(str, format, &d1);
  // int res2 = sscanf(str, format, &d2);
  // ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST


Suite *string_suite() {
  Suite *s1 = suite_create("STRING_TESTS");
  TCase *memchr_tests = tcase_create("MEMCHR");
  suite_add_tcase(s1, memchr_tests);
  tcase_add_test(memchr_tests, memchr_test1);
  tcase_add_test(memchr_tests, memchr_test2);
  tcase_add_test(memchr_tests, memchr_test3);
  tcase_add_test(memchr_tests, memchr_test4); 
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

  TCase *strerror_tests = tcase_create("STRERROR");
  suite_add_tcase(s1, strerror_tests);
  tcase_add_test(strerror_tests, strerror_test1);

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

Suite *string_sharp_suite() {
  Suite *s2 = suite_create("STRING_C#_TESTS");
  TCase *to_upper_tests = tcase_create("TO_UPPER");
  suite_add_tcase(s2, to_upper_tests);
  tcase_add_test(to_upper_tests, to_upper_test1);
  tcase_add_test(to_upper_tests, to_upper_test2);
  tcase_add_test(to_upper_tests, to_upper_test3);
  tcase_add_test(to_upper_tests, to_upper_test4);
  tcase_add_test(to_upper_tests, to_upper_test5);

  TCase *to_lower_tests = tcase_create("TO_LOWER");
  suite_add_tcase(s2, to_lower_tests);
  tcase_add_test(to_lower_tests, to_lower_test1);
  tcase_add_test(to_lower_tests, to_lower_test2);
  tcase_add_test(to_lower_tests, to_lower_test3);
  tcase_add_test(to_lower_tests, to_lower_test4);
  tcase_add_test(to_lower_tests, to_lower_test5);

  TCase *insert_tests = tcase_create("INSERT");
  suite_add_tcase(s2, insert_tests);
  tcase_add_test(insert_tests, insert_test1);
  tcase_add_test(insert_tests, insert_test2);
  tcase_add_test(insert_tests, insert_test3);
  tcase_add_test(insert_tests, insert_test4);
  tcase_add_test(insert_tests, insert_test5);

  TCase *trim_tests = tcase_create("TRIM");
  suite_add_tcase(s2, trim_tests);
  tcase_add_test(trim_tests, trim_test1);
  tcase_add_test(trim_tests, trim_test2);
  tcase_add_test(trim_tests, trim_test3);
  tcase_add_test(trim_tests, trim_test4);
  tcase_add_test(trim_tests, trim_test5);

  return s2;
}

/* 

~~~ Часть 3 ~~~
Ширина: (число) *
Длина: h l L

*/
Suite *sscanf_suite() {
  Suite *s3 = suite_create("SSCANF_TESTS");
  TCase *sscanf_c_tests = tcase_create("SPEC c (SSCANF)");
  suite_add_tcase(s3, sscanf_c_tests);
  tcase_add_test(sscanf_c_tests, sscanf_c_test1);

  TCase *sscanf_d_tests = tcase_create("SPEC d (SSCANF)");
  tcase_add_test(sscanf_d_tests, sscanf_d_test1);

  TCase *sscanf_i_tests = tcase_create("SPEC i (SSCANF)");

  TCase *sscanf_e_tests = tcase_create("SPEC e (SSCANF)");

  TCase *sscanf_E_tests = tcase_create("SPEC E (SSCANF)");

  TCase *sscanf_f_tests = tcase_create("SPEC f (SSCANF)");

  TCase *sscanf_g_tests = tcase_create("SPEC g (SSCANF)");

  TCase *sscanf_G_tests = tcase_create("SPEC G (SSCANF)");

  TCase *sscanf_o_tests = tcase_create("SPEC o (SSCANF)");

  TCase *sscanf_s_tests = tcase_create("SPEC s (SSCANF)");

  TCase *sscanf_u_tests = tcase_create("SPEC u (SSCANF)");

  TCase *sscanf_x_tests = tcase_create("SPEC x (SSCANF)");

  TCase *sscanf_X_tests = tcase_create("SPEC X (SSCANF)");

  TCase *sscanf_p_tests = tcase_create("SPEC p (SSCANF)");

  TCase *sscanf_n_tests = tcase_create("SPEC n (SSCANF)");

  return s3;
}


/* 

~~~ Часть 2 ~~~
Флаги: - + (пробел)
Ширина: (число)
Точность: .(число)
Длина: h l 

~~~ Дополнительно ~~~
Флаги: # 0
Ширина: *
Точность: .*
Длина: L 

*/
Suite *sprintf_suite() {
  Suite *s4 = suite_create("SPRINTF_TESTS");
  TCase *sprintf_c_tests = tcase_create("SPEC c (SPRINTF)"); // part 2
  suite_add_tcase(s4, sprintf_c_tests);

  TCase *sprintf_d_tests = tcase_create("SPEC d (SPRINTF)"); // part 2

  // TCase *sprintf_i_tests = tcase_create("SPEC i (SPRINTF)");

  TCase *sprintf_e_tests = tcase_create("SPEC e (SPRINTF)"); // dop

  TCase *sprintf_E_tests = tcase_create("SPEC E (SPRINTF)"); // dop

  TCase *sprintf_f_tests = tcase_create("SPEC f (SPRINTF)"); // part 2

  TCase *sprintf_g_tests = tcase_create("SPEC g (SPRINTF)"); // dop

  TCase *sprintf_G_tests = tcase_create("SPEC G (SPRINTF)"); // dop

  TCase *sprintf_o_tests = tcase_create("SPEC o (SPRINTF)"); // dop

  TCase *sprintf_s_tests = tcase_create("SPEC s (SPRINTF)"); // part 2

  TCase *sprintf_u_tests = tcase_create("SPEC u (SPRINTF)"); // part 2

  TCase *sprintf_x_tests = tcase_create("SPEC x (SPRINTF)"); // dop

  TCase *sprintf_X_tests = tcase_create("SPEC X (SPRINTF)"); // dop

  TCase *sprintf_p_tests = tcase_create("SPEC p (SPRINTF)"); // dop

  // TCase *sprintf_n_tests = tcase_create("SPEC n (SPRINTF)");

  return s4;
}


int main() {
  Suite *s1 = string_suite();
  Suite *s2 = string_sharp_suite();
  Suite *s3 = sscanf_suite();
  Suite *s4 = sprintf_suite();

  SRunner *runner_string = srunner_create(s1);
  SRunner *runner_c_sharp = srunner_create(s2);
  SRunner *runner_sscanf = srunner_create(s3);
  SRunner *runner_sprintf = srunner_create(s4);

  int number_fails;
  srunner_run_all(runner_string, CK_NORMAL);
  number_fails = srunner_ntests_failed(runner_string);
  srunner_free(runner_string);

  srunner_run_all(runner_c_sharp, CK_NORMAL);
  number_fails += srunner_ntests_failed(runner_c_sharp);
  srunner_free(runner_c_sharp);

  srunner_run_all(runner_sscanf, CK_NORMAL);
  number_fails += srunner_ntests_failed(runner_sscanf);
  srunner_free(runner_sscanf);

  srunner_run_all(runner_sprintf, CK_NORMAL);
  number_fails += srunner_ntests_failed(runner_sprintf);
  srunner_free(runner_sprintf);

  return number_fails == 0 ? 0 : 1;
}