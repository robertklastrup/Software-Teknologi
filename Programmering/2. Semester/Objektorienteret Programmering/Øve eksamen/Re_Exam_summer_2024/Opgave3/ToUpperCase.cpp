#include "ToUpperCase.h"


// Opgave 3 c)

void ToUpperCase::process(std::string& text){
    for (int i = 0; i < text.length(); i++){
        text[i] = static_cast<char>(toupper(text[i]));
    }
}
