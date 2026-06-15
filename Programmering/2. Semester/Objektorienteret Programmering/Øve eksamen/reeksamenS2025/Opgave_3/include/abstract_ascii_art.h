#pragma once
#include "ascii_art.h"

class abstract_ascii_art : public ascii_art {
public:
    void render()const;
    virtual void render_line(unsigned int i) const = 0;
    virtual unsigned int height() const = 0;
};
