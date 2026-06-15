#include <stdexcept>
#include "ascii_art.h"
#include "ascii_text.h"
#include <iostream>


void ascii_text::add(ascii_art *art) {
    if (!arts_.empty() && art->height() != arts_.back()->height()) {
        throw std::invalid_argument("added art is of wrong height");
    }
    arts_.push_back(art);

}

void ascii_text::render_line(unsigned int i) const
{
    for (const auto &art : arts_)
    {
        art->render_line(i);
    }
}

unsigned int ascii_text::height() const
{
    int x = arts_.size();
    if (x > 0)
    {
        return arts_.back()->height();
    }
    else
    {
        return 0;
    }
}