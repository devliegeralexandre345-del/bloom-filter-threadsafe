# Bloom Filter Threadsafe
A simple and thread-safe implementation of a Bloom Filter in C++20 using the STL.

## Compilation
```bash
cmake -S . -B build
cmake --build build
```

## Running Tests
```bash
cmake --build build --target test
ctest --test-dir build
```