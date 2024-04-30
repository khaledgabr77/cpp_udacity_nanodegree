# The compilation of course exercises and projects from the Udacity C++ Nanodegree.

Included Topics:

- Practice
- Fundamentals
- OOP Basics
- Memory Management
- Concurrency
- capstone project

All code files are compatible with C++17.

## Execute any practice program:

```bash
cd cpp_practice
g++ -std=c++17 main.cpp
./a.out
```

For running any concurrent(multi-threaded) program:

```bash
g++ -std=c++17 main.cpp -pthread
./a.out
```

## Run any project program

for example:

```bash
cd 1-CppND-Route-Planning-Project
mkdir build && cd build
cmake ..
make
./osm
```

