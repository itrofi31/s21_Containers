.POSIX:

CC := g++
CFLAGS := -Wall -Werror -Wextra -std=c++17 -g
LFLAGS := -lgtest

LIB_H := $(wildcard containers_src/*/*.h)
LIB_H += $(wildcard containersplus_src/*/*.h)
LIB_TPP := $(patsubst %.h,%.tpp,$(LIB_H))

TEST_CC := $(wildcard test_src/*.cc)

CODE := $(TEST_CC) $(wildcard *.h) $(wildcard test_src/*.h) $(LIB_H) $(LIB_TPP)

define compile
	$(info # compile $@)
	$(CC) -o $@ $(CFLAGS) $(INCS) $(DFLAGS) $(1) $(filter %.cc,$^) $(LFLAGS) -fsanitize=address
endef

all: clean test

clean:
	rm -f test *.info  *.gcda *.gcno valgrind.log
	rm -rf report/ *.dSYM

# TESTS
test: $(TEST_CC)
	$(call compile, --coverage)
	./test

gcov_report: test
	lcov -t "result" --no-external -o res.info -c -d .  --ignore-errors inconsistent
	genhtml -o report res.info  --ignore-errors inconsistent 
	-open report/index.html

# LEAKS AND STYLE
check:
	clang-format -style=Google -n $(CODE)
	clang-format -style=Google -i $(CODE)
	cppcheck --enable=all --language=c++ --suppress=missingIncludeSystem $(CODE)

leaks: test
	leaks --atExit -- ./test

valgrind: test
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --log-file="valgrind.log" \
	-v --verbose -q --quiet -s ./test

.PHONY: all clean gcov_report check leaks valgrind