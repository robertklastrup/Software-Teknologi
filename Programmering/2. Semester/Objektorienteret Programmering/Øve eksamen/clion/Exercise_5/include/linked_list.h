#pragma once

#include "link.h"
#include "cat.h"

class linked_list{
public:
    linked_list();
    ~linked_list();
    void insert_front(const cat &);
    void insert_end(const cat &);
    cat* get_front();
    cat* get_end();
    [[nodiscard]] int size() const;
    void delete_front();
    void delete_end();
    link *get(int index);
    void insert_after(const cat &, link *);
    std::string to_string();

private:
    int size_;
    link head_;
    link tail_;

};