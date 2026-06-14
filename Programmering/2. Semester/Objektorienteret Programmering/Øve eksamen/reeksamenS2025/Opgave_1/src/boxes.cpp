#include "boxes.h"

#include <algorithm>

void boxes::add_box(const box &b) {
    boxes_.emplace_back(b);
}

std::string boxes::to_string()const
{
    std::string boxes;
    std::string box;
    for (int i = 0; i < boxes_.size(); i++)
    {
        box = std::to_string (boxes_[i].volume());
        boxes = boxes + " " + box;
    }
    return boxes;
}


std::string boxes::to_string_sorted()const
{
    std::vector <double> boxes;
    for (int i = 0; i < boxes_.size(); i++)
    {
        boxes.push_back(boxes_[i].volume());
    }
    std::sort(boxes.begin(), boxes.end());

    std::string boxes_string;
    std::string box_string;
    for (int i = 0; i < boxes.size(); i++)
    {
        box_string = std::to_string (boxes[i]);
        boxes_string= boxes_string + " " + box_string;
    }
    return boxes_string;
}