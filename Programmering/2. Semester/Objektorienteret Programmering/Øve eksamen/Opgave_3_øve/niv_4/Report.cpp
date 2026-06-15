#include "Report.h"
#include "PrefixFormatter.h"
#include <algorithm>

/*Metode std::string process() const — anvender alle formatters på text_ i rækkefølge og returnerer resultatet*/
Report::Report(std::string text){
    text_ = text;
}

void Report::add (Formatter* f){
    formatters_.push_back(f);
}

std::string Report::process() const{
    std::string result = text_;

    for (int i = 0; i < formatters_.size(); i++){
        result = formatters_[i]->format(result);
    }
    return result;
}