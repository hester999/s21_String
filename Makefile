CC = gcc
FLAGS = -Wall -Werror -Wextra

OBJECT_STRINGS = s21_insert.o s21_memchr.o s21_memcmp.o s21_memcpy.o s21_memset.o \
								s21_strchr.o s21_strspn.o s21_strerror.o s21_strlen.o s21_strncat.o \
								s21_strncat.o s21_strncmp.o s21_strncpy.o s21_strpbrk.o s21_strrchr.o \
								s21_strspn.o s21_strstr.o s21_strtok.o s21_to_lower.o s21_to_upper.o s21_trim.o


all: object_files s21_string.a test gcov_report

object_files:
	$(CC) $(FLAGS) -c string_functions/*.c --coverage
	$(CC) $(FLAGS) -c extra.c s21_convert.c
	gcc -c s21_test.c

s21_string.a: object_files
	ar rc s21_string.a $(OBJECT_STRINGS) extra.o s21_convert.o

test: object_files
	gcc -o s21_test *.o -lcheck --coverage
	./s21_test

gcov_report: object_files test
	lcov -c -d . -o coverage.info
	genhtml coverage.info -o coverage-html
	open coverage-html/index.html

clean:
	rm -rf *.o s21_test *.gcda *.gcno coverage-html coverage.info s21_string.a

rebuild: clean all