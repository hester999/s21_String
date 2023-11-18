#include "s21_string.h"
#include "string.h"


void *s21_memchr(const void *arr, int c, s21_size_t n){
    int flag = 0;
    s21_size_t i;
    for( i =0; i<n; i++){
        if (*((char*)arr + i) == c){
            flag =1;
        }
    }
    if(flag ==1){
        arr = (char*)arr + i;
    }else{
        arr =s21_NULL;
    }
    return (char*)arr;
}


int s21_memcmp(const void *arr1, const void *arr2, s21_size_t n){
    s21_size_t  i;
    int flag = 0;
    const unsigned char *a1 = arr1;
    const unsigned char *a2 = arr2;

    for(i=0; i<n;i++){
        if(a1[i] == a2[i]){
            flag =0;
        }
        if(a1[i]> a2[i]){
            flag = a1[i] - a2[i];
            break;
        }
        if(a2[i]> a1[i]){
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

void *s21_memset(void *str, int c, s21_size_t n){
    unsigned char *a1 = str;

    for(s21_size_t i=0; i<n;i++){
        a1[i] = (char)c;
    }
    return a1;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    s21_size_t len_dest = strlen(dest); // заменить strlen на s21_strlen
    s21_size_t len_src = strlen(src);

    s21_size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[len_dest + i] = src[i];
    }
    dest[len_dest + i] = '\0';

    return dest;
}


char *s21_strchr(const char *str, int c){
    do {
        if (*str == c) {
            return (char*)str;
        }
    } while (*str++);
    return (0);
}


int s21_strncmp(const char *str1, const char *str2, s21_size_t n){
    int flag=0;
    for(s21_size_t i =0; i< n; i++){
        if(str1[i] == str2[i]){
            flag =0;
        }
        if(str1[i]> str2[i]){
            flag = str1[i] - str2[i];
            break;
        }
        if(str2[i]> str1[i]){
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
    dest[i] = '\0';//     узнать почему не работает  dest[i+1] ='\0'
    return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2){
    s21_size_t len = 0;
    while(*str1){
        if(s21_strchr(str2,*str1)){
            break;
        }
        else{
            len++;
            str1++;
        }
    }
    return len;
}

//char *strerror(int errnum){
//
//}

s21_size_t s21_strlen(const char *str){
    s21_size_t count =0;
    s21_size_t i;

    for(i =0; str[i] !='\0';i++){
        count++;
    }
    return  count;
}

char *s21_strpbrk(const char *str1, const char *str2){
    s21_size_t i;
    s21_size_t k;
    int str1_len = s21_strlen(str1);
    int str2_len = s21_strlen(str2);

    for(i=0;i< str1_len; i++){
        for(k= 0; k< str2_len; k++){
            if(str1[i] == str2[k]) {
                return (char *)&str1[i];
            }
        }
    }
    return NULL;
}
