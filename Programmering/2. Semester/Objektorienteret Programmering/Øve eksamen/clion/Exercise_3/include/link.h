#pragma once

#include "cat.h"

class link{
public:
    link();

    explicit link(const cat &);

    link(const cat &, link *);

    ~link();

    link *get_next();

    void set_next(link *);

    [[nodiscard]] cat *get_data();

private:
    link *next_;
    cat *data_;
};