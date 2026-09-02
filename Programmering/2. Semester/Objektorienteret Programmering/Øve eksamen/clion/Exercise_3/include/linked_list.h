#pragma once

#include "link.h"
#include "cat.h"

class linked_list{
public:
    linked_list();

    ~linked_list();

    void insert_front(const cat &);

    [[nodiscard]] int size() const;

    void delete_front();

    link *get(int index);

    void insert_after(const cat &, link *);

    std::string to_string();

private:
    int size_;
    link head_;
};