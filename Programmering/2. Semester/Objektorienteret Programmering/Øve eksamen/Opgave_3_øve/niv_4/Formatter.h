#pragma once
#include <string>


class Formatter{
    public:
        virtual std::string format(const std::string& text) const = 0;
};