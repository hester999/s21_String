#include "../s21_string.h"


s21_size_t s21_trim_strspn_reverse(const char *str1, const char *str2) {
    s21_size_t str1len = s21_strlen(str1);
    s21_size_t str2len = s21_strlen(str2);
    int flag = 0;
    int res = 0;
    for (int i = (int) str1len - 1; i > -1 && flag == 0; i--) {
        int inner_res = 0;
        for (s21_size_t j = 0; j < str2len && inner_res == 0; j++) {
            if (str1[i] == str2[j]) {
                inner_res++;
            }
        }
        if (inner_res == 0) {
            flag++;
            res--;
        }
        res++;
    }

    return res;
}

void *s21_trim(const char *src, const char *trim_char) {
    char *buffer = s21_NULL;
    if (src != s21_NULL) {
        s21_size_t length = s21_strlen(src);
        if (trim_char == s21_NULL) {
            trim_char = " ";
        }
        s21_size_t first_trim_num = s21_strspn(src, trim_char);
        s21_size_t last_trim_num = s21_trim_strspn_reverse(src, trim_char);
        s21_size_t trimmed_length = length - first_trim_num - last_trim_num;
        if (trimmed_length > 0) {
            buffer = custom_calloc(trimmed_length + 1, sizeof(char));
            if (buffer != s21_NULL) {
                for (s21_size_t i = 0; i < trimmed_length; ++i) {
                    buffer[i] = src[first_trim_num + i];
                }
                buffer[trimmed_length] = 0;
            }
        } else {
            buffer = custom_calloc(1, sizeof(char));
            if (buffer != s21_NULL) {
                buffer[0] = 0;
            }
        }
    }
    return buffer;
}