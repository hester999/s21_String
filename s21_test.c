#include <check.h>
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

  ck_assert_int_eq(s21_sscanf("333abcde333", "%dabcde%d", &a, &b),
                   sscanf("333abcde333", "%dabcde%d", &c, &d));
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

  ck_assert_int_eq(s21_sscanf(" ", "%d", &a), sscanf(" ", "%d", &b));
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

  ck_assert_int_eq(s21_sscanf("19223372036854775807", "%ld%ld", &la, &lb),
                   sscanf("19223372036854775807", "%ld%ld", &lc, &ld));
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

  ck_assert_int_eq(s21_sscanf("123456789012345", "%lld", &lla),
                   sscanf("123456789012345", "%lld", &llb));
  ck_assert_int_eq(lla, llb);
}
END_TEST

// test 25

START_TEST(sscanf_d_test26) {
  long long lla = 0, llb = 0;

  ck_assert_int_eq(s21_sscanf("987654321", "%lld", &lla),
                   sscanf("987654321", "%lld", &llb));
  ck_assert_int_eq(lla, llb);
}
END_TEST

// without digit
START_TEST(sscanf_d_test27) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("abc", "%d", &a), sscanf("abc", "%d", &b));
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

  ck_assert_int_eq(s21_sscanf("--1234567890", "%i", &a),
                   sscanf("--1234567890", "%i", &b));
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

  ck_assert_int_eq(s21_sscanf("a123abcdef", "%i", &a),
                   sscanf("a123abcdef", "%i", &b));
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
// nan
START_TEST(sscanf_e_test1) {
  float a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("nan", "%e", &a), sscanf("nan", "%e", &b));
  ck_assert_float_nan(a);
  ck_assert_float_nan(b);
}
END_TEST

START_TEST(sscanf_e_test2) {
  float a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("1.23e-4", "%e", &a),
                   sscanf("1.23e-4", "%e", &b));
  ck_assert_float_eq_tol(a, b, 0.000001);
}
END_TEST

START_TEST(sscanf_e_test3) {
  float a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("1.23e4", "%e", &a), sscanf("1.23e4", "%e", &b));
  ck_assert_float_eq_tol(a, b, 0.000001);
}
END_TEST

// SPECIFIER E
START_TEST(sscanf_E_test1) {
  float a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("-inf", "%E", &a), sscanf("-inf", "%E", &b));
  ck_assert(isinf(a));
  ck_assert(isinf(b));
}
END_TEST

START_TEST(sscanf_E_test2) {
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

  ck_assert_int_eq(s21_sscanf("", "%f", &a), sscanf("", "%f", &b));
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

  ck_assert_int_eq(s21_sscanf(".", "%f", &a), sscanf(".", "%f", &b));
  ck_assert_float_eq_tol(a, b, 0.000001);
}
END_TEST

START_TEST(sscanf_f_test7) {
  float a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("abc", "%f", &a), sscanf("abc", "%f", &b));
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

// SPECIFIER g
START_TEST(sscanf_g_test1) {
  float a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("iNf", "%g", &a), sscanf("iNf", "%g", &b));
  ck_assert(isinf(a));
  ck_assert(isinf(b));
}
END_TEST

// SPECIFIER G
START_TEST(sscanf_G_test1) {
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

  ck_assert_int_eq(s21_sscanf("", "%s", buf1), sscanf("", "%s", buf2));
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

  ck_assert_int_eq(s21_sscanf("1234567890", "%u", &a),
                   sscanf("1234567890", "%u", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_u_test2) {
  unsigned int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("12345678901", "%u", &a),
                   sscanf("12345678901", "%u", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_u_test3) {
  unsigned long long lla = 0, llb = 0;

  ck_assert_int_eq(s21_sscanf("123456789012345678901", "%llu", &lla),
                   sscanf("123456789012345678901", "%llu", &llb));
  ck_assert_int_eq(lla, llb);
}
END_TEST

START_TEST(sscanf_u_test4) {
  unsigned long long lla = 0, llb = 0;

  ck_assert_int_eq(s21_sscanf("12345678901234567890123", "%22llu", &lla),
                   sscanf("12345678901234567890123", "%22llu", &llb));
  ck_assert_int_eq(lla, llb);
}
END_TEST

START_TEST(sscanf_u_test5) {
  unsigned long la = 0, lb = 0;
  unsigned short sa = 0, sb = 0;

  ck_assert_int_eq(s21_sscanf("1234567890", "%5hu%lu", &sa, &la),
                   sscanf("1234567890", "%5hu%lu", &sb, &lb));
  ck_assert_int_eq(sa, sb);
  ck_assert_int_eq(la, lb);
}
END_TEST

START_TEST(sscanf_u_test6) {
  unsigned int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("123", "%5u", &a), sscanf("123", "%5u", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_u_test7) {
  unsigned int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("-123", "%u", &a), sscanf("-123", "%u", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

// SPECIFIER x
START_TEST(sscanf_x_test1) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("0x1234567890", "%x", &a),
                   sscanf("0x1234567890", "%x", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_x_test2) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("0X1234567890", "%x", &a),
                   sscanf("0X1234567890", "%x", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_x_test3) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("0x1234567890", "%x", &a),
                   sscanf("0x1234567890", "%x", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_x_test4) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("0X1234567890", "%x", &a),
                   sscanf("0X1234567890", "%x", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_x_test5) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("0x1aBcDeF", "%x", &a),
                   sscanf("0x1AbCdEf", "%x", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_x_test6) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("01aBcDeF", "%x", &a),
                   sscanf("01AbCdEf", "%x", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_x_test7) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("x1aBcDeF", "%x", &a),
                   sscanf("x1AbCdEf", "%x", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_x_test8) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("+0x1aBcDeF", "%x", &a),
                   sscanf("+0x1AbCdEf", "%x", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_x_test9) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("-0x1aBcDeF", "%x", &a),
                   sscanf("-0x1AbCdEf", "%x", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

// SPECIFIER X
START_TEST(sscanf_X_test1) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("0x1abcdef", "%X", &a),
                   sscanf("0x1abcdef", "%X", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_X_test2) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("0x1abcdef", "%X", &a),
                   sscanf("0x1abcdef", "%X", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_X_test3) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("0X1ACDEF", "%X", &a),
                   sscanf("0X1ACDEF", "%X", &b));
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sscanf_X_test4) {
  int a = 0, b = 0;

  ck_assert_int_eq(s21_sscanf("01aBcDeF", "%X", &a),
                   sscanf("01AbCdEf", "%X", &b));
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
// END_TEST

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

  ck_assert_int_eq(s21_sscanf("", "%s%n", buf1, &a),
                   sscanf("", "%s%n", buf2, &b));
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

  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_test5) {
  char str1[100];
  char str2[100];
  char *str3 = "%-5c Test %+5c Test % 5c Test %05c Test";
  int a = 70;

  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_c_test6) {
  char str1[100];
  char str2[100];
  char *str3 = "%-5.5c Test %+5.5c Test % 5.5c Test %05.5c Test";
  int a = 70;

  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a));
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

  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
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

  ck_assert_int_eq(sprintf(str1, str3, a, b), s21_sprintf(str2, str3, a, b));
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

  ck_assert_int_eq(sprintf(str1, str3, 5, a, 10, b),
                   s21_sprintf(str2, str3, 5, a, 10, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_d_test11) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "test test %.*d test %-*.d";

  int a = -100, b = 100;

  ck_assert_int_eq(sprintf(str1, str3, 5, a, 10, b),
                   s21_sprintf(str2, str3, 5, a, 10, b));
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
  // tcase_add_test(sscanf_c_tests, sscanf_c_test2);
  // tcase_add_test(sscanf_c_tests, sscanf_c_test3);

  TCase *sscanf_d_tests = tcase_create("SPEC d (SSCANF)");
  suite_add_tcase(s3, sscanf_d_tests);
  tcase_add_test(sscanf_d_tests, sscanf_d_test1);
  tcase_add_test(sscanf_d_tests, sscanf_d_test2);
  tcase_add_test(sscanf_d_tests, sscanf_d_test3);
  tcase_add_test(sscanf_d_tests, sscanf_d_test4);
  // tcase_add_test(sscanf_d_tests, sscanf_d_test5);
  // tcase_add_test(sscanf_d_tests, sscanf_d_test6);
  // tcase_add_test(sscanf_d_tests, sscanf_d_test7);
  tcase_add_test(sscanf_d_tests, sscanf_d_test8);
  tcase_add_test(sscanf_d_tests, sscanf_d_test9);
  // tcase_add_test(sscanf_d_tests, sscanf_d_test10);
  // tcase_add_test(sscanf_d_tests, sscanf_d_test11);
  // tcase_add_test(sscanf_d_tests, sscanf_d_test12);
  // tcase_add_test(sscanf_d_tests, sscanf_d_test13);
  // tcase_add_test(sscanf_d_tests, sscanf_d_test14);
  tcase_add_test(sscanf_d_tests, sscanf_d_test15);
  tcase_add_test(sscanf_d_tests, sscanf_d_test16);
  tcase_add_test(sscanf_d_tests, sscanf_d_test17);
  tcase_add_test(sscanf_d_tests, sscanf_d_test18);
  tcase_add_test(sscanf_d_tests, sscanf_d_test19);
  tcase_add_test(sscanf_d_tests, sscanf_d_test20);
  // tcase_add_test(sscanf_d_tests, sscanf_d_test21);
  tcase_add_test(sscanf_d_tests, sscanf_d_test22);
  tcase_add_test(sscanf_d_tests, sscanf_d_test23);
  tcase_add_test(sscanf_d_tests, sscanf_d_test24);
  // tcase_add_test(sscanf_d_tests, sscanf_d_test25);
  tcase_add_test(sscanf_d_tests, sscanf_d_test26);
  // tcase_add_test(sscanf_d_tests, sscanf_d_test27);
  tcase_add_test(sscanf_d_tests, sscanf_d_test28);
  tcase_add_test(sscanf_d_tests, sscanf_d_test29);
  // tcase_add_test(sscanf_d_tests, sscanf_d_test30);

  TCase *sscanf_i_tests = tcase_create("SPEC i (SSCANF)");
  suite_add_tcase(s3, sscanf_i_tests);
  tcase_add_test(sscanf_i_tests, sscanf_i_test1);
  // tcase_add_test(sscanf_i_tests, sscanf_i_test2);
  // tcase_add_test(sscanf_i_tests, sscanf_i_test3);
  tcase_add_test(sscanf_i_tests, sscanf_i_test4);
  // tcase_add_test(sscanf_i_tests, sscanf_i_test5);
  // tcase_add_test(sscanf_i_tests, sscanf_i_test6);
  // tcase_add_test(sscanf_i_tests, sscanf_i_test7);
  tcase_add_test(sscanf_i_tests, sscanf_i_test8);
  // tcase_add_test(sscanf_i_tests, sscanf_i_test9);
  // tcase_add_test(sscanf_i_tests, sscanf_i_test10);

  TCase *sscanf_e_tests = tcase_create("SPEC e (SSCANF)");
  suite_add_tcase(s3, sscanf_e_tests);
  tcase_add_test(sscanf_e_tests, sscanf_e_test1);
  // tcase_add_test(sscanf_e_tests, sscanf_e_test2);
  tcase_add_test(sscanf_e_tests, sscanf_e_test3);

  TCase *sscanf_E_tests = tcase_create("SPEC E (SSCANF)");
  suite_add_tcase(s3, sscanf_E_tests);
  // tcase_add_test(sscanf_E_tests, sscanf_E_test1);
  // tcase_add_test(sscanf_E_tests, sscanf_E_test2);

  TCase *sscanf_f_tests = tcase_create("SPEC f (SSCANF)");
  suite_add_tcase(s3, sscanf_f_tests);
  tcase_add_test(sscanf_f_tests, sscanf_f_test1);
  tcase_add_test(sscanf_f_tests, sscanf_f_test2);
  tcase_add_test(sscanf_f_tests, sscanf_f_test3);
  // tcase_add_test(sscanf_f_tests, sscanf_f_test4);
  tcase_add_test(sscanf_f_tests, sscanf_f_test5);
  // tcase_add_test(sscanf_f_tests, sscanf_f_test6);
  // tcase_add_test(sscanf_f_tests, sscanf_f_test7);
  tcase_add_test(sscanf_f_tests, sscanf_f_test8);
  tcase_add_test(sscanf_f_tests, sscanf_f_test9);
  tcase_add_test(sscanf_f_tests, sscanf_f_test10);
  tcase_add_test(sscanf_f_tests, sscanf_f_test11);
  tcase_add_test(sscanf_f_tests, sscanf_f_test12);
  // tcase_add_test(sscanf_f_tests, sscanf_f_test13);

  TCase *sscanf_g_tests = tcase_create("SPEC g (SSCANF)");
  suite_add_tcase(s3, sscanf_g_tests);
  tcase_add_test(sscanf_g_tests, sscanf_g_test1);

  TCase *sscanf_G_tests = tcase_create("SPEC G (SSCANF)");
  suite_add_tcase(s3, sscanf_G_tests);
  tcase_add_test(sscanf_G_tests, sscanf_G_test1);

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
  // tcase_add_test(sscanf_s_tests, sscanf_s_test3);
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
  // tcase_add_test(sscanf_x_tests, sscanf_x_test7);
  tcase_add_test(sscanf_x_tests, sscanf_x_test8);
  tcase_add_test(sscanf_x_tests, sscanf_x_test9);

  TCase *sscanf_X_tests = tcase_create("SPEC X (SSCANF)");
  suite_add_tcase(s3, sscanf_X_tests);
  // tcase_add_test(sscanf_X_tests, sscanf_X_test1);
  // tcase_add_test(sscanf_X_tests, sscanf_X_test2);
  // tcase_add_test(sscanf_X_tests, sscanf_X_test3);
  tcase_add_test(sscanf_X_tests, sscanf_X_test4);

  TCase *sscanf_p_tests = tcase_create("SPEC p (SSCANF)");
  suite_add_tcase(s3, sscanf_p_tests);
  tcase_add_test(sscanf_p_tests, sscanf_p_test1);
  tcase_add_test(sscanf_p_tests, sscanf_p_test2);
  tcase_add_test(sscanf_p_tests, sscanf_p_test3);
  // tcase_add_test(sscanf_p_tests, sscanf_p_test4);

  TCase *sscanf_n_tests = tcase_create("SPEC n (SSCANF)");
  suite_add_tcase(s3, sscanf_n_tests);
  // tcase_add_test(sscanf_n_tests, sscanf_n_test1);
  // tcase_add_test(sscanf_n_tests, sscanf_n_test2);
  // tcase_add_test(sscanf_n_tests, sscanf_n_test3);

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
  tcase_add_test(sprintf_d_tests, sprintf_d_test3);
  tcase_add_test(sprintf_d_tests, sprintf_d_test4);
  tcase_add_test(sprintf_d_tests, sprintf_d_test5);
  tcase_add_test(sprintf_d_tests, sprintf_d_test6);
  tcase_add_test(sprintf_d_tests, sprintf_d_test7);
  tcase_add_test(sprintf_d_tests, sprintf_d_test8);
  tcase_add_test(sprintf_d_tests, sprintf_d_test9);
  tcase_add_test(sprintf_d_tests, sprintf_d_test10);
  tcase_add_test(sprintf_d_tests, sprintf_d_test11);
  tcase_add_test(sprintf_d_tests, sprintf_d_test12);
  tcase_add_test(sprintf_d_tests, sprintf_d_test13);
  /*
    TCase *sprintf_e_tests = tcase_create("SPEC e (SPRINTF)");  // dop
    suite_add_tcase(s4, sprintf_e_tests);
    tcase_add_test(sprintf_e_tests, sprintf_e_test1);

    TCase *sprintf_E_tests = tcase_create("SPEC E (SPRINTF)");  // dop
    suite_add_tcase(s4, sprintf_E_tests);
    tcase_add_test(sprintf_E_tests, sprintf_E_test1);

    TCase *sprintf_f_tests = tcase_create("SPEC f (SPRINTF)");  // part 2
    suite_add_tcase(s4, sprintf_f_tests);
    tcase_add_test(sprintf_f_tests, sprintf_f_test1);

    TCase *sprintf_g_tests = tcase_create("SPEC g (SPRINTF)");  // dop
    suite_add_tcase(s4, sprintf_g_tests);
    tcase_add_test(sprintf_g_tests, sprintf_g_test1);

    TCase *sprintf_G_tests = tcase_create("SPEC G (SPRINTF)");  // dop
    suite_add_tcase(s4, sprintf_G_tests);
    tcase_add_test(sprintf_G_tests, sprintf_G_test1);

    TCase *sprintf_o_tests = tcase_create("SPEC o (SPRINTF)");  // dop
    suite_add_tcase(s4, sprintf_o_tests);
    tcase_add_test(sprintf_o_tests, sprintf_o_test1);

    TCase *sprintf_s_tests = tcase_create("SPEC s (SPRINTF)");  // part 2
    suite_add_tcase(s4, sprintf_s_tests);
    tcase_add_test(sprintf_s_tests, sprintf_s_test1);

    TCase *sprintf_u_tests = tcase_create("SPEC u (SPRINTF)");  // part 2
    suite_add_tcase(s4, sprintf_u_tests);
    tcase_add_test(sprintf_u_tests, sprintf_u_test1);

    TCase *sprintf_x_tests = tcase_create("SPEC x (SPRINTF)");  // dop
    suite_add_tcase(s4, sprintf_x_tests);
    tcase_add_test(sprintf_x_tests, sprintf_x_test1);

    TCase *sprintf_X_tests = tcase_create("SPEC X (SPRINTF)");  // dop
    suite_add_tcase(s4, sprintf_X_tests);
    tcase_add_test(sprintf_X_tests, sprintf_X_test1);

    TCase *sprintf_p_tests = tcase_create("SPEC p (SPRINTF)");  // dop
    suite_add_tcase(s4, sprintf_p_tests);
    tcase_add_test(sprintf_p_tests, sprintf_p_test1);
  */

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