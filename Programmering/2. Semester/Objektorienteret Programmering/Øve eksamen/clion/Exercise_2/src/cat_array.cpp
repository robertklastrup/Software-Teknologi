#include "cat_array.h"
#include <stdexcept>

cat_array::cat_array(int initial_size, int re_alloc_size)
        : size_(initial_size), head_(0), re_alloc_size_(re_alloc_size) {
    array_ = new cat *[size_]{};
}

int cat_array::get_size() const {
    return head_;
}

int cat_array::get_array_size() const {
    return size_;
}

cat cat_array::get(int index) const {
    if (index<0||index + 1 > head_) {
        throw std::out_of_range("Index out of range");
    }
    return *array_[index];
}

void cat_array::add(const std::string &name, int height, int weight) {
    if (head_ == size_) {
        cat **ptr = new cat *[size_ + re_alloc_size_];
        for (auto i = 0; i < size_; i++) {
            ptr[i] = array_[i];
        }
        size_ += re_alloc_size_;
        delete[] array_;
        array_ = ptr;
    }
    array_[head_++] = new cat(name, height, weight);
}

cat_array::~cat_array() {
    for (auto i = 0; i < head_; i++) {
        delete array_[i];
    }
    delete[] array_;
}
