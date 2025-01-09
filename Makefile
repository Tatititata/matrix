CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -std=c11
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
CHECK_LIBS = -lcheck -lsubunit -lrt -lpthread -lm

TEST_DIR = ./tests
OBJ_DIR = ./build
SOURCES = $(wildcard *.c)
STATIC_LIB = ./s21_matrix.a
STATIC_LIB_GCOV = ./s21_matrix_gcov.a
MAIN_DIR = ./main_folder

TEST_EXECUTABLES = $(patsubst $(TEST_DIR)/test_%.c, $(TEST_DIR)/test_%, $(wildcard $(TEST_DIR)/test_*.c))


all: $(STATIC_LIB) tests

$(STATIC_LIB): clean
	$(CC) $(CFLAGS) -c $(SOURCES)
	ar rcs s21_matrix.a *.o
	ranlib s21_matrix.a

$(STATIC_LIB_GCOV): clean
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c $(SOURCES)
	ar rcs s21_matrix_gcov.a *.o
	ranlib s21_matrix_gcov.a

$(OBJ_DIR)/%.o: ./%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_DIR)/test_%: $(TEST_DIR)/test_%.c $(STATIC_LIB_GCOV)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $^ -o $@ $(CHECK_LIBS)

tests: $(TEST_EXECUTABLES)
	@echo "Running all tests..."
	@for test in $(TEST_EXECUTABLES); do \
		echo "Running $$test..."; \
		./$$test || exit 1; \
	done
	@echo "All tests passed!"
	

gcov_report: tests
	@echo "Generating coverage report..."
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory ./coverage_report
	@xdg-open ./coverage_report/index.html || echo "Could not open report"

clean:
	rm -f *.o
	rm -f $(STATIC_LIB) $(TEST_EXECUTABLES) $(OBJ_DIR)/*.o coverage.info
	rm -f $(TEST_DIR)/*.gcno $(TEST_DIR)/*.gcda 
	rm -f *.gcno *.gcda $(STATIC_LIB_GCOV)
	rm -f main 
	rm -rf $(OBJ_DIR) coverage_report

clean_tests:
	rm -f $(TEST_EXECUTABLES)

.PHONY: all tests tests gcov_report clean clean_tests

valgrind_tests: $(TEST_EXECUTABLES)
	@echo "Running tests with Valgrind..."
	@for test in $(TEST_EXECUTABLES); do \
		echo "Running $$test with Valgrind..."; \
		valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --trace-children=yes -s ./$$test 2>&1 | grep -e "ERROR" || true; \
	done
	@echo "end"

cl: *.c *.h main_folder/*.c main_folder/*.c 
	clang-format -i *.c *.h main_folder/*.c 

cpp: 
	cppcheck --enable=all --suppress=missingIncludeSystem ../decimals



main: $(MAIN_DIR)/main.c $(STATIC_LIB)
	$(CC) $(CFLAGS) $(MAIN_DIR)/main.c -o main -L. -l:s21_matrix.a
	./main


