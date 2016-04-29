export MASON_DIR = $(shell pwd)/.mason
export MASON = $(MASON_DIR)/mason

$(MASON_DIR):
	git submodule update --init $(MASON_DIR)

mason_packages: $(MASON_DIR)
	$(MASON) install variant 1.1.0

test: tests/* mason_packages
	$(CXX) tests/*.cpp -std=c++14 -o test -I include `$(MASON) cflags variant 1.1.0`
	./test

clean:
	rm test

default: test
