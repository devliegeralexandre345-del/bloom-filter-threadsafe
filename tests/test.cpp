#include "bloom_filter.hpp"
#include <cassert>

int main() {
    BloomFilter bf(1024, 5);
    assert(!bf.contains("test"));
    bf.insert("test");
    assert(bf.contains("test"));
    return 0;
}