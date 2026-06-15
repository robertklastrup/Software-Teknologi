#include "PrefixFormatter.h"

PrefixFormatter::PrefixFormatter(std::string prefix){
    prefix_ = prefix;
}
std::string PrefixFormatter::format(const std::string& text) const{
    std::string result = prefix_ + text;
    return result;
}