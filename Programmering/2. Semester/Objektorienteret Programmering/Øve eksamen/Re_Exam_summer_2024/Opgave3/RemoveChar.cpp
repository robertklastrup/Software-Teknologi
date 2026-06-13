#include "RemoveChar.h"

// Opgave 3 g)

RemoveChar::RemoveChar(char c){
    this-> c = c;
}

void RemoveChar::process(std::string& text){
    auto it = text.begin();
    while(it != text.end()){
        if (*it == c){
            it = text.erase(it);
        }
        else{
            ++it;
            continue;
        }
    }
}