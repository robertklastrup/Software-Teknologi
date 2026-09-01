#include "cat.h"

cat::cat(const std::string &name, int height, int weight) : name_(name), height_(height), weight_(weight) {}

double cat::body_mass_index() const {
    return height_ / static_cast<double>(weight_);
}

std::string cat::to_string() const {
    return "Name:" + name_ + "  BMI:" + std::to_string(body_mass_index());
}