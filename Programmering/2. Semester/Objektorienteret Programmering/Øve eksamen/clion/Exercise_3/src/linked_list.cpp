#include <iostream>
#include "linked_list.h"

linked_list::linked_list() : size_(0) {}

linked_list::~linked_list() {
    link *p = head_.get_next();
    while (p != nullptr) {
        link *d = p->get_next();
        delete p;
        p = d;
    }
}

int linked_list::size() const {
    return size_;
}

void linked_list::insert_front(const cat &data) {
    link *node = new link(data, head_.get_next());
    head_.set_next(node);
    size_++;
}

void linked_list::delete_front() {

    link *to_delete = head_.get_next();
    if (to_delete == nullptr) {
        return;
    }
    size_--;
    head_.set_next(to_delete->get_next());
    delete to_delete;
}

link *linked_list::get(int index) {
    if (index < 0 || index > size_ - 1) {
        throw std::out_of_range("Out of range");
    }
    link *current_node = &head_;
    for (auto i = 0; i < index + 1; i++) {
        current_node = current_node->get_next();
    }
    return current_node;
}

void linked_list::insert_after(const cat &data, link *node) {
    link *new_link = new link(data, node->get_next());
    node->set_next(new_link);
    size_++;
}
std::string linked_list::to_string(){
    std::string res;
    link *p = head_.get_next();
    while (p != nullptr) {
        res.append(p->get_data()->to_string());
        res.append("\n");
        p = p->get_next();
    }
    return res;
}