#include "s21_string.h"

void *s21_memchr(const void *arr, int c, s21_size_t n) {
    int flag = 0;
    s21_size_t i;
    for( i =0; i<n; i++) {
        if (*((char*)arr + i) == c) {
            flag =1;
        }
    }
    if (flag ==1) {
        arr = (char*)arr + i;
    } else{
        arr =s21_NULL;
    }
    return (char*)arr;
}


int s21_memcmp(const void *arr1, const void *arr2, s21_size_t n) {
    s21_size_t  i;
    int flag = 0;
    const unsigned char *a1 = arr1;
    const unsigned char *a2 = arr2;

    for (i = 0; i < n; i++) {
        if (a1[i] == a2[i]) {
            flag =0;
        }
        if (a1[i] > a2[i]) {
            flag = a1[i] - a2[i];
            break;
        }
        if (a2[i] > a1[i]) {
            flag = a1[i] - a2[i];
            break;
        }
    }
    return flag;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    char *mem_dest = (char*)dest;
    const char *mem_src = (const char*)src;
    for (s21_size_t i = 0; i < n; i++) {
        mem_dest[i] = mem_src[i];
    }
    return mem_dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
    unsigned char *a1 = str;

    for(s21_size_t i = 0; i < n;i++) {
        a1[i] = (char)c;
    }
    return a1;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    s21_size_t len_dest = s21_strlen(dest);
    s21_size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[len_dest + i] = src[i];
    }
    dest[len_dest + i] = '\0';

    return dest;
}


char *s21_strchr(const char *str, int c) {
    do {
        if (*str == c) {
            return (char*)str;
        }
    } while (*str++);
    return (0);
}


int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    int flag=0;
    for (s21_size_t i =0; i< n; i++) {
        if (str1[i] == str2[i]) {
            flag =0;
        }
        if (str1[i] > str2[i]) {
            flag = str1[i] - str2[i];
            break;
        }
        if (str2[i] > str1[i]) {
            flag = str1[i] - str2[i];
            break;
        }
    }
    return flag;
}

char* s21_strncpy(char *dest, const char *src, s21_size_t n) {
    s21_size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t len = 0;
    while (*str1) {
        if (s21_strchr(str2,*str1)) {
            break;
        }
        else {
            len++;
            str1++;
        }
    }
    return len;
}



char *s21_strerror(int errnum) {
    static char *errlist[] = ERRLIST;
    static char unknown_error[64];
    char* error = s21_NULL;
    if (errnum >= 0 && errnum <= ERRLIST_LEN) {
        error = (char *)errlist[errnum];
    } else {
        #if defined (__APPLE__)
        s21_strncpy(unknown_error, "Unknown error: ", (s21_size_t)15);
        #elif defined (__linux__)
        s21_strncpy(unknown_error, "Unknown error ", (s21_size_t)14);
        #endif
        char unknown_error_code[10];
        s21_sprintf(unknown_error_code, "%d", errnum);
        s21_strncat(unknown_error, unknown_error_code, digits_count(errnum));
        error = unknown_error;
    }
    return error;
}

s21_size_t s21_strlen(const char *str) {
    s21_size_t count =0;
    s21_size_t i;

    for (i =0; str[i] !='\0';i++) {
        count++;
    }
    return  count;
}

char *s21_strpbrk(const char *str1, const char *str2) {
    s21_size_t i;
    s21_size_t k;
    int str1_len = s21_strlen(str1);
    int str2_len = s21_strlen(str2);
    char *res = s21_NULL;
    for (i = 0; i < str1_len; i++) {
        for (k= 0; k< str2_len; k++) {
            if (str1[i] == str2[k]) {
                res =  (char *)&str1[i];
                return res;
            }
        }
    }
    return res;
}
char *s21_strrchr(const char *str, int c) {
    int len = (int)s21_strlen(str);
    char *res = s21_NULL;

    for (int i = len; i >= 0; i--) {
        if (str[i] == c) {
            res = (char *)&str[i];
            break;
        }
    }
    return res;
}

char *s21_strstr(const char *haystack, const char *needle) {
    if (!*needle) {
        return (char *)haystack;
    }

    for (; *haystack; haystack++) {
        const char *h = haystack;
        const char *n = needle;

        while (*h && *n && *h == *n) {
            h++;
            n++;
        }

        if (!*n) {
            return (char *)haystack;
        }
    }

    return s21_NULL;
}


char *s21_strtok(char *str, const char *delim) {
    static char* last_token = s21_NULL;

    if (str == s21_NULL) {
        str = last_token;
    }
    if (str == s21_NULL || *str == '\0' || delim == s21_NULL) {
        return s21_NULL;
    }

    while (*str &&  s21_strchr(delim, *str) != s21_NULL) {
        str++;
    }

    if (*str == '\0') {
        last_token = s21_NULL;
        return s21_NULL;
    }

    char *start_token = str;
    str += s21_strcspn(str, delim);

    if (*str != '\0') {
        *str = '\0';
        last_token = str + 1;
    } else {
        last_token = s21_NULL;
    }

    return start_token;
}

void *s21_to_upper(const char *str) {
    s21_size_t length = 0;
    s21_size_t i = 0;
    char* buff = s21_NULL;
    if (str) {
        length = s21_strlen(str);
        buff = (char *)custom_calloc(length + 1, 1);
    }
    if (str) {
        for (; i < length; i++)
            if (str[i] >= 'a' && str[i] <= 'z') {
                buff[i] = str[i] - 32;
            } else {
                buff[i] = str[i];
            }
        }
    return buff;
}

void *s21_to_lower(const char *str) {
    s21_size_t length = 0;
    s21_size_t i = 0;
    char* buff = s21_NULL;
    if (str) {
        length = s21_strlen(str);
        buff = (char *)custom_calloc(length + 1, 1);
    }
    if (str) {
        for (; i < length; i++)
            if (str[i] >= 'A' && str[i] <= 'Z') {
                buff[i] = str[i] + 32;
            } else {
                buff[i] = str[i];
            }
        }
    return buff;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char* buff = s21_NULL;
    if ((src != s21_NULL) && (str != s21_NULL)) {
        s21_size_t src_length = s21_strlen(src);
        s21_size_t str_length = s21_strlen(str);
        if (start_index <= src_length) {
            buff = custom_calloc(src_length + str_length + 1, sizeof(char));
            if (buff != s21_NULL) {
                for (s21_size_t i = 0; i < start_index; i++) {
                    buff[i] = src[i];
                }
                for (s21_size_t i = 0; i < str_length; i++) {
                    buff[i + start_index] = str[i];
                }
                for (s21_size_t i = 0; i < src_length - start_index; i++) {
                    buff[i + start_index + str_length] = src[i + start_index];
                }
                buff[src_length + str_length] = 0;
            }
        }
    }
    return buff;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t len = 0;
    while (*str1 && s21_strchr(str2, *str1++)) {
        len++;
    }
    return len;
}

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