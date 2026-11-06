#include "bloom_filter.hpp"
#include <iostream>

int main() {
    BloomFilter bf(1024, 5);
    bf.insert("hello");
    std::cout << (bf.contains("hello") ? "Contains hello" : "Does not contain hello") << std::endl;
    std::cout << (bf.contains("world") ? "Contains world" : "Does not contain world") << std::endl;
    return 0;
}