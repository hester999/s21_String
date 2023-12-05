all: 
	gcc -o extra.o -c extra.c 
	gcc -o s21_string.o -c s21_string.c 
	gcc -o s21_test.o -c --coverage s21_test.c
	gcc -o s21_test s21_string.o s21_test.o extra.o -lcheck --coverage
	./s21_test
	lcov -c -d . -o coverage.info
	genhtml coverage.info -o coverage-html
	open coverage-html/index.html

clean:
	rm -rf *.o s21_test s21_test.gcda s21_test.gcno coverage-html coverage.info

rebuild: clean all