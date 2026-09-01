#include "link.h"

link::link() : previous_(nullptr), next_(nullptr), data_(nullptr) {}

link::link(const cat &data) : previous_(nullptr), next_(nullptr), data_(new cat(data)) {}

link::link(const cat &data, link *previous, link *next) : previous_(previous), next_(next), data_(new cat(data)) {}

link::~link() {
    delete data_;
}

cat *link::get_data() {
    return data_;
}

void link::set_previous(link *node) {
    previous_ = node;
}

void link::set_next(link *node) {
    next_ = node;
}

link *link::get_previous() {
    return previous_;
}

link *link::get_next() {
    return next_;
}