all: 
	gcc -o s21_string.o -c s21_string.c 
	gcc -o s21_test.o -c -fprofile-arcs -ftest-coverage s21_test.c
	gcc -o s21_test s21_string.o s21_test.o -lcheck -fprofile-arcs -ftest-coverage
	./s21_test
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory coverage-html
	open coverage-html/index.html

clean:
	rm -rf *.o s21_test s21_test.gcda s21_test.gcno coverage-html coverage.info

rebuild: clean all