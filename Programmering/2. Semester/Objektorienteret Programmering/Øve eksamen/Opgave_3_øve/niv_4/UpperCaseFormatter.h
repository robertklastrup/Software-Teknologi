#include "Formatter.h"

class UpperCaseFormatter : public Formatter{
    public:
        std::string format(const std::string& text) const;
};