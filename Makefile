CFLAGS += -I include --std=c++14 -Wall -Wextra -Werror

export MASON_DIR = $(shell pwd)/.mason
export MASON = $(MASON_DIR)/mason

$(MASON_DIR):
	git submodule update --init $(MASON_DIR)

mason_packages: $(MASON_DIR)
	$(MASON) install variant 1.1.0

test: tests/* include/mapbox/geometry/* mason_packages Makefile
	$(CXX) tests/*.cpp $(CFLAGS) `$(MASON) cflags variant 1.1.0` -o test
	./test

clean:
	rm test

default: test
