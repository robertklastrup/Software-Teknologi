#pragma once
#include "Formatter.h"

class PrefixFormatter : public Formatter{
    private:
        std::string prefix_;
    public: 
        PrefixFormatter(std::string prefix);
        std::string format(const std::string& text) const;

};