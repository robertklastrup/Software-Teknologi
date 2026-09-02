#pragma once

#include <string>

class address {
public:
    address & set_street(const std::string&);
    address & set_number(int);
    address & set_floor(int);
    address & set_zip_code(const std::string&);
    address & set_city(const std::string&);
    address & set_country(const std::string&);
    std::string to_string();
private:
    std::string street_;
    int number_;
    int floor_;
    std::string zip_code_;
    std::string city_;
    std::string country_;

};