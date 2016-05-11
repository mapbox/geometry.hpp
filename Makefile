CXXFLAGS += -I include --std=c++14 -Wall -Wextra -Werror
MASON ?= .mason/mason

default: test

$(MASON):
	git submodule update --init

mason_packages: $(MASON)
	$(MASON) install variant 1.1.0

test: tests/* include/mapbox/geometry/* mason_packages Makefile
	$(CXX) tests/*.cpp $(CXXFLAGS) `$(MASON) cflags variant 1.1.0` -o test
	./test

clean:
	rm test
