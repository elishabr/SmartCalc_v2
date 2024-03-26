SHELL = /bin/sh 

GCC := g++ -Werror -Wextra -Wall --std=c++17 -lstdc++ -lm
SANITIZER :=  -fsanitize=address
SOURSE :=  Test_Calc_v2/*.cc Calc_v2/Model/*.cc
FLAGS_LCOV := -g -fprofile-arcs -ftest-coverage
FLAGS_GTEST := -lgtest -lgcov -pthread
OS = $(shell uname)


all: install

install: uninstall
	@mkdir build
	cd Calc_v2 && qmake && make && make clean && rm Makefile && mv Calc2_0.app ../build
	cd build/Calc2_0.app/Contents/MacOS && ./Calc2_0
open:
	cd build/Calc2_0.app/Contents/MacOS && ./Calc2_0
uninstall:
	@rm -rf build
test: clean
	$(GCC) $(FLAGS_LCOV) $(SOURSE) $(FLAGS_GTEST) -o s21_test_calc
	./s21_test_calc
gcov_report: test
	@lcov --ignore-errors mismatch -t test -o rep.info -c -d .
	@genhtml -o report rep.info
	@rm -rf gcovreport gcovreport.info *.gcda *.gcno math_test.gcda math_test.gcno
	@open ./report/index.html
check: test
	clang-format --style=Google -n $(shell find . -name '*.cc') $(shell find . -name '*.h') $(shell find . -name '*.cpp')
	clang-format --style=Google -i $(shell find . -name '*.cc') $(shell find . -name '*.h') $(shell find . -name '*.cpp')
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config Calc_v2/Model/*.*
ifeq ($(OS), Darwin)
	leaks --atExit -- ./s21_test_calc
else
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./s21_test_calc
endif

dvi:
	open ../readme.md
dist:
	@rm -rf ../Calc2_0-2.0/
	@mkdir ../Calc2_0-2.0/
	@mkdir ../Calc2_0-2.0/src
	@cp build/Calc2_0.app/Contents/MacOS/Calc2_0 ../Calc2_0-2.0/src/
	cd .. && tar cvzf Calc2_0-2.0.tgz ./Calc2_0-2.0
clean:
	rm -rf s21_test_calc
	rm -rf *.o test *.a a.out *.gcno *.gcda s21_test_calc.dSYM *.info report *.gch *.txt


