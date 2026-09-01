#include "link.h"

link::link() : next_(nullptr), data_(nullptr) {}

link::link(const cat &data) : next_(nullptr), data_(new cat(data)) {}

link::link(const cat &data, link *node) : next_(node), data_(new cat(data)) {}

link::~link() {
    delete data_;
}

cat *link::get_data() {
    return data_;
}

void link::set_next(link *node) {
    next_ = node;
}

link *link::get_next() {
    return next_;
}