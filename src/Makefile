.POSIX:

CC := g++
CFLAGS := -Wall -Werror -Wextra -std=c++17
LFLAGS := -lgtest

LIB_A := s21_containers.a
LIB_CC := $(wildcard containers_src/*/*.cc)
LIB_CC += $(wildcard containersplus_src/*/*.cc)
LIB_O := $(patsubst %.cc,%.o,$(LIB_CC))
LIB_H := $(patsubst %.cc,%.h,$(LIB_CC))

TEST_CC := $(wildcard test_src/*.cc)

CODE := $(LIB_CC) $(TEST_CC) $(wildcard *.h) $(wildcard test_src/*.h) $(LIB_H)

define compile
	$(info # compile $@)
	$(CC) -o $@ $(CFLAGS) $(INCS) $(DFLAGS) $(1) $(filter %.cc,$^) $(LFLAGS)
endef

all: clean $(LIB_A)

clean:
	rm -f $(LIB_A) $(LIB_O) test *.info *.dSYM *.gcda *.gcno
	rm -rf report/

# LIBRARY BUILD
$(LIB_A): $(LIB_O)
	ar rcs $@ $(LIB_O)
	ranlib $@

.cc.o:
	$(call compile, -c)

# TESTS
test: $(LIB_CC) $(TEST_CC)
	$(call compile, --coverage)
	./test

gcov_report: test
	lcov -t "result" --no-external -o res.info -c -d .
	./result
	genhtml -o report res.info
	-open report/index.html

# LEAKS AND STYLE
check:
	clang-format -style=Google -n $(CODE)
	clang-format -style=Google -i $(CODE)
	cppcheck --enable=all --language=c++ --suppress=missingIncludeSystem $(CODE)

leaks: test
	leaks --atExit -- ./$(TEST_TARGET)

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test

.PHONY: all clean test gcov_report check leaks valgrind