#pragma once

#include "ascii_art.h"
#include "abstract_ascii_art.h"
#include <vector>

class ascii_text : public abstract_ascii_art{
public:
    void add(ascii_art *);
    void render_line(unsigned int i) const override;
    unsigned int height() const override;
private:
    std::vector<ascii_art *> arts_;
};