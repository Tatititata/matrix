CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -std=c11
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
CHECK_FLAGS = -lcheck -lsubunit -lrt -lpthread -lm

TEST_DIR = ./tests
BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj
SOURCES = $(wildcard *.c)
STATIC_LIB = ./s21_matrix.a
TEST_SRC = $(wildcard $(TEST_DIR)/*.c) 
OBJECTS	 = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCES))


MAIN_DIR = ./main_folder


all: $(STATIC_LIB) tests

$(STATIC_LIB): $(OBJECTS)
	ar rcs $(STATIC_LIB) $(OBJECTS)
	ranlib $(STATIC_LIB)

$(OBJ_DIR)/%.o: ./%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

tests: 
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(SOURCES) $(TEST_SRC) -o unit_tests $(CHECK_FLAGS)
	./unit_tests 
	
	

gcov_report: tests
	@echo "Generating coverage report..."
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory ./coverage_report
	@xdg-open ./coverage_report/index.html || echo "Could not open report"

clean:
	rm -f *.o
	rm -f $(OBJ_DIR)/*.o coverage.info
	rm -f $(TEST_DIR)/*.gcno $(TEST_DIR)/*.gcda 
	rm -f *.gcno *.gcda $(STATIC_LIB_GCOV)
	rm -f main unit_tests
	rm -rf $(OBJ_DIR) coverage_report

clean_tests:
	rm -f $(TEST_DIR)/*.gcno $(TEST_DIR)/*.gcda 

clean_lib:
	rm -f $(STATIC_LIB) 

.PHONY: all tests tests gcov_report clean clean_tests

valgrind_tests: tests
	@echo "Running tests with Valgrind..."
	@for test in ./unit_tests; do \
		echo "Running $$test with Valgrind..."; \
		valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --trace-children=yes -s ./$$test 2>&1 | grep -e "ERROR" || true; \
	done
	@echo "end"

cl: *.c *.h main_folder/*.c tests/*.c 
	clang-format -i *.c *.h main_folder/*.c tests/*.c tests/*.h

cpp: 
	cppcheck --enable=all --suppress=missingIncludeSystem ../decimals



main: $(MAIN_DIR)/main.c $(STATIC_LIB)
	$(CC) $(CFLAGS) $(MAIN_DIR)/main.c -o main -L. -l:s21_matrix.a
	./main


