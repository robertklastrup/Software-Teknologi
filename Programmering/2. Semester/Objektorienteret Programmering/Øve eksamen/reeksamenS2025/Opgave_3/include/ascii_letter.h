#pragma once

#include <string>
#include <vector>

class ascii_letter {
public:
    ascii_letter(const std::vector<std::string> &init);

private:
    std::vector<std::string> data_;
};