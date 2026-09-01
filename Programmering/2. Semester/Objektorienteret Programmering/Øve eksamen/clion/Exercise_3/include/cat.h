#pragma once

#include <string>

class cat {
public:
    cat(const std::string &name, int height, int weight);
    double body_mass_index() const;
    std::string to_string() const;

private:
    std::string name_;
    int height_;
    int weight_;
};