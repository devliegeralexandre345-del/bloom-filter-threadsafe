#ifndef BLOOM_FILTER_HPP
#define BLOOM_FILTER_HPP

#include <vector>
#include <string>
#include <functional>
#include <mutex>

class BloomFilter {
public:
    BloomFilter(size_t size, size_t num_hashes);
    void insert(const std::string& item);
    bool contains(const std::string& item) const;

private:
    std::vector<bool> filter_;
    size_t num_hashes_;
    mutable std::mutex mutex_;

    size_t hash(const std::string& str, size_t seed) const;
};

#endif // BLOOM_FILTER_HPP