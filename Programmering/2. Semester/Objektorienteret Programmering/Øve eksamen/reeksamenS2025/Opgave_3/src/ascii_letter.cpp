#include "ascii_letter.h"

#include <iostream>
#include <ostream>

ascii_letter::ascii_letter(const std::vector<std::string> &init):data_(init) {
}



void ascii_letter::render_line(unsigned int i) const
{
    std::cout << data_[i];
}
unsigned int ascii_letter::height() const
{
    return data_.size();
}