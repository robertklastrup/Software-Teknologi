#include "ToLowerCase.h"
// Opgave 3 e)


void ToLowerCase::process(std::string& text){
    for (int i = 0; i < text.length(); i++){
        text[i] = static_cast<char>(tolower(text[i]));
    }
}


