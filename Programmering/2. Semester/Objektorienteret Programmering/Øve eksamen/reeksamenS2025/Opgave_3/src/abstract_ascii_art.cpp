#include "abstract_ascii_art.h"

#include <iostream>
#include <ostream>

/*void render() const: Implementation af render har ansvar for at rendere hele ascii figuren.
Der følger nu en mere detaljeret forklaring af hvert af de nedarvende klasser*/

void abstract_ascii_art::render()const
{
    for (int i = 0; i < height(); i++)
    {
        render_line(i);
        std::cout << std::endl;
    }
}