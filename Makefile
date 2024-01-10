CC = gcc
FLAGS = -Wall -Werror -Wextra -std=c11

OBJECT_STRINGS = s21_insert.o s21_memchr.o s21_memcmp.o s21_memcpy.o s21_memset.o \
								s21_strchr.o s21_strcspn.o s21_strerror.o s21_strlen.o s21_strncat.o \
								s21_strncat.o s21_strncmp.o s21_strncpy.o s21_strpbrk.o s21_strrchr.o \
								s21_strstr.o s21_strtok.o s21_to_lower.o s21_to_upper.o s21_trim.o

all: s21_string.a test gcov_report

s21_string.a:
	$(CC) $(FLAGS) -c string_functions/*.c
	$(CC) $(FLAGS) -c s21_sscanf.c
	$(CC) $(FLAGS) -c s21_sprintf.c
	$(CC) $(FLAGS) -c extra.c s21_convert.c s21_parse.c
	ar rc s21_string.a $(OBJECT_STRINGS) extra.o s21_convert.o s21_sscanf.o s21_sprintf.o parse.o
	rm -rf *.o

test:
	$(CC) $(FLAGS) -c string_functions/*.c --coverage
	$(CC) -c s21_sscanf.c --coverage
	$(CC) $(FLAGS) -c s21_sprintf.c --coverage
	$(CC) -c extra.c s21_convert.c s21_parse.c
	$(CC) -c s21_test.c 
	$(CC) -o s21_test *.o -lcheck --coverage
	./s21_test

gcov_report: test
	lcov -c -d . -o coverage.info
	genhtml coverage.info -o coverage-html
	open coverage-html/index.html

clean:
	rm -rf *.o s21_test *.gcda *.gcno coverage-html coverage.info s21_string.a

rebuild: clean all