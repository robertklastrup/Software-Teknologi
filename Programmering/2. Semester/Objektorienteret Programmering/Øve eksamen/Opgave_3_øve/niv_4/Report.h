#pragma once
#include <vector>
#include "Formatter.h"

class Report{
    private:
        std::string text_;
        std::vector<Formatter*> formatters_;
    public:
        Report(std::string text);
        void add (Formatter* f);
        std::string process() const;
};