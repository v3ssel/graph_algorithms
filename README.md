# Collection of Graph algorithms
Graph is implemented in adjacency matrix format, like:
```
SIZE
M A T
R I X
* * *
```
```
3
0 2 4
3 0 2
7 9 0
```
You can find example files in `src/assets` directory.

# Collection list
For now there are 8 algorithms and some graph operations:

In `graph.h` you can:
* Load graph from adjacency matrix
* Export graph as adjacency matrix
* Export graph in DOT format

In `graph_algorithms.h` implemented:
* Depth First Search
* Bread First Search
* Dijkstra algorithm for finding shortest path.
* Floyd-Warshall algorithm for finding shortest path between all vertices.
* Prim algorithm for finding least spanning tree.

And there are 3 traveling salesman problem solving algorithms in `src/graph/TSM` directory:
* Ant Colony Optimization algorithm
* Genetic Algorithm
* Branches and Bounds algorithm

# Console Interface

In addition, there are implemented console interface.

For building use:
```
make install
```
or
```
cmake . -B build && \
cmake --build build --target GraphApplication --config=Release
```

and launch:
```
./GraphApplication
```

# Library
You can build a static library only.

For building only graph, use:
```
make graph.a
```

For build with algorithms, use:
```
make graph_algorithms.a
```

Or you can use cmake directly, see `src/Makefile`

# Tests
There are some tests for these algorithms.
You can build and run them to check everything is fine.

For building use:
```
make tests
```
or
```
cmake . -B build && \
cmake --build build --target GraphTests --config=Release
```

and launch:
```
./GraphTests
```

### Note: Tests using src/assets files, make sure they are not edited.

