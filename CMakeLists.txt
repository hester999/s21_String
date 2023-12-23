cmake_minimum_required(VERSION 3.26)
project(String C)
set(CMAKE_C_STANDARD 11)

add_executable(String main.c
        s21_string.c
        s21_string.h
        s21_convert.c
        s21_convert.h
        s21_parse.c
        s21_sscanf.c
        s21_sscanf.h
)


#target_compile_options(String PRIVATE -Wall -Werror -Wextra)
