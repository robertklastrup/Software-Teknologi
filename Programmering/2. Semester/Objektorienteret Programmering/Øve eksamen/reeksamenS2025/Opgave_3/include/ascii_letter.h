#pragma once

#include <string>
#include <vector>
#include "abstract_ascii_art.h"

class ascii_letter : public abstract_ascii_art{
public:
    ascii_letter(const std::vector<std::string> &init);
    void render_line(unsigned int i) const override;
    unsigned int height() const override;

private:
    std::vector<std::string> data_;
};
