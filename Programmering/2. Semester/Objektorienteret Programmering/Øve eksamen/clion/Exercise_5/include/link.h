#pragma once

#include "cat.h"

class link {
public:
    link();

    explicit link(const cat &);

    link(const cat &, link *, link *);

    ~link();

    link *get_next();

    link *get_previous();

    void set_previous(link *);

    void set_next(link *);

    [[nodiscard]] cat *get_data();

private:
    link *next_;
    link *previous_;
    cat *data_;
};