PROJECTDIR = $(CURDIR)
TEST_EXE = GraphTests
BUILDDIR=build

ifeq ($(shell uname), Darwin)
	COMPILER21 = -DCMAKE_CXX_COMPILER="/usr/local/bin/g++"
endif


.PHONY: tests graph.a graph_algorithms.a
all: graph.a graph_algorithms.a install tests clean


install:
	cmake . -G "Unix Makefiles" -B $(BUILDDIR) && \
	cmake --build $(BUILDDIR) --target GraphApplication --config=Release


graph.a:
	cmake . -G "Unix Makefiles" -B $(BUILDDIR) && \
	cmake --build $(BUILDDIR) --target graph --config=Release


graph_algorithms.a:
	cmake . -G "Unix Makefiles" -B $(BUILDDIR) && \
	cmake --build $(BUILDDIR) --target graph_algorithms --config=Release


tests:
	cmake . -G "Unix Makefiles" -B $(BUILDDIR) && \
	cmake --build $(BUILDDIR) --target GraphTests --config=Release
	./$(TEST_EXE)


clean:
	rm -rf build *.a $(TEST_EXE)

