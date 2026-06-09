#include "opg3.h"
#include <cctype>

SensorMåling::SensorMåling(std::string t, double v, std::string s){
    time = t;
    value = v;
    status = s;
}

bool SensorMåling::isValid(){
    if (status != "OK" && status != "ERROR" && status != "WARNING" && status != "OFFLINE"){
        return false;
    }

    // Tjek time format "TT:MM.SS"
    if (time.size() != 8) return false;
    if (time[2] != ':' || time[5] != '.') return false;

    for (int i = 0; i < 8; i++){
        if (i == 2 || i == 5) continue;
        if (!isdigit(time[i])) return false;
    }

    int tt = stoi(time.substr(0, 2));
    int mm = stoi(time.substr(3, 2));
    int ss = stoi(time.substr(6, 2));

    if (tt > 23) return false;
    if (mm > 59) return false;
    if (ss > 59) return false;

    return true;
}

void SensorMåling::makeValid(){
    if (!isValid()){
        status = "OK";
        time = "00:00.00";
        std::cout << "Eftersom objektet var invalid, er status nu = OK og time = 00:00.00" << std::endl;
    }
}
