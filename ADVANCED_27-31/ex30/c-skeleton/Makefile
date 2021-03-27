CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)
PREFIX=?/usr/local

SOURCES=$(wildcard src/**/*.c src/*.c)								# Gathers all of the source files in given directory		
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))								# Creates object files from every source file in given directory

TEST_SRC=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c, %, $(TEST_SRC))								# Create a full program out of test source folders

TARGET=build/libYOUR_LIBRARY.a										# YOUR_LIBRARY part will change accordingly to things that i am going to build
SO_TARGET=$(patsubst %.a, %.so, $(TARGET))

# The Target Build
all: $(TARGET) $(SO_TARGET) tests

dev: CFLAGS=-g -Wall -Isrc -Wall -Wextra $(OPTFLAGS)
dev: all

$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@
$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)

build:
	mkdir -p build
	mkdir -p bin

# The Unit Test
.PHONY: tests
tests: CFLAGS += $(TARGET)
tests: $(TESTS)
	sh ./tests/runtests.sh

# The Cleaner
clean:
	rm -rf build $(OBJECTS) $(TESTS)
	rm -f tests/tests.log
	find . -name "*.gc*" -exec rm {} \;
	rm -rf `find . -name "*.dSYM" -print`

# The Install
install: all
	install -d $(DESTDIR)/$(PREFIX)/lib/
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib

# The Checker
check:
	@echo Files with potentially dangereous functions.
	@egrep '[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)\
				|stpn?cpy|a?sn?printf|byte_)' $(SOURCES) || true
