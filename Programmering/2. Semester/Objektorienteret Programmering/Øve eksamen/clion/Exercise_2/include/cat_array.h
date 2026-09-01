#pragma once

#include "cat.h"

class cat_array {
public:
    cat_array(int initial_size, int re_alloc_size);

    ~cat_array();

    void add(const std::string &name, int height, int weight);

    cat get(int index) const;

    int get_size() const;

    int get_array_size() const;

private:
    int size_;
    int head_;
    int re_alloc_size_;
    cat **array_;
};