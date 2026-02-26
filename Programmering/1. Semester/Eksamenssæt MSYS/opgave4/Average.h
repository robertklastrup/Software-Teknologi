#ifndef AVERAGE_H
#define AVERAGE_H

#include <vector>
#include <string>
#include "CNCPositionMeasurement.h"

// Beregner gennemsnittet af en valgt værdi
double averageValue(const std::vector<CNCPositionMeasurement>& measurements,
                    const std::string& valueType);

#endif
