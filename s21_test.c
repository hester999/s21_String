#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "extra.h"
#include "s21_sprintf.h"
#include "s21_sscanf.h"
#include "s21_string.h"

// TESTS FOR MEMCHR
START_TEST(memchr_test1) {
  char str[20] = "memchr_test";
  ck_assert_mem_eq(s21_memchr(str, 'c', 20), memchr(str, 'c', 20), 20);
}
END_TEST

START_TEST(memchr_test2) {
  char str[20] = "memchr_test";
  ck_assert_msg(s21_memchr(str, 'C', 11) == s21_NULL,
                "Fail: s21_memchr == s21_NULL");
}
END_TEST

START_TEST(memchr_test3) {
  char str[30] = "memchr_test";
  ck_assert_msg(s21_memchr(str, 'F', 11) == s21_NULL,
                "Fail: s21_memchr == s21_NULL");
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
  char str2[17] = "memcmp_test";
  ck_assert_int_eq(s21_memcmp(str1, str2, 20), memcmp(str1, str2, 20));
}
END_TEST

START_TEST(memcmp_test3) {
  char str1[17] = "memcmp_test";
  char str2[20] = "memcmp_test!!!";
  ck_assert_int_eq(s21_memcmp(str1, str2, 20), memcmp(str1, str2, 20));
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
#if defined(__APPLE__)
  for (int i = 0; i < 107; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }

#elif defined(__linux__)
  for (int i = 0; i < 133; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
#endif
}
END_TEST

START_TEST(strerror_test2) {
  int n = -1;
  ck_assert_str_eq(s21_strerror(n), strerror(n));
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
  ck_assert_msg(s21_strpbrk(str1, str2) == strpbrk(str1, str2),
                "Fail s21_strpbrk = (null)");
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
  ck_assert_msg(s21_strpbrk(str1, str2) == strpbrk(str1, str2),
                "Fail s21_strpbrk = (null)");
}
END_TEST

START_TEST(strpbrk_test5) {
  char str1[20] = "";
  char str2[20] = "0123\n";
  ck_assert_msg(s21_strpbrk(str1, str2) == strpbrk(str1, str2),
                "Fail s21_strpbrk = (null)");
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
  ck_assert_msg(s21_strstr(haystack, needle) == strstr(haystack, needle),
                "Fail s21_strstr == (null)");
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
  ck_assert_msg(s21_strstr(haystack, needle) == strstr(haystack, needle),
                "Fail s21_strstr == (null)");
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
  ck_assert_msg(s21_strtok(str, delim) == strtok(str, delim),
                "Fail s21_strtok == (null)");
}
END_TEST

START_TEST(strtok_test5) {
  char str[20] = "strtok_test";
  char delim[20] = "strtok_test";
  ck_assert_msg(s21_strtok(str, delim) == strtok(str, delim),
                "Fail s21_strtok == (null)");
}
END_TEST

START_TEST(strtok_test6) {
  char delim[20] = "strtok_test";
  ck_assert_msg(s21_strtok(s21_NULL, delim) == strtok(s21_NULL, delim),
                "Fail s21_strtok == (null)");
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
  ck_assert_msg(s21_insert(src, "1234", 2) == s21_NULL,
                "Fail s21_insert == NULL");
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

START_TEST(trim_test6) {
  char src[20] = "trim_test***";
  ck_assert_str_eq(s21_trim(src, s21_NULL), "trim_test***");
}
END_TEST

START_TEST(trim_test7) {
  char src[20] = "";
  char trim_char[1] = " ";

  ck_assert_str_eq(s21_trim(src, trim_char), "");
}
END_TEST

// TESTS FOR SSCANF
// SPECIFIER c
START_TEST(sscanf_c_test1) {
  char buf1[100] = {0}, buf2[100] = {0};

  ck_assert_int_eq(s21_sscanf("123", "%c", buf1), sscanf("123", "%c", buf2));
  ck_assert_int_eq(buf1[0], buf2[0]);
}
END_TEST

START_TEST(sscanf_c_test2) {
  char buf1[100] = {0}, buf2[100] = {0};

  ck_assert_int_eq(s21_sscanf("qwertyuiop", "%9c", buf1),
                   sscanf("qwertyuiop", "%9c", buf2));
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sscanf_c_test3) {
  char buf1[100] = {0}, buf2[100] = {0};

  s21_sscanf("qwe", "%2c", buf1);
  sscanf("qwe", "%2c", buf2);

  ck_assert_int_eq(s21_sscanf("qwe", "%2c", buf1), sscanf("qwe", "%2c", buf2));
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

// SPECIFIER d
START_TEST(sscanf_d_test1) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("123", "%d", &a), sscanf("123", "%d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_d_test2) {
  short sa = 0, sb = 0;

  ck_assert_int_eq(s21_sscanf("123456", "%hd", &sa),
                   sscanf("123456", "%hd", &sb));
  ck_assert_int_eq(sa, sb);
}

START_TEST(sscanf_d_test3) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("98765", "%3d", &a), sscanf("98765", "%3d", &b));
  ck_assert_int_eq(a, b);
}

START_TEST(sscanf_d_test4) {
  int a = 0, b = 0;
  short sa = 0, sb = 0;

  ck_assert_int_eq(s21_sscanf("98765", "%3hd%d", &sa, &a),
                   sscanf("98765", "%3hd%d", &sb, &b));
  ck_assert_int_eq(sa, sb);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_d_test5) {
  int a = 0, b = 0, c = 0, d = 0;

  ck_assert_int_eq(s21_sscanf("111%111", "%d%%%d", &a, &b),
                   sscanf("111%111", "%d%%%d", &c, &d));
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
}
END_TEST

START_TEST(sscanf_d_test6) {
  int a = 0, b = 0, c = 0, d = 0;

  ck_assert_int_eq(s21_sscanf("222%222", "%d %d", &a, &b),
                   sscanf("222%222", "%d %d", &c, &d));
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
}
END_TEST

START_TEST(sscanf_d_test7) {
  int a = 0, b = 0, c = 0, d = 0;

  s21_sscanf("333abcde333", "%dabcde%d", &a, &b);
  sscanf("333abcde333", "%dabcde%d", &c, &d);

  // ck_assert_int_eq(s21_sscanf("333abcde333", "%dabcde%d", &a, &b),
  //  sscanf("333abcde333", "%dabcde%d", &c, &d));
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
}
END_TEST

START_TEST(sscanf_d_test8) {
  int a = 0, b = 0, c = 0, d = 0;

  ck_assert_int_eq(s21_sscanf("44", "%1d %1d", &a, &b),
                   sscanf("44", "%1d %1d", &c, &d));
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
}
END_TEST

START_TEST(sscanf_d_test9) {
  int a = 0, b = 0, c = 0, d = 0;

  ck_assert_int_eq(s21_sscanf("4 4", "%d%d", &a, &b),
                   sscanf("4 4", "%d%d", &c, &d));
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
}
END_TEST

START_TEST(sscanf_d_test10) {
  ck_assert_int_eq(s21_sscanf(" ", "%%"), sscanf(" ", "%%"));
}
END_TEST

// empty string
START_TEST(sscanf_d_test11) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("", "%d", &a), sscanf("", "%d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

// strings with spaces
START_TEST(sscanf_d_test12) {
  int a = 0;
  int b = 0;

  s21_sscanf(" ", "%d", &a);
  sscanf(" ", "%d", &b);

  // ck_assert_int_eq(s21_sscanf(" ", "%d", &a), sscanf(" ", "%d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_d_test13) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("123123", "%*3d%d", &a),
                   sscanf("123123", "%*3d%d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_d_test14) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("123", "%a", &a), -1);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_d_test15) {
  short sa = 0, sb = 0, sc = 0, sd = 0;

  ck_assert_int_eq(s21_sscanf("123456123", "%6hd%hd", &sa, &sb),
                   sscanf("123456123", "%6hd%hd", &sc, &sd));
  ck_assert_int_eq(sa, sc);
  ck_assert_int_eq(sb, sd);
}
END_TEST

START_TEST(sscanf_d_test16) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("12345678901", "%d", &a),
                   sscanf("12345678901", "%d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_d_test17) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("-12345678901", "%d", &a),
                   sscanf("-12345678901", "%d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_d_test18) {
  long la = 0, lb = 0;

  ck_assert_int_eq(s21_sscanf("-12345678901", "%ld", &la),
                   sscanf("-12345678901", "%ld", &lb));
  ck_assert_int_eq(la, lb);
}
END_TEST

START_TEST(sscanf_d_test19) {
  long la = 0, lb = 0;

  ck_assert_int_eq(s21_sscanf("12345678901234567890", "%ld", &la),
                   sscanf("12345678901234567890", "%ld", &lb));
  ck_assert_int_eq(la, lb);
}
END_TEST

START_TEST(sscanf_d_test20) {
  long la = 0, lb = 0;

  ck_assert_int_eq(s21_sscanf("-12345678901234567890", "%ld", &la),
                   sscanf("-12345678901234567890", "%ld", &lb));
  ck_assert_int_eq(la, lb);
}
END_TEST

// переполнение на целый круг
START_TEST(sscanf_d_test21) {
  long la = 0, lb = 0, lc = 0, ld = 0;

  s21_sscanf("19223372036854775807", "%ld%ld", &la, &lb);
  sscanf("19223372036854775807", "%ld%ld", &lc, &ld);

  // ck_assert_int_eq(s21_sscanf("19223372036854775807", "%ld%ld", &la, &lb),
  //  sscanf("19223372036854775807", "%ld%ld", &lc, &ld));
  ck_assert_int_eq(la, lc);
  ck_assert_int_eq(lb, ld);
}
END_TEST

// понижение разряда при переполнении
START_TEST(sscanf_d_test22) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("12345678901234567890", "%d", &a),
                   sscanf("12345678901234567890", "%d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_d_test23) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("-12345678901234567890", "%d", &a),
                   sscanf("-12345678901234567890", "%d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

// long long
START_TEST(sscanf_d_test24) {
  long long lla = 0, llb = 0, llc = 0, lld = 0;

  s21_sscanf("123456789012345", "%lld", &lla);
  sscanf("123456789012345", "%lld", &llb);

  // ck_assert_int_eq(s21_sscanf("123456789012345", "%lld", &lla),
  //  sscanf("123456789012345", "%lld", &llb));
  ck_assert_int_eq(lla, llb);
}
END_TEST

START_TEST(sscanf_d_test25) {
  long long lla = 0, llb = 0, llc = 0, lld = 0;

  s21_sscanf("-123456789012345678901", "%21lld%lld", &lla, &llb);
  sscanf("-123456789012345678901", "%21lld%lld", &llc, &lld);

  // ck_assert_int_eq(
  // s21_sscanf("-123456789012345678901", "%21lld%lld", &lla, &llb),
  // sscanf("-123456789012345678901", "%21lld%lld", &llc, &lld));
  ck_assert_int_eq(lla, llc);
  ck_assert_int_eq(llb, lld);
}
END_TEST

START_TEST(sscanf_d_test26) {
  long long lla = 0, llb = 0;

  s21_sscanf("987654321", "%lld", &lla);
  sscanf("987654321", "%lld", &llb);

  // ck_assert_int_eq(s21_sscanf("987654321", "%lld", &lla),
  //  sscanf("987654321", "%lld", &llb));
  ck_assert_int_eq(lla, llb);
}
END_TEST

// without digit
START_TEST(sscanf_d_test27) {
  int a = 0, b = 0;

  s21_sscanf("abc", "%d", &a);
  sscanf("abc", "%d", &b);

  // ck_assert_int_eq(s21_sscanf("abc", "%d", &a), sscanf("abc", "%d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

// too big len
START_TEST(sscanf_d_test28) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("123", "%5d", &a), sscanf("123", "%5d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

// flag +
START_TEST(sscanf_d_test29) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("+321", "%d", &a), sscanf("+321", "%d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_d_test30) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("+98765", "%*5d%d", &a),
                   sscanf("+98765", "%*5d%d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

// SPECIFIER i
START_TEST(sscanf_i_test1) {
  unsigned int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("1234567890", "%i", &a),
                   sscanf("1234567890", "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_i_test2) {
  unsigned int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("01234567", "%i", &a),
                   sscanf("01234567", "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_i_test3) {
  unsigned int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("0x1234567890", "%i", &a),
                   sscanf("0x1234567890", "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_i_test4) {
  unsigned int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("-1234567890", "%i", &a),
                   sscanf("-1234567890", "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_i_test5) {
  unsigned int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("-01234567", "%i", &a),
                   sscanf("-01234567", "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_i_test6) {
  unsigned int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("-0x1234567890", "%i", &a),
                   sscanf("-0x1234567890", "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_i_test7) {
  unsigned int a = 0, b = 0;

  s21_sscanf("--1234567890", "%i", &a);
  sscanf("--1234567890", "%i", &b);

  // ck_assert_int_eq(s21_sscanf("--1234567890", "%i", &a),
  //  sscanf("--1234567890", "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_i_test8) {
  unsigned int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("123abcdef", "%i", &a),
                   sscanf("123abcdef", "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_i_test9) {
  unsigned int a = 0, b = 0;

  s21_sscanf("a123abcdef", "%i", &a);
  sscanf("a123abcdef", "%i", &b);

  // ck_assert_int_eq(s21_sscanf("a123abcdef", "%i", &a),
  //  sscanf("a123abcdef", "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_i_test10) {
  unsigned int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("+0xfaf", "%i", &a), sscanf("+0xfaf", "%i", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

// SPECIFIER e
START_TEST(sscanf_e_test1) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("3.14", "%e", &a), sscanf("3.14", "%e", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_e_test2) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("-123.456", "%e", &a),
                   sscanf("-123.456", "%e", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_e_test3) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("1.23e3", "%e", &a), sscanf("1.23e3", "%e", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_e_test4) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("  42.17", "%4e", &a),
                   sscanf("  42.17", "%4e", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_e_test5) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("3.14", "%Le", &a), sscanf("3.14", "%Le", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_e_test6) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("1234", "%e", &a), sscanf("1234", "%e", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_e_test7) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("1.23e-5", "%e", &a),
                   sscanf("1.23e-5", "%e", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_e_test8) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("  -42.17", "%8Le", &a),
                   sscanf("  -42.17", "%8Le", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_e_test9) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("3.14", "%Le", &a), sscanf("3.14", "%Le", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_e_test10) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("1234", "%Le", &a), sscanf("1234", "%Le", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

// nan
START_TEST(sscanf_e_test11) {
  float a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("nan", "%e", &a), sscanf("nan", "%e", &b));
  ck_assert_float_nan(a);
  ck_assert_float_nan(b);
}
END_TEST

START_TEST(sscanf_e_test12) {
  float a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("1.23e-4", "%e", &a),
                   sscanf("1.23e-4", "%e", &b));
  ck_assert_float_eq_tol(a, b, 0.000001);
}
END_TEST

START_TEST(sscanf_e_test13) {
  float a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("1.23e4", "%e", &a), sscanf("1.23e4", "%e", &b));
  ck_assert_float_eq_tol(a, b, 0.000001);
}
END_TEST

// SPECIFIER E
START_TEST(sscanf_E_test1) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("3.14", "%E", &a), sscanf("3.14", "%E", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_E_test2) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("-123.456", "%E", &a),
                   sscanf("-123.456", "%E", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_E_test3) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("1.23e3", "%E", &a), sscanf("1.23e3", "%E", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_E_test4) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("  42.17", "%4E", &a),
                   sscanf("  42.17", "%4E", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_E_test5) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("3.14", "%LE", &a), sscanf("3.14", "%LE", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_E_test6) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("1234", "%E", &a), sscanf("1234", "%E", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_E_test7) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("1.23e-5", "%E", &a),
                   sscanf("1.23e-5", "%E", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_E_test8) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("  -42.17", "%8LE", &a),
                   sscanf("  -42.17", "%8LE", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_E_test9) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("3.14", "%LE", &a), sscanf("3.14", "%LE", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_E_test10) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("1234", "%LE", &a), sscanf("1234", "%LE", &b));
  ck_assert_double_eq(a, b);
}
END_TEST
START_TEST(sscanf_E_test11) {
  float a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("-inf", "%E", &a), sscanf("-inf", "%E", &b));
  ck_assert(isinf(a));
  ck_assert(isinf(b));
}
END_TEST

START_TEST(sscanf_E_test12) {
  float a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("1.23E10", "%6E", &a),
                   sscanf("1.23E10", "%6E", &b));
  ck_assert_float_eq_tol(a, b, 0.000001);
}
END_TEST

// SPECIFIER f
START_TEST(sscanf_f_test1) {
  float a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("123.456", "%f", &a),
                   sscanf("123.456", "%f", &b));
  ck_assert_float_eq_tol(a, b, 0.000001);
}
END_TEST

START_TEST(sscanf_f_test2) {
  double da = 0, db = 0;

  ck_assert_int_eq(s21_sscanf("123.456", "%lf", &da),
                   sscanf("123.456", "%lf", &db));
  ck_assert_double_eq_tol(da, db, 0.000001);
}
END_TEST

START_TEST(sscanf_f_test3) {
  long double lda = 0, ldb = 0;

  ck_assert_int_eq(s21_sscanf("123.456", "%Lf", &lda),
                   sscanf("123.456", "%Lf", &ldb));
  ck_assert_ldouble_eq_tol(lda, ldb, 0.000001);
}
END_TEST

// empty string
START_TEST(sscanf_f_test4) {
  float a = 0, b = 0;

  s21_sscanf("", "%f", &a);
  sscanf("", "%f", &b);

  // ck_assert_int_eq(s21_sscanf("", "%f", &a), sscanf("", "%f", &b));
  ck_assert_float_eq_tol(a, b, 0.000001);
}
END_TEST

START_TEST(sscanf_f_test5) {
  float a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("123.456", "%6f", &a),
                   sscanf("123.456", "%6f", &b));
  ck_assert_float_eq_tol(a, b, 0.000001);
}
END_TEST

START_TEST(sscanf_f_test6) {
  float a = 0, b = 0;

  s21_sscanf(".", "%f", &a);
  sscanf(".", "%f", &b);

  // ck_assert_int_eq(s21_sscanf(".", "%f", &a), sscanf(".", "%f", &b));
  ck_assert_float_eq_tol(a, b, 0.000001);
}
END_TEST

START_TEST(sscanf_f_test7) {
  float a = 0, b = 0;

  s21_sscanf("abc", "%f", &a);
  sscanf("abc", "%f", &b);

  // ck_assert_int_eq(s21_sscanf("abc", "%f", &a), sscanf("abc", "%f", &b));
  ck_assert_float_eq_tol(a, b, 0.000001);
}
END_TEST

START_TEST(sscanf_f_test8) {
  float a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("123.", "%f", &a), sscanf("123.", "%f", &b));
  ck_assert_float_eq_tol(a, b, 0.000001);
}
END_TEST

START_TEST(sscanf_f_test9) {
  float a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf(".123", "%f", &a), sscanf(".123", "%f", &b));
  ck_assert_float_eq_tol(a, b, 0.000001);
}
END_TEST

START_TEST(sscanf_f_test10) {
  float a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("123.abc", "%f", &a),
                   sscanf("123.abc", "%f", &b));
  ck_assert_float_eq_tol(a, b, 0.000001);
}
END_TEST

START_TEST(sscanf_f_test11) {
  float a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("222", "%f", &a), sscanf("222", "%f", &b));
  ck_assert_float_eq_tol(a, b, 0.000001);
}
END_TEST

START_TEST(sscanf_f_test12) {
  float a = 0, b = 0, c = 0, d = 0;

  sscanf("3.13 32.14", "%2f %f", &a, &b);
  s21_sscanf("3.13 32.14", "%2f %f", &c, &d);

  ck_assert_float_eq_tol(a, c, 0.000001);
  ck_assert_float_eq_tol(b, d, 0.000001);
}
END_TEST

START_TEST(sscanf_f_test13) {
  float a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("123.456", "%10f", &a),
                   sscanf("123.456", "%10f", &b));
  ck_assert_float_eq_tol(a, b, 0.000001);
}
END_TEST

START_TEST(sscanf_f_test14) {
  float a = 0, b = 0;

  s21_sscanf("123.456", "%*f", &a);
  sscanf("123.456", "%*f", &b);

  // ck_assert_int_eq(s21_sscanf("123.456", "%*f", &a),
  //  sscanf("123.456", "%*f", &b));
  ck_assert_float_eq_tol(a, b, 0.000001);
}
END_TEST

// SPECIFIER g
START_TEST(sscanf_g_test1) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("3.14", "%g", &a), sscanf("3.14", "%g", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_g_test2) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("-123.456", "%g", &a),
                   sscanf("-123.456", "%g", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_g_test3) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("1.23e3", "%g", &a), sscanf("1.23e3", "%g", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_g_test4) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("  42.17", "%4g", &a),
                   sscanf("  42.17", "%4g", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_g_test5) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("3.14", "%Lg", &a), sscanf("3.14", "%Lg", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_g_test6) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("1234", "%g", &a), sscanf("1234", "%g", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_g_test7) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("1.23e-5", "%g", &a),
                   sscanf("1.23e-5", "%g", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_g_test8) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("  -42.17", "%8Lg", &a),
                   sscanf("  -42.17", "%8Lg", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_g_test9) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("3.14", "%Lg", &a), sscanf("3.14", "%Lg", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_g_test10) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("1234", "%Lg", &a), sscanf("1234", "%Lg", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_g_test11) {
  float a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("inf", "%g", &a), sscanf("inf", "%g", &b));
  ck_assert(isinf(a));
  ck_assert(isinf(b));
}
END_TEST

// SPECIFIER G
START_TEST(sscanf_G_test1) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("3.14", "%G", &a), sscanf("3.14", "%G", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_G_test2) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("-123.456", "%G", &a),
                   sscanf("-123.456", "%G", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_G_test3) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("1.23e3", "%G", &a), sscanf("1.23e3", "%G", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_G_test4) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("  42.17", "%4G", &a),
                   sscanf("  42.17", "%4G", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_G_test5) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("3.14", "%LG", &a), sscanf("3.14", "%LG", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_G_test6) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("1234", "%G", &a), sscanf("1234", "%G", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_G_test7) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("1.23e-5", "%G", &a),
                   sscanf("1.23e-5", "%G", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_G_test8) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("  -42.17", "%8LG", &a),
                   sscanf("  -42.17", "%8LG", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_G_test9) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("3.14", "%LG", &a), sscanf("3.14", "%LG", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_G_test10) {
  float a = 0.0, b = 0.0;

  ck_assert_int_eq(s21_sscanf("1234", "%LG", &a), sscanf("1234", "%LG", &b));
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(sscanf_G_test11) {
  float a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("inf", "%G", &a), sscanf("inf", "%G", &b));
  ck_assert(isinf(a));
  ck_assert(isinf(b));
}
END_TEST

// SPECIFIER o
START_TEST(sscanf_o_test1) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("01234567", "%o", &a),
                   sscanf("01234567", "%o", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_o_test2) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("21234567", "%o", &a),
                   sscanf("21234567", "%o", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_o_test3) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("-01234567", "%o", &a),
                   sscanf("-01234567", "%o", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_o_test4) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("0-1234567", "%o", &a),
                   sscanf("0-1234567", "%o", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_o_test5) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("+01234567", "%o", &a),
                   sscanf("+01234567", "%o", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

// SPECIFIER s
START_TEST(sscanf_s_test1) {
  char buf1[100] = {0}, buf2[100] = {0};

  ck_assert_int_eq(s21_sscanf("1234567890", "%s", buf1),
                   sscanf("1234567890", "%s", buf2));
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sscanf_s_test2) {
  char buf1[100] = {0}, buf2[100] = {0};

  ck_assert_int_eq(s21_sscanf("abcdefghk", "%5s", buf1),
                   sscanf("abcdefghk", "%5s", buf2));
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sscanf_s_test3) {
  char buf1[100] = {0}, buf2[100] = {0};

  s21_sscanf("", "%s", buf1), sscanf("", "%s", buf2);

  // ck_assert_int_eq(s21_sscanf("", "%s", buf1), sscanf("", "%s", buf2));
  ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(sscanf_s_test4) {
  char buf1[100] = {0}, buf2[100] = {0}, buf3[100] = {0}, buf4[100] = {0};

  ck_assert_int_eq(s21_sscanf("123 456", "%s %s", buf1, buf3),
                   sscanf("123 456", "%s %s", buf2, buf4));
  ck_assert_str_eq(buf1, buf2);
  ck_assert_str_eq(buf3, buf4);
}
END_TEST

// SPECIFIER u
START_TEST(sscanf_u_test1) {
  unsigned int a = 0, b = 0;

  s21_sscanf("1234567890", "%u", &a);
  sscanf("1234567890", "%u", &b);

  // ck_assert_int_eq(s21_sscanf("1234567890", "%u", &a),
  //  sscanf("1234567890", "%u", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_u_test2) {
  unsigned int a = 0, b = 0;

  s21_sscanf("12345678901", "%u", &a);
  sscanf("12345678901", "%u", &b);

  // ck_assert_int_eq(s21_sscanf("12345678901", "%u", &a),
  //  sscanf("12345678901", "%u", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_u_test3) {
  unsigned long long lla = 0, llb = 0;

  s21_sscanf("123456789012345678901", "%llu", &lla);
  sscanf("123456789012345678901", "%llu", &llb);

  // ck_assert_int_eq(s21_sscanf("123456789012345678901", "%llu", &lla),
  //  sscanf("123456789012345678901", "%llu", &llb));
  ck_assert_int_eq(lla, llb);
}
END_TEST

START_TEST(sscanf_u_test4) {
  unsigned long long lla = 0, llb = 0;

  s21_sscanf("12345678901234567890123", "%22llu", &lla);
  sscanf("12345678901234567890123", "%22llu", &llb);

  // ck_assert_int_eq(s21_sscanf("12345678901234567890123", "%22llu", &lla),
  //  sscanf("12345678901234567890123", "%22llu", &llb));
  ck_assert_int_eq(lla, llb);
}
END_TEST

START_TEST(sscanf_u_test5) {
  unsigned long la = 0, lb = 0;
  unsigned short sa = 0, sb = 0;

  s21_sscanf("1234567890", "%5hu%lu", &sa, &la);
  sscanf("1234567890", "%5hu%lu", &sb, &lb);

  // ck_assert_int_eq(s21_sscanf("1234567890", "%5hu%lu", &sa, &la),
  //  sscanf("1234567890", "%5hu%lu", &sb, &lb));
  ck_assert_int_eq(sa, sb);
  ck_assert_int_eq(la, lb);
}
END_TEST

START_TEST(sscanf_u_test6) {
  unsigned int a = 0, b = 0;

  s21_sscanf("123", "%5u", &a);
  sscanf("123", "%5u", &b);

  // ck_assert_int_eq(s21_sscanf("123", "%5u", &a), sscanf("123", "%5u", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_u_test7) {
  unsigned int a = 0, b = 0;

  s21_sscanf("-123", "%u", &a);
  sscanf("-123", "%u", &b);

  // ck_assert_int_eq(s21_sscanf("-123", "%u", &a), sscanf("-123", "%u", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

// SPECIFIER x
START_TEST(sscanf_x_test1) {
  int a = 0, b = 0;

  s21_sscanf("0x1234567890", "%x", &a);
  sscanf("0x1234567890", "%x", &b);

  // ck_assert_int_eq(s21_sscanf("0x1234567890", "%x", &a),
  //  sscanf("0x1234567890", "%x", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_x_test2) {
  int a = 0, b = 0;

  s21_sscanf("0X1234567890", "%x", &a);
  sscanf("0X1234567890", "%x", &b);

  // ck_assert_int_eq(s21_sscanf("0X1234567890", "%x", &a),
  //  sscanf("0X1234567890", "%x", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_x_test3) {
  int a = 0, b = 0;

  s21_sscanf("0x1234567890", "%x", &a);
  sscanf("0x1234567890", "%x", &b);

  // ck_assert_int_eq(s21_sscanf("0x1234567890", "%x", &a),
  //  sscanf("0x1234567890", "%x", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_x_test4) {
  int a = 0, b = 0;

  s21_sscanf("0X1234567890", "%x", &a);
  sscanf("0X1234567890", "%x", &b);

  // ck_assert_int_eq(s21_sscanf("0X1234567890", "%x", &a),
  //  sscanf("0X1234567890", "%x", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_x_test5) {
  int a = 0, b = 0;

  s21_sscanf("0x1aBcDeF", "%x", &a);
  sscanf("0x1AbCdEf", "%x", &b);

  // ck_assert_int_eq(s21_sscanf("0x1aBcDeF", "%x", &a),
  //  sscanf("0x1AbCdEf", "%x", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_x_test6) {
  int a = 0, b = 0;

  s21_sscanf("01aBcDeF", "%x", &a);
  sscanf("01AbCdEf", "%x", &b);

  // ck_assert_int_eq(s21_sscanf("01aBcDeF", "%x", &a),
  //  sscanf("01AbCdEf", "%x", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_x_test7) {
  int a = 0, b = 0;

  s21_sscanf("x1aBcDeF", "%x", &a);
  sscanf("x1AbCdEf", "%x", &b);

  // ck_assert_int_eq(s21_sscanf("x1aBcDeF", "%x", &a),
  //  sscanf("x1AbCdEf", "%x", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_x_test8) {
  int a = 0, b = 0;

  s21_sscanf("+0x1aBcDeF", "%x", &a);
  sscanf("+0x1AbCdEf", "%x", &b);

  // ck_assert_int_eq(s21_sscanf("+0x1aBcDeF", "%x", &a),
  //  sscanf("+0x1AbCdEf", "%x", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_x_test9) {
  int a = 0, b = 0;

  s21_sscanf("-0x1aBcDeF", "%x", &a);
  sscanf("-0x1AbCdEf", "%x", &b);

  // ck_assert_int_eq(s21_sscanf("-0x1aBcDeF", "%x", &a),
  //  sscanf("-0x1AbCdEf", "%x", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

// SPECIFIER X
START_TEST(sscanf_X_test1) {
  int a = 0, b = 0;

  s21_sscanf("0x1abcdef", "%X", &a);
  sscanf("0x1abcdef", "%X", &b);

  // ck_assert_int_eq(s21_sscanf("0x1abcdef", "%X", &a),
  //  sscanf("0x1abcdef", "%X", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_X_test2) {
  int a = 0, b = 0;

  s21_sscanf("0x1abcdef", "%X", &a);
  sscanf("0x1abcdef", "%X", &b);

  // ck_assert_int_eq(s21_sscanf("0x1abcdef", "%X", &a),
  //  sscanf("0x1abcdef", "%X", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_X_test3) {
  int a = 0, b = 0;

  s21_sscanf("0X1ACDEF", "%X", &a);
  sscanf("0X1ACDEF", "%X", &b);

  // ck_assert_int_eq(s21_sscanf("0X1ACDEF", "%X", &a),
  //  sscanf("0X1ACDEF", "%X", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_X_test4) {
  int a = 0, b = 0;

  s21_sscanf("01aBcDeF", "%X", &a);
  sscanf("01AbCdEf", "%X", &b);

  // ck_assert_int_eq(s21_sscanf("01aBcDeF", "%X", &a),
  //  sscanf("01AbCdEf", "%X", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

// SPECIFIER p
START_TEST(sscanf_p_test1) {
  void *a = NULL, *b = NULL;

  ck_assert_int_eq(s21_sscanf("0x1234567890", "%p", &a),
                   sscanf("0x1234567890", "%p", &b));
  ck_assert_ptr_eq(a, b);
}
END_TEST

START_TEST(sscanf_p_test2) {
  void *a = NULL, *b = NULL;

  ck_assert_int_eq(s21_sscanf("0xabc", "%p", &a), sscanf("0xabc", "%p", &b));
  ck_assert_ptr_eq(a, b);
}
END_TEST

START_TEST(sscanf_p_test3) {
  void *a = NULL, *b = NULL;

  ck_assert_int_eq(s21_sscanf("1234567890", "%p", &a),
                   sscanf("1234567890", "%p", &b));
  ck_assert_ptr_eq(a, b);
}
END_TEST

START_TEST(sscanf_p_test4) {
  void *a = NULL, *b = NULL;

  ck_assert_int_eq(s21_sscanf("-1234567890", "%p", &a),
                   sscanf("-1234567890", "%p", &b));
  ck_assert_ptr_eq(a, b);
}
END_TEST

// SPECIFIER n
START_TEST(sscanf_n_test1) {
  char buf1[100] = {0}, buf2[100] = {0};
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("1234567890", "%5s%n", buf1, &a),
                   sscanf("1234567890", "%5s%n", buf2, &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_n_test2) {
  char buf1[100] = {0}, buf2[100] = {0};
  int a = 0, b = 0;

  s21_sscanf("", "%s%n", buf1, &a);
  sscanf("", "%s%n", buf2, &b);

  // ck_assert_int_eq(s21_sscanf("", "%s%n", buf1, &a),
  //  sscanf("", "%s%n", buf2, &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_n_test3) {
  char buf1[100] = {0}, buf2[100] = {0};
  int a = 0, b = 0, i = 0, j = 0;

  ck_assert_int_eq(s21_sscanf("123456", "%*3d%d%n", &i, &a),
                   sscanf("123456", "%*3d%d%n", &j, &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_percent_test1) {
  int a = 0, b = 0;

  s21_sscanf("42%%", "%%d", &a);
  sscanf("42%%", "%%d", &b);

  // ck_assert_int_eq(s21_sscanf("42%%", "%%d", &a),
  //  sscanf("42%%", "%%d", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

// TESTS FOR SPRINTF
// SPECIFIER c
START_TEST(sprintf_c_test1) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %c %c %c %c %c";
  char a = 'a', b = 'b', c = 'c', d = 'd', e = '\n';

  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_test2) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %c %c %c %c %c";
  int a = 9, b = 54, c = 61, d = 65, e = 126;

  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_test3) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %c %c %c %c %c";
  int a = -9, b = -54, c = -61, d = -65, e = -126;

  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_test4) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %c";
  int a = 0;

  sprintf(str1, str3, a);
  s21_sprintf(str2, str3, a);

  // ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_test5) {
  char str1[100];
  char str2[100];
  char *str3 = "%-5c Test %+5c Test % 5c Test %05c Test";
  int a = 70;

  sprintf(str1, str3, a, a, a, a);
  s21_sprintf(str2, str3, a, a, a, a);

  // ck_assert_int_eq(sprintf(str1, str3, a, a, a, a), s21_sprintf(str2, str3,
  // a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_test6) {
  char str1[100];
  char str2[100];
  char *str3 = "%-5.5c Test %+5.5c Test % 5.5c Test %05.5c Test";
  int a = 70;

  sprintf(str1, str3, a, a, a, a);
  s21_sprintf(str2, str3, a, a, a, a);

  // ck_assert_int_eq(sprintf(str1, str3, a, a, a, a), s21_sprintf(str2, str3,
  // a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_test7) {
  char str1[100];
  char str2[100];
  char *str3 = "%lc Test %lc Test %lc Test %lc Test";
  int a = 70;

  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// SPECIFIER d
START_TEST(sprintf_d_test1) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "test test %d test";

  int a = 100;

  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_test2) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "test test %d test";

  int a = -100;

  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_test3) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "test test %5d test";

  int a = 100;

  sprintf(str1, str3, a);
  s21_sprintf(str2, str3, a);

  // ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_test4) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "test test %5d test";

  int a = -100;

  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_test5) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "test test %-5d test";

  int a = -100;

  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_test6) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "test test %+5d test %+5d";

  int a = -100, b = 100;

  ck_assert_int_eq(sprintf(str1, str3, a, b), s21_sprintf(str2, str3, a, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_test7) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "test test % 5d test % 5d";

  int a = -100, b = 100;

  sprintf(str1, str3, a, b);
  s21_sprintf(str2, str3, a, b);

  // ck_assert_int_eq(sprintf(str1, str3, a, b), s21_sprintf(str2, str3, a, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_test8) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "test test %05d test %05d";

  int a = -100, b = 100;

  ck_assert_int_eq(sprintf(str1, str3, a, b), s21_sprintf(str2, str3, a, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_test9) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "test test %5.5d test %5.5d";

  int a = -100, b = 100;

  ck_assert_int_eq(sprintf(str1, str3, a, b), s21_sprintf(str2, str3, a, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_test10) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "test test %*d test %-*d";

  int a = -100, b = 100;

  sprintf(str1, str3, 5, a, 10, b);
  s21_sprintf(str2, str3, 5, a, 10, b);

  // ck_assert_int_eq(sprintf(str1, str3, 5, a, 10, b), s21_sprintf(str2, str3,
  // 5, a, 10, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_test11) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "test test %.*d test %-*.d";

  int a = -100, b = 100;

  sprintf(str1, str3, 5, a, 10, b);
  s21_sprintf(str2, str3, 5, a, 10, b);

  // ck_assert_int_eq(sprintf(str1, str3, 5, a, 10, b), s21_sprintf(str2, str3,
  // 5, a, 10, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_test12) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "test test %ld test %ld";

  int a = 3088675747373646, b = -3088675747373646;

  ck_assert_int_eq(sprintf(str1, str3, a, b), s21_sprintf(str2, str3, a, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_test13) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "test test %hd test %hd";

  int a = 22000, b = -22000;

  ck_assert_int_eq(sprintf(str1, str3, a, b), s21_sprintf(str2, str3, a, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// SPECIFIER e
START_TEST(sprintf_e_test1) {
  char str1[100];
  char str2[100];
  char *str3 = "%e Test %5e Test %5.e";
  double num = -764231539.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_test2) {
  char str1[100];
  char str2[100];
  char *str3 = "%e\n%.e\n%4e\n%4.e\n%5.10e!";
  double num = -764231539.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_test3) {
  char str1[100];
  char str2[100];
  char *str3 = "%#e\n%#.e\n%#5.e\n%#.0e\n%#0.0e!";
  double num = -665695342471359.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_test4) {
  char str1[300];
  char str2[300];
  char *str3 = "New test: %020e\nSecond test: %020.e!";
  double num = -5921563224775967.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_test5) {
  char str1[300];
  char str2[300];
  char *str3 = "Third test: %010e\nForth test: %010.e!";
  double num = -5921563224775967.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_test6) {
  char str1[300];
  char str2[300];
  char *str3 = "Fifth test: %0.0e!";
  double num = -5921563224775967.;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_test7) {
  char str1[300];
  char str2[300];
  char *str3 = "New test: %020e\nSecond test: %020.e!";
  double num =
      -5921563224775977777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777776.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_test8) {
  char str1[300];
  char str2[300];
  char *str3 = "Third test: %010e\nForth test: %010.e\nFifth test: %0.0e!";
  double num =
      -5921563224775977777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777776.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_test9) {
  char str1[300];
  char str2[300];
  char *str3 = "New test: %020e\nSecond test: %020.5e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_test10) {
  char str1[300];
  char str2[300];
  char *str3 = "Third test: %020.4e\nForth test: %020.3e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// SPECIFIER E
START_TEST(sprintf_E_test1) {
  char str1[300];
  char str2[300];
  double num1 = -.89435776876;
  double num2 = -.00089435776876;
  double num3 = -0.000000089435776876;
  double num4 = -0000000000000.89435776876;
  char *str3 = "test: %.E!\ntest: %#E!\ntest: %#.E!\ntest: %0.E!\n";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2, num3, num4),
                   s21_sprintf(str2, str3, num1, num2, num3, num4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_E_test2) {
  char str1[300];
  char str2[300];
  double num1 = -.3529373967;
  double num2 = -.0003529373967;
  double num3 = -0.00000003529373967;
  char *str3 = "test: % 013.E\ntest: %#4.9E\ntest: %016.2E!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2, num3),
                   s21_sprintf(str2, str3, num1, num2, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_E_test3) {
  char str1[300];
  char str2[300];
  double num1 = -.3529373967;
  double num4 = -0000000000000.3529373967;
  char *str3 = "test: %20.E\ntest: %-20.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num4, num1),
                   s21_sprintf(str2, str3, num4, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_E_test4) {
  char str1[300];
  char str2[300];
  double num1 = .3529373967;
  double num2 = .0003529373967;
  double num3 = 0.00000003529373967;
  char *str3 = "test: % 30.1E\ntest: % 30.E\ntest: %030.0E!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2, num3),
                   s21_sprintf(str2, str3, num1, num2, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_E_test5) {
  char str1[300];
  char str2[300];
  double num1 = .3529373967;
  double num4 = 0000000000000.3529373967;
  char *str3 = "test: %066.E\ntest: %-20.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num4, num1),
                   s21_sprintf(str2, str3, num4, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_E_test6) {
  char str1[300];
  char str2[300];
  double num1 = 53296575676899283734747273752737878257.;
  char *str3 = "test: %- 17.1E\ntest: % -17.1E!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num1),
                   s21_sprintf(str2, str3, num1, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_E_test7) {
  char str1[300];
  char str2[300];
  double num2 = -53296575676899283734747273752737878257.;
  char *str3 = "test: %# 10.2E\ntest: % #10.0E\ntest: %010.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num2, num2, num2),
                   s21_sprintf(str2, str3, num2, num2, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_E_test8) {
  char str1[600];
  char str2[600];
  double num1 = 1234567890000.0938217586;
  char *str3 = "test: %- 67.1E\ntest: % -67.1E!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num1),
                   s21_sprintf(str2, str3, num1, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_E_test9) {
  char str1[600];
  char str2[600];
  double num2 = -.12345678900000938217586;
  char *str3 = "test: %# 100.0E\ntest: % #100.0E\ntest: %0100.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num2, num2, num2),
                   s21_sprintf(str2, str3, num2, num2, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_E_test10) {
  char str1[1000];
  char str2[1000];
  double num1 = 1234567890000.0938217586;
  double num2 = -.12345678900000938217586;
  char *str3 = "test: % 070.10E\ntest: % -67.10E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2),
                   s21_sprintf(str2, str3, num1, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// SPECIFIER f
START_TEST(sprintf_f_test1) {
  char str1[200];
  char str2[200];
  char *str3 = "%f TEST %f TEST %f TEST %f TEST %f!";
  double num = 76.756513;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_test2) {
  char str1[200];
  char str2[200];
  char *str3 = "%10f TEST %5f TEST %1f TEST %0f TEST %f!";
  double num = 76.756513;
  sprintf(str1, str3, num, num, num, num, num);
  s21_sprintf(str2, str3, num, num, num, num, num);
  // ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
  //  s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_test3) {
  char str1[400];
  char str2[400];
  char *str3 = "%-10f %f!";
  double num = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_test4) {
  char str1[200];
  char str2[200];
  char *str3 = "%10f TEST %5f TEST %1f TEST %0f TEST %f!";
  double num = 76.756513;
  double num1 = 76.756514;
  double num2 = 76.756511;
  double num3 = 76.956510;
  double num4 = 76.7565121;
  ck_assert_int_eq(sprintf(str1, str3, num, num1, num2, num3, num4),
                   s21_sprintf(str2, str3, num, num1, num2, num3, num4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_test5) {
  char str1[200];
  char str2[200];
  char *str3 = "%10f TEST %5f TEST %1f TEST %0f TEST %f!";
  float num = 76.756513;
  double num1 = 76.756514;
  double num2 = 76.756511;
  double num3 = 76.956510;
  float num4 = 76.7565121;
  ck_assert_int_eq(sprintf(str1, str3, num, num1, num2, num3, num4),
                   s21_sprintf(str2, str3, num, num1, num2, num3, num4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_test6) {
  char str1[200];
  char str2[200];
  char *str3 = "%-f TEST %-5f TEST %-1f TEST %-0f TEST %-f!";
  float num = 76.756513;
  double num1 = 76.756514;
  double num2 = 76.756511;
  double num3 = 76.956510;
  float num4 = 76.7565121;
  ck_assert_int_eq(sprintf(str1, str3, num, num1, num2, num3, num4),
                   s21_sprintf(str2, str3, num, num1, num2, num3, num4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_test7) {
  char str1[200];
  char str2[200];
  char *str3 = "%+f TEST %+5f TEST %+1f TEST %+0f TEST %+f!";
  double num = 76.756513;
  double num1 = 76.756514;
  double num2 = 76.756511;
  double num3 = 76.956510;
  float num4 = 76.7565121;
  ck_assert_int_eq(sprintf(str1, str3, num, num1, num2, num3, num4),
                   s21_sprintf(str2, str3, num, num1, num2, num3, num4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_test8) {
  char str1[200];
  char str2[200];
  char *str3 = "% f TEST % -5f TEST % +1f TEST % -0f TEST % -+0f!";
  double num = 76.756513;
  double num1 = 76.756514;
  double num2 = 76.756511;
  double num3 = 76.956510;
  float num4 = 76.7565121;
  ck_assert_int_eq(sprintf(str1, str3, num, num1, num2, num3, num4),
                   s21_sprintf(str2, str3, num, num1, num2, num3, num4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_test9) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %10.4f\ntest: %25.5f!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_test10) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+15.f\ntest: %+#16.f\ntest: %+#18.0f!";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_test11) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 18.0f\ntest: %+10.f\ntest: %+25.f!";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_test12) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-26.1f\ntest: %-18.0f\ntest: %#-10.f!";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_test13) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-#15.f\ntest: %-+25.f!";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_test14) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-15.4f!\ntest: %-26.1f!\ntest: %-18.0f!";
  double num = -365289.3462865487;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_test15) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %#-10.9f!\ntest: %-+25.15f!";
  double num = -365289.3462865487;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_test16) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13f!\ntest: %26.15f!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_test17) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7f!\ntest: %10.15f!\ntest: %25.15f!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_test18) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.5f!\ntest: %26.15f!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_test19) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7f!\ntest: %10.15f!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_test20) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %- 23.14f!\ntest: %+ 25.15f!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_test21) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15Lf!test: %100Lf!";
  long double num = -3752765839673496.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_test22) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %f!\n";
  double num = INFINITY;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_test23) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+f!\n";
  double num = INFINITY;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_f_test24) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %Lf!\n";
  long double num = -INFINITY;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// SPECIFIER g
START_TEST(sprintf_g_test1) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %g TEST %g TEST %g TEST %g!";
  double num = 76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_test2) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.4g!";
  double num = -76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_test3) {
  char str1[200];
  char str2[200];
  char *str3 = "%25.18g TEST\n%.6g TEST\n";
  double num = 838.65400000;
  double num1 = 640.783289182;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_test4) {
  char str1[200];
  char str2[200];
  char *str3 = "%.2g TEST\n%.3g TEST\n";
  double num = 838.65400000;
  double num1 = 640.783289182;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_test5) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %#5.10g!";
  double num = 0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_test6) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %#5.10g!";
  double num = -0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_test7) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  double num = 573429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_test8) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.0g TEST %4.2g TEST %4.g TEST %5.10g!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_test9) {
  char str1[200];
  char str2[200];
  char *str3 = "test: %15.1g\ntest: %16.2g\ntest: %18.3g!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_test10) {
  char str1[200];
  char str2[200];
  char *str3 = "test: %10.4g\ntest: %25.5g!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_test11) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-#15.g\ntest: %-26.1g\ntest: %-18.0g!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_test12) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %#-10.g\ntest: %-+25.g!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_test13) {
  char str1[200];
  char str2[200];
  char *str3 = "%6g TEST %.2g TEST %4.5g TEST %4.3g TEST %5.10g!";
  double num = -0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_test14) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  double num = 573429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_test15) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lg\n%.Lg!";
  long double num_long = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num_long, num_long),
                   s21_sprintf(str2, str3, num_long, num_long));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_test16) {
  char str1[400];
  char str2[400];
  char *str3 = "%20.10g\n%20.15g\n%-20.5g!";
  double num = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_test17) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lg\n%.Lg\n%+-#Lg\n%+#.Lg\n%-#.Lg!";
  long double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_test18) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %g!\n";
  double num = INFINITY;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_test19) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %Lg!\ntest: %Lg!\n";
  long double num = NAN;
  long double num1 = 1.;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// SPECIFIER G
START_TEST(sprintf_G_test1) {
  char str1[200];
  char str2[200];
  char *str3 = "%G TEST %G TEST %G TEST %G TEST %G!";
  double num = 76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_G_test2) {
  char str1[200];
  char str2[200];
  char *str3 = "%G TEST %.G TEST %4G TEST %4.G TEST %5.4G!";
  double num = -76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_G_test3) {
  char str1[200];
  char str2[200];
  char *str3 = "%25.18G TEST\n%.6G TEST\n";
  double num = 838.65400000;
  double num1 = 640.783289182;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_G_test4) {
  char str1[200];
  char str2[200];
  char *str3 = "%.2G TEST\n%.3G TEST\n";
  double num = 838.65400000;
  double num1 = 640.783289182;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_G_test5) {
  char str1[200];
  char str2[200];
  char *str3 = "%G TEST %.G TEST %4G TEST %4.G TEST %#5.10G!";
  double num = 0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_G_test6) {
  char str1[200];
  char str2[200];
  char *str3 = "%G TEST %.G TEST %4G TEST %4.G TEST %#5.10G!";
  double num = -0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_G_test7) {
  char str1[200];
  char str2[200];
  char *str3 = "%G TEST %.G TEST %4G TEST %4.G TEST %5.10G!";
  double num = 573429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_G_test8) {
  char str1[200];
  char str2[200];
  char *str3 = "%G TEST %.0G TEST %4.2G TEST %4.G TEST %5.10G!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_G_test9) {
  char str1[200];
  char str2[200];
  char *str3 = "test: %15.1G\ntest: %16.2G\ntest: %18.3G!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_G_test10) {
  char str1[200];
  char str2[200];
  char *str3 = "test: %10.4G\ntest: %25.5G!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_G_test11) {
  char str1[200];
  char str2[200];
  char *str3 = "%GLol %3.G";
  double a1 = 1.4567;
  ck_assert_int_eq(sprintf(str1, str3, a1, a1),
                   s21_sprintf(str2, str3, a1, a1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// SPECIFIER o
// One parameter octal
START_TEST(sprintf_o_test1) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %o Test";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three octal parameters
START_TEST(sprintf_o_test2) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Test %o Test %o";
  int val = 012;
  int val2 = 017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_o_test3) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Test %o Test %o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_o_test4) {
  char str1[100];
  char str2[100];
  char *str3 = "%lo Test %lo Test %ho GOD %ho";
  long int val = 3088675747373646;
  unsigned long int val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_o_test5) {
  char str1[100];
  char str2[100];
  char *str3 = "%3o Test %5o Test %10o";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_o_test6) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5o Test %.23o Test %3.o TEST %.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Minus flag
START_TEST(sprintf_o_test7) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5o Test %-.8o Test %-7o TEST %-.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zeroes
START_TEST(sprintf_o_test8) {
  char str1[200];
  char str2[200];
  char *str3 = "%0o Test %0.o Test %0.0o TEST %0o GOD %.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Pluses
START_TEST(sprintf_o_test9) {
  char str1[200];
  char str2[200];
  char *str3 = "%+o Test %+3.o Test %+5.7o TEST %+10o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // Zero vals
START_TEST(sprintf_o_test10) {
  char str1[200];
  char str2[200];
  char *str3 = "%o Test %3.o Test %5.7o TEST %10o %#o %-o %+o %.o % .o";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_o_test11) {
  char str1[200];
  char str2[200];
  char *str3 = "% o Test % 3.o Test % 5.7o TEST % 10o GOD %.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Plus
START_TEST(sprintf_o_test12) {
  char str1[200];
  char str2[200];
  char *str3 = "%+o Test %+3.o Test %+5.7o TEST %+10o GOD %+.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Hash
START_TEST(sprintf_o_test13) {
  char str1[200];
  char str2[200];
  char *str3 = "%#o Test %#3o Test %#5.7o TEST %#.7o Oof %#.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_o_test14) {
  char str1[200];
  char str2[200];
  char *str3 = "%0o Test %06o Test %05.7o TEST %0.7o Oof %0.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Asterisk
START_TEST(sprintf_o_test15) {
  char str1[200];
  char str2[200];
  char *str3 = "%*o Test %-*o Test %*.*o TEST %.*o";
  int val = 32;
  int val2 = 8899;
  int val3 = 919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// SPECIFIER s
START_TEST(sprintf_s_test1) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %s Test";
  char *val = "Here is a copy of the drawing!";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three string parameters
START_TEST(sprintf_s_test2) {
  char str1[100];
  char str2[100];
  char *str3 = "%s Test %s Test %s";
  char *val = "In the book it said:";
  char *val2 = "Boa constrictors swallow their prey whole";
  char *val3 = ", without chewing it.";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_s_test3) {
  char str1[100];
  char str2[100];
  char *str3 = "%s Test %s Test %s";
  char *val = "called True Stories from Nature";
  char *val2 = "about the primeval forest";
  char *val3 = "KEK";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // Different sizes WCHAR FOR LATER
START_TEST(sprintf_s_test4) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %ls Test2";
  wchar_t *val = L"3wtf80";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_s_test5) {
  char str1[200];
  char str2[200];
  char *str3 = "%3s Test %5s Test %10s";
  char *val = "After that they";
  char *val2 = "swallowing an animal";
  char *val3 = "KEK";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_s_test6) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5s Test %.23s Test %3.s TEST %.s";
  char *val = "AFTER THAT THEY";
  char *val2 = "are not able to move,";
  char *val3 = "BBOA";
  char *val4 = "and they sleep through the six months";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Minus flag
START_TEST(sprintf_s_test7) {
  char str1[200];
  char str2[200];
  char *str3 = "%-010s Test %-8s Test %-7s TEST %-s";
  char *val = "AFTER THAT THEY";
  char *val2 = "are not able to move,";
  char *val3 = "BBOA";
  char *val4 = "and they sleep through the six months";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zeroes
START_TEST(sprintf_s_test8) {
  char str1[200];
  char str2[200];
  char *str3 = "%0s Test %0s Test %00s TEST %-0s GOD %s";
  char *val = "AFTER THAT THEY";
  char *val2 = "are not able to move,";
  char *val3 = "BBOA";
  char *val4 = "and they sleep through the six months";
  char *val5 = "that they need for digestion!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Pluses
START_TEST(sprintf_s_test9) {
  char str1[200];
  char str2[200];
  char *str3 = "%+s Test %+3s Test %+5s TEST %10s";
  char *val = "AFTER THAT THEY";
  char *val2 = "are not able to move,";
  char *val3 = "BBOA";
  char *val4 = "and they sleep through the six months";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zero vals
START_TEST(sprintf_s_test10) {
  char str1[200];
  char str2[200];
  char *str3 = "%s Test %3.s Test %5.7s TEST %10s %#s %-s %+s %.s % .s";
  char *val = NULL;

  sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val);

  // ck_assert_int_eq(
  // sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
  // s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Plus
START_TEST(sprintf_s_test11) {
  char str1[200];
  char str2[200];
  char *str3 = "%+s Test %+3s Test %+05s TEST %+10s GOD %+s";
  char *val = "AFTER THAT THEY";
  char *val2 = "are not able to move,";
  char *val3 = "BBOA";
  char *val4 = "and they sleep through the six months";
  char *val5 = "that they need for digestion!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_s_test12) {
  char str1[200];
  char str2[200];
  char *str3 = "% s Test % 3s Test % -5s TEST % +10s GOD % +-0s";
  char *val = "AFTER THAT THEY";
  char *val2 = "are not able to move,";
  char *val3 = "BBOA";
  char *val4 = "and they sleep through the six months";
  char *val5 = "that they need for digestion!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // Hash
START_TEST(sprintf_s_test13) {
  char str1[200];
  char str2[200];
  char *str3 = "%#s Test %#3s Test %#5.7s TEST %#.7s Oof %#.s";
  char *val = "AFTER THAT THEY";
  char *val2 = "are not able to move,";
  char *val3 = "BBOA";
  char *val4 = "and they sleep through the six months";
  char *val5 = "that they need for digestion!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // ZERO flag
START_TEST(sprintf_s_test14) {
  char str1[200];
  char str2[200];
  char *str3 = "%0s Test %06s Test %05.7s TEST %0.7s Oof %0.s";
  char *val = "AFTER THAT THEY";
  char *val2 = "are not able to move,";
  char *val3 = "BBOA";
  char *val4 = "and they sleep through the six months";
  char *val5 = "that they need for digestion!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Asterisk
START_TEST(sprintf_s_test15) {
  char str1[200];
  char str2[200];
  char *str3 = "%*s Test %-*s Test %*.*s TEST %.*s";
  char *val = "AFTER THAT THEY";
  char *val2 = "are not able to move,";
  char *val3 = "BBOA";
  char *val4 = "and they sleep through the six months";
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_test16) {
  char str1[100];
  char str2[100];
  char *str3 = "%s %s %s %% %d";
  char *val = "This";
  char *val2 = "\0";
  int val3 = 65;
  char *val4 = "string";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val4, val3),
                   s21_sprintf(str2, str3, val, val2, val4, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_test17) {
  char str1[1024];
  char str2[1024];
  char *str3 =
      "%0.0s %1.0s %2.0s %3.0s %5.0s %6.0s %7.0s %0.3s %0.7s %3.2s %3.7s %7.3s";
  char *val = NULL;

  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val, val, val,
              val);
  sprintf(str1, str3, val, val, val, val, val, val, val, val, val, val, val,
          val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_test18) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %ls Test2";
  wchar_t *val = L"3wtf80";

  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);

  // ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_test19) {
  char str1[200];
  char str2[200];
  char *str3 = "% s Test %s Test %s Test %s";
  char *c = "";
  char *c1 = "\n";
  char *c2 = "\t";
  char *c3 = "\0";

  ck_assert_int_eq(sprintf(str1, str3, c, c1, c2, c3),
                   s21_sprintf(str2, str3, c, c1, c2, c3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_test20) {
  char str1[200];
  char str2[200];
  char *str3 = "% s Test % 3.s Test % 5.7s TEST % 10s GOD %.s";
  char *val = "AFTER THAT THEY";
  char *val2 = "are not able to move,";
  char *val3 = "BBOA";
  char *val4 = "and they sleep through the six months";
  char *val5 = "that they need for digestion!";

  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_test21) {
  char str1[200];
  char str2[200];
  char *str3 = "%.*s Test %*.s Test";
  char *val = "97";
  char *val2 = "97";
  int ast = -10;
  int ast2 = -10;

  sprintf(str1, str3, ast, val, ast2, val2);
  s21_sprintf(str2, str3, ast, val, ast2, val2);

  // ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
  //  s21_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_s_test22) {
  char str1[200];
  char str2[200];
  char *str3 = "%.*s Test %*.s Test";
  char *val = "97";
  char *val2 = "97";
  int ast = -10;
  int ast2 = -10;

  sprintf(str1, str3, ast, val, ast2, val2);
  s21_sprintf(str2, str3, ast, val, ast2, val2);

  // ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2),
  //  s21_sprintf(str2, str3, ast, val, ast2, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// SPECIFIER U
START_TEST(sprintf_u_test1) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %u Test";
  unsigned int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three unsigned parameters
START_TEST(sprintf_u_test2) {
  char str1[100];
  char str2[100];
  char *str3 = "%u Test %u Test %u";
  unsigned int val = 012;
  unsigned int val2 = 017;
  unsigned int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_u_test3) {
  char str1[100];
  char str2[100];
  char *str3 = "%u Test %u Test %u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_u_test4) {
  char str1[100];
  char str2[100];
  char *str3 = "%lu Test %lu Test %hu GOD %hu";
  long unsigned int val = 3088675747373646;
  long unsigned val2 = 33030030303;
  unsigned short val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_u_test5) {
  char str1[100];
  char str2[100];
  char *str3 = "%3u Test %5u Test %10u";
  unsigned int val = 3015;
  unsigned int val2 = 01234;
  unsigned int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // Different precision and width
START_TEST(sprintf_u_test6) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5u Test %.23u Test %3.u TEST %.u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Minus flag
START_TEST(sprintf_u_test7) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10u Test %-8u Test %-7u TEST %-u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zerues
START_TEST(sprintf_u_test8) {
  char str1[200];
  char str2[200];
  char *str3 = "%0u Test %0u Test %00u TEST %0u GOD %5u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  unsigned int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Pluses
START_TEST(sprintf_u_test9) {
  char str1[200];
  char str2[200];
  char *str3 = "%+u Test %+3u Test %+5u TEST %+010u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // Zeru vals
START_TEST(sprintf_u_test10) {
  char str1[200];
  char str2[200];
  char *str3 = "%u Test %3.u Test %5.7u TEST %10u %#u %-u %+u %.u % .u";
  unsigned int val = 0;
  sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val);
  // ck_assert_int_eq(
  // sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
  // s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Plus
START_TEST(sprintf_u_test11) {
  char str1[200];
  char str2[200];
  char *str3 = "%+u Test %+3u Test %+05u TEST %+10u GOD %+u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_u_test12) {
  char str1[200];
  char str2[200];
  char *str3 = "% u Test % 3u Test % 0u TEST % -10u GOD % +-0u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 23;

  sprintf(str1, str3, val, val2, val3, val4, val5);
  s21_sprintf(str2, str3, val, val2, val3, val4, val5);

  // ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
  //  s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // Hash
START_TEST(sprintf_u_test13) {
  char str1[200];
  char str2[200];
  char *str3 = "%#u Test %#3u Test %#5.7u TEST %#.7u Ouf %#.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_u_test14) {
  char str1[200];
  char str2[200];
  char *str3 = "%0u Test %06u Test %05u TEST %07u Ouf %0u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Asterisk
START_TEST(sprintf_u_test15) {
  char str1[200];
  char str2[200];
  char *str3 = "%*u Test %-*u Test %*.*u TEST %.*u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 919;
  unsigned int val4 = 32311;
  unsigned int ast = 2;
  unsigned int ast2 = 5;
  unsigned int ast3 = 4;
  unsigned int ast4 = 10;
  unsigned int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_test16) {
  char str1[200];
  char str2[200];
  char *str3 = "fdsdsds %lu";
  unsigned long int val = ULONG_MAX;

  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);

  // ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_test17) {
  char str1[200];
  char str2[200];
  char *str3 = "%- u Test %- 15u sdasda %- 15u sdsad %- u";
  unsigned int val = -3231;
  unsigned int val2 = -3231;
  unsigned int val3 = 3231;
  unsigned int val4 = 3231;

  sprintf(str1, str3, val, val2, val3, val4);
  s21_sprintf(str2, str3, val, val2, val3, val4);

  // ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
  //  s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_test18) {
  char str1[200];
  char str2[200];
  char *str3 = "%2u %10u %15u %7u %5u %7u %5u %7u";
  int val = 1;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_test19) {
  char str1[200];
  char str2[200];
  char *str3 = "%02u %010u %015u %07u %05u %07u %05u %07u";
  int val = 0;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_u_test20) {
  char str1[200];
  char str2[200];
  char *str3 = "%0+2u %0+10u %0+15u %0+7u %0+5u %0+7u %0+5u %0+7u";
  int val = 1;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// SPECIFIER x
// One parameter hex
START_TEST(sprintf_x_test1) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %x Test";
  int val = 0x32;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three hex parameters
START_TEST(sprintf_x_test2) {
  char str1[100];
  char str2[100];
  char *str3 = "%x Test %x Test %x";
  int val = 0x7a4;
  int val2 = 0x91ba123f;
  int val3 = 0x3123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_x_test3) {
  char str1[100];
  char str2[100];
  char *str3 = "%x Test %x Test %x";
  int val = 0x3015;
  int val2 = 0x712;
  int val3 = 0x99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_x_test4) {
  char str1[100];
  char str2[100];
  char *str3 = "%lx Test %lx Test %hx GOD %hx";
  long int val = 3088675747373646;
  long val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_x_test5) {
  char str1[100];
  char str2[100];
  char *str3 = "%3x Test %5x Test %10x";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // Different precision and width
START_TEST(sprintf_x_test6) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5x Test %.23x Test %3.x TEST %.x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Minus flag
START_TEST(sprintf_x_test7) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5x Test %-.8x Test %-7x TEST %-.x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zeroes
START_TEST(sprintf_x_test8) {
  char str1[200];
  char str2[200];
  char *str3 = "%0x Test %0.x Test %0.0x TEST %0x GOD %.x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Pluses
START_TEST(sprintf_x_test9) {
  char str1[200];
  char str2[200];
  char *str3 = "%+x Test %+3.x Test %+5.7x TEST %+10x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zero vals
START_TEST(sprintf_x_test10) {
  char str1[200];
  char str2[200];
  char *str3 = "%x Test %3.x Test %5.7x TEST %10x %#x %-x %+x %.x % .x";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_x_test11) {
  char str1[200];
  char str2[200];
  char *str3 = "% x Test % 3.x Test % 5.7x TEST % 10x GOD %.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Plus
START_TEST(sprintf_x_test12) {
  char str1[200];
  char str2[200];
  char *str3 = "%+x Test %+3.x Test %+5.7x TEST %+10x GOD %+.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // Hash
START_TEST(sprintf_x_test13) {
  char str1[200];
  char str2[200];
  char *str3 = "%#x Test %#3x Test %#5.7x TEST %#.7x Oof %#.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_x_test14) {
  char str1[200];
  char str2[200];
  char *str3 = "%0x Test %06x Test %05.7x TEST %0.7x Oof %0.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Asterisk
START_TEST(sprintf_x_test15) {
  char str1[200];
  char str2[200];
  char *str3 = "%*x Test %-*x Test %*.*x TEST %.*x";
  int val = 32;
  int val2 = 8899;
  int val3 = 919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_test16) {
  char str1[200];
  char str2[200];
  char *str3 = "%- x Test %- 15x sdasda %- 15x sdsad %- x";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_test17) {
  char str1[200];
  char str2[200];
  char *str3 = "fdsdsds %lx";
  long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_test18) {
  char str1[200];
  char str2[200];
  char *str3 = "%2x %10x %15x %7x %5x %7x %5x %7x";
  int val = 1;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_test19) {
  char str1[200];
  char str2[200];
  char *str3 = "%02x %010x %015x %07x %05x %07x %05x %07x";
  int val = 0;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x_test20) {
  char str1[200];
  char str2[200];
  char *str3 = "%0+2x %0+10x %0+15x %0+7x %0+5x %0+7x %0+5x %0+7x";
  int val = 1;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// SPECIFIER X
START_TEST(sprintf_X_test1) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %X Test";
  int val = 0X32;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three HEX parameters
START_TEST(sprintf_X_test2) {
  char str1[100];
  char str2[100];
  char *str3 = "%X Test %X Test %X";
  int val = 0X7a4;
  int val2 = 0X9112312f;
  int val3 = 0X3123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_X_test3) {
  char str1[100];
  char str2[100];
  char *str3 = "%X Test %X Test %X";
  int val = 0X3015;
  int val2 = 0X712;
  int val3 = 0X99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_X_test4) {
  char str1[100];
  char str2[100];
  char *str3 = "%lX Test %lX Test %hX GOD %hX";
  unsigned long int val = 3088675747373646;
  unsigned long int val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_X_test5) {
  char str1[100];
  char str2[100];
  char *str3 = "%3X Test %5X Test %10X";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_X_test6) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5X Test %.23X Test %3.X TEST %.X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Minus flag
START_TEST(sprintf_X_test7) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5X Test %-.8X Test %-7X TEST %-.X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zeroes
START_TEST(sprintf_X_test8) {
  char str1[200];
  char str2[200];
  char *str3 = "%0X Test %0.X Test %0.0X TEST %0X GOD %.X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Pluses
START_TEST(sprintf_X_test9) {
  char str1[200];
  char str2[200];
  char *str3 = "%+X Test %+3.X Test %+5.7X TEST %+10X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zero vals
START_TEST(sprintf_X_test10) {
  char str1[200];
  char str2[200];
  char *str3 = "%X Test %3.X Test %5.7X TEST %10X %#X %-X %+X %.X % .X";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_X_test11) {
  char str1[200];
  char str2[200];
  char *str3 = "% X Test % 3.X Test % 5.7X TEST % 10X GOD %.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Plus
START_TEST(sprintf_X_test12) {
  char str1[200];
  char str2[200];
  char *str3 = "%+X Test %+3.X Test %+5.7X TEST %+10X GOD %+.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // Hash
START_TEST(sprintf_X_test13) {
  char str1[200];
  char str2[200];
  char *str3 = "%#X Test %#3X Test %#5.7X TEST %#.7X Oof %#.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_X_test14) {
  char str1[200];
  char str2[200];
  char *str3 = "%0X Test %06X Test %05.7X TEST %0.7X Oof %0.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Asterisk
START_TEST(sprintf_X_test15) {
  char str1[200];
  char str2[200];
  char *str3 = "%*X Test %-*X Test %*.*X TEST %.*X";
  int val = 32;
  int val2 = 8899;
  int val3 = 919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_X_test16) {
  char str1[200];
  char str2[200];
  char *str3 = "%- X Test %- 15X sdasda %- 15X sdsad %- X";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_X_test17) {
  char str1[200];
  char str2[200];
  char *str3 = "%2X %10X %15X %7X %5X %7X %5X %7X";
  int val = 1;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_X_test18) {
  char str1[200];
  char str2[200];
  char *str3 = "%02X %010X %015X %07X %05X %07X %05X %07X";
  int val = 0;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_X_test19) {
  char str1[200];
  char str2[200];
  char *str3 = "%0+2X %0+10X %0+15X %0+7X %0+5X %0+7X %0+5X %0+7X";
  int val = 1;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}  // One parameter octal
START_TEST(sprintf_1_octal) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %o Test";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three octal parameters
START_TEST(sprintf_2_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Test %o Test %o";
  int val = 012;
  int val2 = 017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_3_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Test %o Test %o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_4_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%lo Test %lo Test %ho GOD %ho";
  long int val = 3088675747373646;
  unsigned long int val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_5_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%3o Test %5o Test %10o";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_6_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5o Test %.23o Test %3.o TEST %.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Minus flag
START_TEST(sprintf_7_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5o Test %-.8o Test %-7o TEST %-.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zeroes
START_TEST(sprintf_8_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%0o Test %0.o Test %0.0o TEST %0o GOD %.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Pluses
START_TEST(sprintf_9_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%+o Test %+3.o Test %+5.7o TEST %+10o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // Zero vals
START_TEST(sprintf_10_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%o Test %3.o Test %5.7o TEST %10o %#o %-o %+o %.o % .o";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_11_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "% o Test % 3.o Test % 5.7o TEST % 10o GOD %.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Plus
START_TEST(sprintf_12_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%+o Test %+3.o Test %+5.7o TEST %+10o GOD %+.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Hash
START_TEST(sprintf_13_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%#o Test %#3o Test %#5.7o TEST %#.7o Oof %#.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_14_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%0o Test %06o Test %05.7o TEST %0.7o Oof %0.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Asterisk
START_TEST(sprintf_15_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%*o Test %-*o Test %*.*o TEST %.*o";
  int val = 32;
  int val2 = 8899;
  int val3 = 919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
END_TEST

START_TEST(sprintf_X_test20) {
  char str1[200];
  char str2[200];
  char *str3 = "%0-2X %0-10X %0-15X %0-7X %0-5X %0-7X %0-5X %0-7X";
  int val = 1;
  int val2 = 10;
  int val3 = 100;
  int val4 = -1000;
  int val5 = -1000;
  int val6 = +1000;
  int val7 = +1000;
  int val8 = 1000;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val2, val3, val4, val5, val6, val7, val8),
      s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6, val7, val8));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// SPECIFIER p
START_TEST(sprintf_p_test1) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %p Test";
  char *val = "0p32";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three pointer parameters
START_TEST(sprintf_p_test2) {
  char str1[100];
  char str2[100];
  char *str3 = "%p Test %p Test %p";
  char *val = "0p7a4";
  char *val2 = "0p91ba123f";
  char *val3 = "0p3123";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_p_test3) {
  char str1[100];
  char str2[100];
  char *str3 = "%p Test %p Test %p";
  char *val = "0p3015";
  char *val2 = "0p712";
  char *val3 = "0p99";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_p_test4) {
  char str1[100];
  char str2[100];
  char *str3 = "%p Test %p Test %p GOD %p";
  long int *val = (void *)3088675747373646;
  long long int *val2 = (void *)33030030303;
  unsigned short int *val3 = (void *)22600;
  unsigned char *val4 = (void *)120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_p_test5) {
  char str1[100];
  char str2[100];
  char *str3 = "%3p Test %5p Test %12p";
  char *val = "3015";
  char *val2 = "01234";
  char *val3 = "99";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_p_test6) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5p Test %.23p Test %3.p TEST %.p";
  char *val = "3015";
  char *val2 = "712";
  char *val3 = "99";
  char *val4 = "38";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Minus flag
START_TEST(sprintf_p_test7) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5p Test %-.4p Test %-16p TEST %-.5p";
  char *val = "3015";
  char *val2 = "712";
  char *val3 = "99";
  char *val4 = "2939";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zeroes
START_TEST(sprintf_p_test8) {
  char str1[200];
  char str2[200];
  char *str3 = "%0p Test %0.p Test %0.0p TEST %0p GOD %.p";
  char *val = "3015";
  char *val2 = "712";
  char *val3 = "99";
  char *val4 = "2939";
  char *val5 = "0123";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Pluses
START_TEST(sprintf_p_test9) {
  char str1[200];
  char str2[200];
  char *str3 = "%+p Test %+3.p Test %+5.7p TEST %+10p";
  char *val = "3015";
  char *val2 = "712";
  char *val3 = "99";
  char *val4 = "2939";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zero vals
START_TEST(sprintf_p_test10) {
  char str1[200];
  char str2[200];
  char *str3 = "%p Test %3.p Test %5.7p TEST %10p %#p %-p %+p %.p % .p";
  char *val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_p_test11) {
  char str1[200];
  char str2[200];
  char *str3 = "% p Test % 3.p Test % 5.7p TEST % 10p GOD %.p";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "91918";
  char *val4 = "32311";
  char *val5 = "23";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Plus
START_TEST(sprintf_p_test12) {
  char str1[200];
  char str2[200];
  char *str3 = "%+p Test %+3.p Test %+5.7p TEST %+10p GOD %+.p";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "91918";
  char *val4 = "32311";
  char *val5 = "3261";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Hash
START_TEST(sprintf_p_test13) {
  char str1[200];
  char str2[200];
  char *str3 = "%#p Test %#3p Test %#5.7p TEST %#.7p Oof %#.p";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "91918";
  char *val4 = "32311";
  char *val5 = "8894";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_p_test14) {
  char str1[200];
  char str2[200];
  char *str3 = "%0p Test %06p Test %05.7p TEST %0.7p Oof %0.p";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "91918";
  char *val4 = "32311";
  char *val5 = "8894";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Asterisk
START_TEST(sprintf_p_test15) {
  char str1[200];
  char str2[200];
  char *str3 = "%*p Test %-*p Test %*.*p TEST %.*p Lololol %.*p";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "9193112312312";
  char *val4 = "32311";
  char *val5 = "WTF cmon";
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  int ast6 = 18;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3,
                           ast5, val4, ast6, val5),
                   s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4,
                               val3, ast5, val4, ast6, val5));
  ck_assert_pstr_eq(str1, str2);
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
  tcase_add_test(strerror_tests, strerror_test2);

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
  tcase_add_test(strtok_tests, strtok_test6);

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
  tcase_add_test(trim_tests, trim_test6);
  tcase_add_test(trim_tests, trim_test7);

  return s2;
}

Suite *sscanf_suite() {
  Suite *s3 = suite_create("SSCANF_TESTS");
  TCase *sscanf_c_tests = tcase_create("SPEC c (SSCANF)");
  suite_add_tcase(s3, sscanf_c_tests);
  tcase_add_test(sscanf_c_tests, sscanf_c_test1);
  tcase_add_test(sscanf_c_tests, sscanf_c_test2);
  tcase_add_test(sscanf_c_tests, sscanf_c_test3);

  TCase *sscanf_d_tests = tcase_create("SPEC d (SSCANF)");
  suite_add_tcase(s3, sscanf_d_tests);
  tcase_add_test(sscanf_d_tests, sscanf_d_test1);
  tcase_add_test(sscanf_d_tests, sscanf_d_test2);
  tcase_add_test(sscanf_d_tests, sscanf_d_test3);
  tcase_add_test(sscanf_d_tests, sscanf_d_test4);
  tcase_add_test(sscanf_d_tests, sscanf_d_test5);
  tcase_add_test(sscanf_d_tests, sscanf_d_test6);
  // tcase_add_test(sscanf_d_tests, sscanf_d_test7);
  tcase_add_test(sscanf_d_tests, sscanf_d_test8);
  tcase_add_test(sscanf_d_tests, sscanf_d_test9);
  // tcase_add_test(sscanf_d_tests, sscanf_d_test10);
  // tcase_add_test(sscanf_d_tests, sscanf_d_test11);
  tcase_add_test(sscanf_d_tests, sscanf_d_test12);
  tcase_add_test(sscanf_d_tests, sscanf_d_test13);
  tcase_add_test(sscanf_d_tests, sscanf_d_test14);
  tcase_add_test(sscanf_d_tests, sscanf_d_test15);
  tcase_add_test(sscanf_d_tests, sscanf_d_test16);
  tcase_add_test(sscanf_d_tests, sscanf_d_test17);
  tcase_add_test(sscanf_d_tests, sscanf_d_test18);
  tcase_add_test(sscanf_d_tests, sscanf_d_test19);
  tcase_add_test(sscanf_d_tests, sscanf_d_test20);
  // tcase_add_test(sscanf_d_tests, sscanf_d_test21);
  tcase_add_test(sscanf_d_tests, sscanf_d_test22);
  tcase_add_test(sscanf_d_tests, sscanf_d_test23);
  // tcase_add_test(sscanf_d_tests, sscanf_d_test24);
  // tcase_add_test(sscanf_d_tests, sscanf_d_test25);
  // tcase_add_test(sscanf_d_tests, sscanf_d_test26);
  tcase_add_test(sscanf_d_tests, sscanf_d_test27);
  tcase_add_test(sscanf_d_tests, sscanf_d_test28);
  tcase_add_test(sscanf_d_tests, sscanf_d_test29);
  tcase_add_test(sscanf_d_tests, sscanf_d_test30);

  TCase *sscanf_i_tests = tcase_create("SPEC i (SSCANF)");
  suite_add_tcase(s3, sscanf_i_tests);
  tcase_add_test(sscanf_i_tests, sscanf_i_test1);
  tcase_add_test(sscanf_i_tests, sscanf_i_test2);
  tcase_add_test(sscanf_i_tests, sscanf_i_test3);
  tcase_add_test(sscanf_i_tests, sscanf_i_test4);
  tcase_add_test(sscanf_i_tests, sscanf_i_test5);
  tcase_add_test(sscanf_i_tests, sscanf_i_test6);
  tcase_add_test(sscanf_i_tests, sscanf_i_test7);
  tcase_add_test(sscanf_i_tests, sscanf_i_test8);
  tcase_add_test(sscanf_i_tests, sscanf_i_test9);
  tcase_add_test(sscanf_i_tests, sscanf_i_test10);

  TCase *sscanf_e_tests = tcase_create("SPEC e (SSCANF)");
  suite_add_tcase(s3, sscanf_e_tests);
  tcase_add_test(sscanf_e_tests, sscanf_e_test1);
  // tcase_add_test(sscanf_e_tests, sscanf_e_test2);
  tcase_add_test(sscanf_e_tests, sscanf_e_test3);
  // tcase_add_test(sscanf_e_tests, sscanf_e_test4);
  // tcase_add_test(sscanf_e_tests, sscanf_e_test5);
  tcase_add_test(sscanf_e_tests, sscanf_e_test6);
  tcase_add_test(sscanf_e_tests, sscanf_e_test7);
  // tcase_add_test(sscanf_e_tests, sscanf_e_test8);
  // tcase_add_test(sscanf_e_tests, sscanf_e_test9);
  // tcase_add_test(sscanf_e_tests, sscanf_e_test10);
  tcase_add_test(sscanf_e_tests, sscanf_e_test11);
  tcase_add_test(sscanf_e_tests, sscanf_e_test12);
  tcase_add_test(sscanf_e_tests, sscanf_e_test13);

  TCase *sscanf_E_tests = tcase_create("SPEC E (SSCANF)");
  suite_add_tcase(s3, sscanf_E_tests);
  tcase_add_test(sscanf_E_tests, sscanf_E_test1);
  // tcase_add_test(sscanf_E_tests, sscanf_E_test2);
  tcase_add_test(sscanf_E_tests, sscanf_E_test3);
  // tcase_add_test(sscanf_E_tests, sscanf_E_test4);
  // tcase_add_test(sscanf_E_tests, sscanf_E_test5);
  tcase_add_test(sscanf_E_tests, sscanf_E_test6);
  tcase_add_test(sscanf_E_tests, sscanf_E_test7);
  // tcase_add_test(sscanf_E_tests, sscanf_E_test8);
  // tcase_add_test(sscanf_E_tests, sscanf_E_test9);
  // tcase_add_test(sscanf_E_tests, sscanf_E_test10);
  tcase_add_test(sscanf_E_tests, sscanf_E_test11);
  tcase_add_test(sscanf_E_tests, sscanf_E_test12);

  TCase *sscanf_f_tests = tcase_create("SPEC f (SSCANF)");
  suite_add_tcase(s3, sscanf_f_tests);
  tcase_add_test(sscanf_f_tests, sscanf_f_test1);
  tcase_add_test(sscanf_f_tests, sscanf_f_test2);
  tcase_add_test(sscanf_f_tests, sscanf_f_test3);
  tcase_add_test(sscanf_f_tests, sscanf_f_test4);
  tcase_add_test(sscanf_f_tests, sscanf_f_test5);
  tcase_add_test(sscanf_f_tests, sscanf_f_test6);
  tcase_add_test(sscanf_f_tests, sscanf_f_test7);
  tcase_add_test(sscanf_f_tests, sscanf_f_test8);
  tcase_add_test(sscanf_f_tests, sscanf_f_test9);
  tcase_add_test(sscanf_f_tests, sscanf_f_test10);
  tcase_add_test(sscanf_f_tests, sscanf_f_test11);
  tcase_add_test(sscanf_f_tests, sscanf_f_test12);
  // tcase_add_test(sscanf_f_tests, sscanf_f_test13);
  tcase_add_test(sscanf_f_tests, sscanf_f_test14);

  TCase *sscanf_g_tests = tcase_create("SPEC g (SSCANF)");
  suite_add_tcase(s3, sscanf_g_tests);
  tcase_add_test(sscanf_g_tests, sscanf_g_test1);
  // tcase_add_test(sscanf_g_tests, sscanf_g_test2);
  tcase_add_test(sscanf_g_tests, sscanf_g_test3);
  // tcase_add_test(sscanf_g_tests, sscanf_g_test4);
  // tcase_add_test(sscanf_g_tests, sscanf_g_test5);
  tcase_add_test(sscanf_g_tests, sscanf_g_test6);
  tcase_add_test(sscanf_g_tests, sscanf_g_test7);
  // tcase_add_test(sscanf_g_tests, sscanf_g_test8);
  // tcase_add_test(sscanf_g_tests, sscanf_g_test9);
  // tcase_add_test(sscanf_g_tests, sscanf_g_test10);
  tcase_add_test(sscanf_g_tests, sscanf_g_test11);

  TCase *sscanf_G_tests = tcase_create("SPEC G (SSCANF)");
  suite_add_tcase(s3, sscanf_G_tests);
  tcase_add_test(sscanf_G_tests, sscanf_G_test1);
  // tcase_add_test(sscanf_G_tests, sscanf_G_test2);
  tcase_add_test(sscanf_G_tests, sscanf_G_test3);
  // tcase_add_test(sscanf_G_tests, sscanf_G_test4);
  // tcase_add_test(sscanf_G_tests, sscanf_G_test5);
  tcase_add_test(sscanf_G_tests, sscanf_G_test6);
  tcase_add_test(sscanf_G_tests, sscanf_G_test7);
  // tcase_add_test(sscanf_G_tests, sscanf_G_test8);
  // tcase_add_test(sscanf_G_tests, sscanf_G_test9);
  // tcase_add_test(sscanf_G_tests, sscanf_G_test10);
  tcase_add_test(sscanf_G_tests, sscanf_G_test11);

  TCase *sscanf_o_tests = tcase_create("SPEC o (SSCANF)");
  suite_add_tcase(s3, sscanf_o_tests);
  tcase_add_test(sscanf_o_tests, sscanf_o_test1);
  tcase_add_test(sscanf_o_tests, sscanf_o_test2);
  tcase_add_test(sscanf_o_tests, sscanf_o_test3);
  tcase_add_test(sscanf_o_tests, sscanf_o_test4);
  tcase_add_test(sscanf_o_tests, sscanf_o_test5);

  TCase *sscanf_s_tests = tcase_create("SPEC s (SSCANF)");
  suite_add_tcase(s3, sscanf_s_tests);
  tcase_add_test(sscanf_s_tests, sscanf_s_test1);
  tcase_add_test(sscanf_s_tests, sscanf_s_test2);
  tcase_add_test(sscanf_s_tests, sscanf_s_test3);
  tcase_add_test(sscanf_s_tests, sscanf_s_test4);

  TCase *sscanf_u_tests = tcase_create("SPEC u (SSCANF)");
  suite_add_tcase(s3, sscanf_u_tests);
  tcase_add_test(sscanf_u_tests, sscanf_u_test1);
  tcase_add_test(sscanf_u_tests, sscanf_u_test2);
  // tcase_add_test(sscanf_u_tests, sscanf_u_test3);
  // tcase_add_test(sscanf_u_tests, sscanf_u_test4);
  tcase_add_test(sscanf_u_tests, sscanf_u_test5);
  tcase_add_test(sscanf_u_tests, sscanf_u_test6);
  // tcase_add_test(sscanf_u_tests, sscanf_u_test7);

  TCase *sscanf_x_tests = tcase_create("SPEC x (SSCANF)");
  suite_add_tcase(s3, sscanf_x_tests);
  tcase_add_test(sscanf_x_tests, sscanf_x_test1);
  tcase_add_test(sscanf_x_tests, sscanf_x_test2);
  tcase_add_test(sscanf_x_tests, sscanf_x_test3);
  tcase_add_test(sscanf_x_tests, sscanf_x_test4);
  tcase_add_test(sscanf_x_tests, sscanf_x_test5);
  tcase_add_test(sscanf_x_tests, sscanf_x_test6);
  tcase_add_test(sscanf_x_tests, sscanf_x_test7);
  tcase_add_test(sscanf_x_tests, sscanf_x_test8);
  tcase_add_test(sscanf_x_tests, sscanf_x_test9);

  TCase *sscanf_X_tests = tcase_create("SPEC X (SSCANF)");
  suite_add_tcase(s3, sscanf_X_tests);
  tcase_add_test(sscanf_X_tests, sscanf_X_test1);
  tcase_add_test(sscanf_X_tests, sscanf_X_test2);
  tcase_add_test(sscanf_X_tests, sscanf_X_test3);
  tcase_add_test(sscanf_X_tests, sscanf_X_test4);

  TCase *sscanf_p_tests = tcase_create("SPEC p (SSCANF)");
  suite_add_tcase(s3, sscanf_p_tests);
  tcase_add_test(sscanf_p_tests, sscanf_p_test1);
  tcase_add_test(sscanf_p_tests, sscanf_p_test2);
  tcase_add_test(sscanf_p_tests, sscanf_p_test3);
  tcase_add_test(sscanf_p_tests, sscanf_p_test4);

  TCase *sscanf_n_tests = tcase_create("SPEC n (SSCANF)");
  suite_add_tcase(s3, sscanf_n_tests);
  tcase_add_test(sscanf_n_tests, sscanf_n_test1);
  tcase_add_test(sscanf_n_tests, sscanf_n_test2);
  tcase_add_test(sscanf_n_tests, sscanf_n_test3);

  TCase *sscanf_percent_tests = tcase_create("SPEC percent (SSCANF)");
  suite_add_tcase(s3, sscanf_percent_tests);
  tcase_add_test(sscanf_percent_tests, sscanf_percent_test1);

  return s3;
}

Suite *sprintf_suite() {
  Suite *s4 = suite_create("SPRINTF_TESTS");
  TCase *sprintf_c_tests = tcase_create("SPEC c (SPRINTF)");  // part 2
  suite_add_tcase(s4, sprintf_c_tests);
  tcase_add_test(sprintf_c_tests, sprintf_c_test1);
  tcase_add_test(sprintf_c_tests, sprintf_c_test2);
  tcase_add_test(sprintf_c_tests, sprintf_c_test3);
  tcase_add_test(sprintf_c_tests, sprintf_c_test4);
  tcase_add_test(sprintf_c_tests, sprintf_c_test5);
  tcase_add_test(sprintf_c_tests, sprintf_c_test6);
  tcase_add_test(sprintf_c_tests, sprintf_c_test7);

  TCase *sprintf_d_tests = tcase_create("SPEC d (SPRINTF)");  // part 2
  suite_add_tcase(s4, sprintf_d_tests);
  tcase_add_test(sprintf_d_tests, sprintf_d_test1);
  tcase_add_test(sprintf_d_tests, sprintf_d_test2);
  // tcase_add_test(sprintf_d_tests, sprintf_d_test3);
  tcase_add_test(sprintf_d_tests, sprintf_d_test4);
  tcase_add_test(sprintf_d_tests, sprintf_d_test5);
  tcase_add_test(sprintf_d_tests, sprintf_d_test6);
  // tcase_add_test(sprintf_d_tests, sprintf_d_test7);
  tcase_add_test(sprintf_d_tests, sprintf_d_test8);
  tcase_add_test(sprintf_d_tests, sprintf_d_test9);
  // tcase_add_test(sprintf_d_tests, sprintf_d_test10);
  // tcase_add_test(sprintf_d_tests, sprintf_d_test11);
  tcase_add_test(sprintf_d_tests, sprintf_d_test12);
  tcase_add_test(sprintf_d_tests, sprintf_d_test13);

  TCase *sprintf_e_tests = tcase_create("SPEC e (SPRINTF)");  // dop
  suite_add_tcase(s4, sprintf_e_tests);
  // tcase_add_test(sprintf_e_tests, sprintf_e_test1);
  // tcase_add_test(sprintf_e_tests, sprintf_e_test2);
  // tcase_add_test(sprintf_e_tests, sprintf_e_test3);
  // tcase_add_test(sprintf_e_tests, sprintf_e_test4);
  // tcase_add_test(sprintf_e_tests, sprintf_e_test5);
  // tcase_add_test(sprintf_e_tests, sprintf_e_test6);
  // tcase_add_test(sprintf_e_tests, sprintf_e_test7);
  // tcase_add_test(sprintf_e_tests, sprintf_e_test8);
  // tcase_add_test(sprintf_e_tests, sprintf_e_test9);
  // tcase_add_test(sprintf_e_tests, sprintf_e_test10);

  TCase *sprintf_E_tests = tcase_create("SPEC E (SPRINTF)");  // dop
  suite_add_tcase(s4, sprintf_E_tests);
  // tcase_add_test(sprintf_E_tests, sprintf_E_test1);
  // tcase_add_test(sprintf_E_tests, sprintf_E_test2);
  // tcase_add_test(sprintf_E_tests, sprintf_E_test3);
  // tcase_add_test(sprintf_E_tests, sprintf_E_test4);
  // tcase_add_test(sprintf_E_tests, sprintf_E_test5);
  // tcase_add_test(sprintf_E_tests, sprintf_E_test6);
  // tcase_add_test(sprintf_E_tests, sprintf_E_test7);
  // tcase_add_test(sprintf_E_tests, sprintf_E_test8);
  // tcase_add_test(sprintf_E_tests, sprintf_E_test9);
  // tcase_add_test(sprintf_E_tests, sprintf_E_test10);

  TCase *sprintf_f_tests = tcase_create("SPEC f (SPRINTF)");  // part 2
  suite_add_tcase(s4, sprintf_f_tests);
  tcase_add_test(sprintf_f_tests, sprintf_f_test1);
  tcase_add_test(sprintf_f_tests, sprintf_f_test2);
  // tcase_add_test(sprintf_f_tests, sprintf_f_test3);
  // tcase_add_test(sprintf_f_tests, sprintf_f_test4);
  // tcase_add_test(sprintf_f_tests, sprintf_f_test5);
  // tcase_add_test(sprintf_f_tests, sprintf_f_test6);
  // tcase_add_test(sprintf_f_tests, sprintf_f_test7);
  // tcase_add_test(sprintf_f_tests, sprintf_f_test8);
  // tcase_add_test(sprintf_f_tests, sprintf_f_test9);
  // tcase_add_test(sprintf_f_tests, sprintf_f_test10);
  tcase_add_test(sprintf_f_tests, sprintf_f_test11);
  // tcase_add_test(sprintf_f_tests, sprintf_f_test12);
  // tcase_add_test(sprintf_f_tests, sprintf_f_test13);
  tcase_add_test(sprintf_f_tests, sprintf_f_test14);
  // tcase_add_test(sprintf_f_tests, sprintf_f_test15);
  // tcase_add_test(sprintf_f_tests, sprintf_f_test16);
  // tcase_add_test(sprintf_f_tests, sprintf_f_test17);
  // tcase_add_test(sprintf_f_tests, sprintf_f_test18);
  // tcase_add_test(sprintf_f_tests, sprintf_f_test19);
  // tcase_add_test(sprintf_f_tests, sprintf_f_test20);
  tcase_add_test(sprintf_f_tests, sprintf_f_test21);
  // tcase_add_test(sprintf_f_tests, sprintf_f_test22);
  // tcase_add_test(sprintf_f_tests, sprintf_f_test23);
  // tcase_add_test(sprintf_f_tests, sprintf_f_test24);

  /*
      TCase *sprintf_g_tests = tcase_create("SPEC g (SPRINTF)");  // dop
      suite_add_tcase(s4, sprintf_g_tests);
      tcase_add_test(sprintf_g_tests, sprintf_g_test1);
      tcase_add_test(sprintf_g_tests, sprintf_g_test2);
      tcase_add_test(sprintf_g_tests, sprintf_g_test3);
      tcase_add_test(sprintf_g_tests, sprintf_g_test4);
      tcase_add_test(sprintf_g_tests, sprintf_g_test5);
      tcase_add_test(sprintf_g_tests, sprintf_g_test6);
      tcase_add_test(sprintf_g_tests, sprintf_g_test7);
      tcase_add_test(sprintf_g_tests, sprintf_g_test8);
      tcase_add_test(sprintf_g_tests, sprintf_g_test9);
      tcase_add_test(sprintf_g_tests, sprintf_g_test10);
      tcase_add_test(sprintf_g_tests, sprintf_g_test11);
      tcase_add_test(sprintf_g_tests, sprintf_g_test12);
      tcase_add_test(sprintf_g_tests, sprintf_g_test13);
      tcase_add_test(sprintf_g_tests, sprintf_g_test14);
      tcase_add_test(sprintf_g_tests, sprintf_g_test15);
      tcase_add_test(sprintf_g_tests, sprintf_g_test16);
      tcase_add_test(sprintf_g_tests, sprintf_g_test17);
      tcase_add_test(sprintf_g_tests, sprintf_g_test18);
      tcase_add_test(sprintf_g_tests, sprintf_g_test19);

      TCase *sprintf_G_tests = tcase_create("SPEC G (SPRINTF)");  // dop
      suite_add_tcase(s4, sprintf_G_tests);
      tcase_add_test(sprintf_G_tests, sprintf_G_test1);
      tcase_add_test(sprintf_G_tests, sprintf_G_test2);
      tcase_add_test(sprintf_G_tests, sprintf_G_test3);
      tcase_add_test(sprintf_G_tests, sprintf_G_test4);
      tcase_add_test(sprintf_G_tests, sprintf_G_test5);
      tcase_add_test(sprintf_G_tests, sprintf_G_test6);
      tcase_add_test(sprintf_G_tests, sprintf_G_test7);
      tcase_add_test(sprintf_G_tests, sprintf_G_test8);
      tcase_add_test(sprintf_G_tests, sprintf_G_test9);
      tcase_add_test(sprintf_G_tests, sprintf_G_test10);
      tcase_add_test(sprintf_G_tests, sprintf_G_test11);

      TCase *sprintf_o_tests = tcase_create("SPEC o (SPRINTF)");  // dop
      suite_add_tcase(s4, sprintf_o_tests);
      tcase_add_test(sprintf_o_tests, sprintf_o_test1);
      tcase_add_test(sprintf_o_tests, sprintf_o_test2);
      tcase_add_test(sprintf_o_tests, sprintf_o_test3);
      tcase_add_test(sprintf_o_tests, sprintf_o_test4);
      tcase_add_test(sprintf_o_tests, sprintf_o_test5);
      tcase_add_test(sprintf_o_tests, sprintf_o_test6);
      tcase_add_test(sprintf_o_tests, sprintf_o_test7);
      tcase_add_test(sprintf_o_tests, sprintf_o_test8);
      tcase_add_test(sprintf_o_tests, sprintf_o_test9);
      tcase_add_test(sprintf_o_tests, sprintf_o_test10);
      tcase_add_test(sprintf_o_tests, sprintf_o_test11);
      tcase_add_test(sprintf_o_tests, sprintf_o_test12);
      tcase_add_test(sprintf_o_tests, sprintf_o_test13);
      tcase_add_test(sprintf_o_tests, sprintf_o_test14);
      tcase_add_test(sprintf_o_tests, sprintf_o_test15);
*/

  TCase *sprintf_s_tests = tcase_create("SPEC s (SPRINTF)");  // part 2
  suite_add_tcase(s4, sprintf_s_tests);
  tcase_add_test(sprintf_s_tests, sprintf_s_test1);
  tcase_add_test(sprintf_s_tests, sprintf_s_test2);
  tcase_add_test(sprintf_s_tests, sprintf_s_test3);
  // tcase_add_test(sprintf_s_tests, sprintf_s_test4);
  tcase_add_test(sprintf_s_tests, sprintf_s_test5);
  tcase_add_test(sprintf_s_tests, sprintf_s_test6);
  tcase_add_test(sprintf_s_tests, sprintf_s_test7);
  tcase_add_test(sprintf_s_tests, sprintf_s_test8);
  tcase_add_test(sprintf_s_tests, sprintf_s_test9);
  // tcase_add_test(sprintf_s_tests, sprintf_s_test10);
  tcase_add_test(sprintf_s_tests, sprintf_s_test11);
  tcase_add_test(sprintf_s_tests, sprintf_s_test12);
  tcase_add_test(sprintf_s_tests, sprintf_s_test13);
  tcase_add_test(sprintf_s_tests, sprintf_s_test14);
  tcase_add_test(sprintf_s_tests, sprintf_s_test15);
  tcase_add_test(sprintf_s_tests, sprintf_s_test16);
  // tcase_add_test(sprintf_s_tests, sprintf_s_test17);
  // tcase_add_test(sprintf_s_tests, sprintf_s_test18);
  tcase_add_test(sprintf_s_tests, sprintf_s_test19);
  tcase_add_test(sprintf_s_tests, sprintf_s_test20);
  // tcase_add_test(sprintf_s_tests, sprintf_s_test21);
  // tcase_add_test(sprintf_s_tests, sprintf_s_test22);

  TCase *sprintf_u_tests = tcase_create("SPEC u (SPRINTF)");  // part 2
  suite_add_tcase(s4, sprintf_u_tests);
  tcase_add_test(sprintf_u_tests, sprintf_u_test1);
  tcase_add_test(sprintf_u_tests, sprintf_u_test2);
  tcase_add_test(sprintf_u_tests, sprintf_u_test3);
  tcase_add_test(sprintf_u_tests, sprintf_u_test4);
  tcase_add_test(sprintf_u_tests, sprintf_u_test5);
  tcase_add_test(sprintf_u_tests, sprintf_u_test6);
  tcase_add_test(sprintf_u_tests, sprintf_u_test7);
  tcase_add_test(sprintf_u_tests, sprintf_u_test8);
  tcase_add_test(sprintf_u_tests, sprintf_u_test9);
  // tcase_add_test(sprintf_u_tests, sprintf_u_test10);
  tcase_add_test(sprintf_u_tests, sprintf_u_test11);
  tcase_add_test(sprintf_u_tests, sprintf_u_test12);
  tcase_add_test(sprintf_u_tests, sprintf_u_test13);
  tcase_add_test(sprintf_u_tests, sprintf_u_test14);
  tcase_add_test(sprintf_u_tests, sprintf_u_test15);
  // tcase_add_test(sprintf_u_tests, sprintf_u_test16);
  // tcase_add_test(sprintf_u_tests, sprintf_u_test17);
  tcase_add_test(sprintf_u_tests, sprintf_u_test18);
  tcase_add_test(sprintf_u_tests, sprintf_u_test19);
  tcase_add_test(sprintf_u_tests, sprintf_u_test20);

  TCase *sprintf_x_tests = tcase_create("SPEC x (SPRINTF)");  // dop
  suite_add_tcase(s4, sprintf_x_tests);
  // tcase_add_test(sprintf_x_tests, sprintf_x_test1);
  // tcase_add_test(sprintf_x_tests, sprintf_x_test2);
  // tcase_add_test(sprintf_x_tests, sprintf_x_test3);
  // tcase_add_test(sprintf_x_tests, sprintf_x_test4);
  // tcase_add_test(sprintf_x_tests, sprintf_x_test5);
  // tcase_add_test(sprintf_x_tests, sprintf_x_test6);
  // tcase_add_test(sprintf_x_tests, sprintf_x_test7);
  // tcase_add_test(sprintf_x_tests, sprintf_x_test8);
  // tcase_add_test(sprintf_x_tests, sprintf_x_test9);
  // tcase_add_test(sprintf_x_tests, sprintf_x_test10);
  // tcase_add_test(sprintf_x_tests, sprintf_x_test11);
  // tcase_add_test(sprintf_x_tests, sprintf_x_test12);
  // tcase_add_test(sprintf_x_tests, sprintf_x_test13);
  // tcase_add_test(sprintf_x_tests, sprintf_x_test14);
  // tcase_add_test(sprintf_x_tests, sprintf_x_test15);
  // tcase_add_test(sprintf_x_tests, sprintf_x_test16);
  // tcase_add_test(sprintf_x_tests, sprintf_x_test17);
  // tcase_add_test(sprintf_x_tests, sprintf_x_test18);
  // tcase_add_test(sprintf_x_tests, sprintf_x_test19);
  // tcase_add_test(sprintf_x_tests, sprintf_x_test20);

  TCase *sprintf_X_tests = tcase_create("SPEC X (SPRINTF)");  // dop
  suite_add_tcase(s4, sprintf_X_tests);
  // tcase_add_test(sprintf_X_tests, sprintf_X_test1);
  // tcase_add_test(sprintf_X_tests, sprintf_X_test2);
  // tcase_add_test(sprintf_X_tests, sprintf_X_test3);
  // tcase_add_test(sprintf_X_tests, sprintf_X_test4);
  // tcase_add_test(sprintf_X_tests, sprintf_X_test5);
  // tcase_add_test(sprintf_X_tests, sprintf_X_test6);
  // tcase_add_test(sprintf_X_tests, sprintf_X_test7);
  // tcase_add_test(sprintf_X_tests, sprintf_X_test8);
  // tcase_add_test(sprintf_X_tests, sprintf_X_test9);
  // tcase_add_test(sprintf_X_tests, sprintf_X_test10);
  // tcase_add_test(sprintf_X_tests, sprintf_X_test11);
  // tcase_add_test(sprintf_X_tests, sprintf_X_test12);
  // tcase_add_test(sprintf_X_tests, sprintf_X_test13);
  // tcase_add_test(sprintf_X_tests, sprintf_X_test14);
  // tcase_add_test(sprintf_X_tests, sprintf_X_test15);
  // tcase_add_test(sprintf_X_tests, sprintf_X_test16);
  // tcase_add_test(sprintf_X_tests, sprintf_X_test17);
  // tcase_add_test(sprintf_X_tests, sprintf_X_test18);
  // tcase_add_test(sprintf_X_tests, sprintf_X_test19);
  // tcase_add_test(sprintf_X_tests, sprintf_X_test20);

  TCase *sprintf_p_tests = tcase_create("SPEC p (SPRINTF)");  // dop
  suite_add_tcase(s4, sprintf_p_tests);
  // tcase_add_test(sprintf_p_tests, sprintf_p_test1);
  // tcase_add_test(sprintf_p_tests, sprintf_p_test2);
  // tcase_add_test(sprintf_p_tests, sprintf_p_test3);
  // tcase_add_test(sprintf_p_tests, sprintf_p_test4);
  // tcase_add_test(sprintf_p_tests, sprintf_p_test5);
  // tcase_add_test(sprintf_p_tests, sprintf_p_test6);
  // tcase_add_test(sprintf_p_tests, sprintf_p_test7);
  // tcase_add_test(sprintf_p_tests, sprintf_p_test8);
  // tcase_add_test(sprintf_p_tests, sprintf_p_test9);
  // tcase_add_test(sprintf_p_tests, sprintf_p_test10);
  // tcase_add_test(sprintf_p_tests, sprintf_p_test11);
  // tcase_add_test(sprintf_p_tests, sprintf_p_test12);
  // tcase_add_test(sprintf_p_tests, sprintf_p_test13);
  // tcase_add_test(sprintf_p_tests, sprintf_p_test14);
  // tcase_add_test(sprintf_p_tests, sprintf_p_test15);
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