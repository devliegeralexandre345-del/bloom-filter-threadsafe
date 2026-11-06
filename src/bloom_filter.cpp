#include "bloom_filter.hpp"
#include <functional>

BloomFilter::BloomFilter(size_t size, size_t num_hashes)
    : filter_(size), num_hashes_(num_hashes) {}

void BloomFilter::insert(const std::string& item) {
    std::lock_guard<std::mutex> lock(mutex_);
    for (size_t i = 0; i < num_hashes_; ++i) {
        size_t hash_value = hash(item, i) % filter_.size();
        filter_[hash_value] = true;
    }
}

bool BloomFilter::contains(const std::string& item) const {
    std::lock_guard<std::mutex> lock(mutex_);
    for (size_t i = 0; i < num_hashes_; ++i) {
        size_t hash_value = hash(item, i) % filter_.size();
        if (!filter_[hash_value]) return false;
    }
    return true;
}

size_t BloomFilter::hash(const std::string& str, size_t seed) const {
    std::hash<std::string> hasher;
    return hasher(str + static_cast<char>(seed));
}