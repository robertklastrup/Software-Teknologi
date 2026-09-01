#include "address.h"

address &address::set_street(const std::string &street) {
    street_ = street;
    return *this;
}

address &address::set_number(int number) {
    number_ = number;
    return *this;
}

address &address::set_floor(int floor) {
    floor_ = floor;
    return *this;
}

address &address::set_zip_code(const std::string &zip_code) {
    zip_code_ = zip_code;
    return *this;
}

address &address::set_city(const std::string &city) {
    city_ = city;
    return *this;
}

address &address::set_country(const std::string &country) {
    country_ = country;
    return *this;
}

std::string address::to_string() {
    std::string res;
    res.append("Street:");
    res.append(street_);
    res.append("\n");
    res.append("Number:");
    res.append(std::to_string(number_));
    res.append("\n");
    res.append("Floor:");
    res.append(std::to_string(floor_));
    res.append("\n");
    res.append("Zip Code:");
    res.append(zip_code_);
    res.append("\n");
    res.append("City:");
    res.append(city_);
    res.append("\n");
    res.append("Country:");
    res.append(country_);
    res.append("\n");
    return res;
}