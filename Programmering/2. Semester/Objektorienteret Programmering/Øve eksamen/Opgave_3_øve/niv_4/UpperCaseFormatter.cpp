#include "UpperCaseFormatter.h"
#include <string>


std::string UpperCaseFormatter::format(const std::string& text) const{
    std::string result = text;
    for(int i = 0; i < result.length(); i++){
        result[i] = static_cast<char>(toupper(text[i]));
    }
    return result;
}