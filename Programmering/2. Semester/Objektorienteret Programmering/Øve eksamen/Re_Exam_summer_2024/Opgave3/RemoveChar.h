#pragma once
#include "StringProcessor.h"

// Opgave 3 f)

class RemoveChar : public StringProcessor{
    private:
        char c;
    public:
        RemoveChar(char c);
        void process(std::string& text);

};