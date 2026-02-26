#ifndef CNCPOSITIONMEASUREMENT_H
#define CNCPOSITIONMEASUREMENT_H

#include <string>

class CNCPositionMeasurement
{
private:
    std::string id;
    std::string machineId;
    std::string time;  // "HH:MM"
    std::string day;   // "DD-MM-YYYY"
    float x;           // mm
    float y;           // mm
    float z;           // mm
    float roll;        // deg
    float pitch;       // deg
    std::string deg;   // "RAD" eller "360"

    // Hjælpefunktioner til validering (private, så kun klassen bruger dem)
    bool isValidTime(const std::string& t) const;
    bool isValidDay(const std::string& d) const;
    bool isValidDeg(const std::string& dg) const;

    bool isDigitChar(char c) const;
    int  toInt2(const std::string& s, int startIndex) const; // læser 2 cifre
    int  toInt4(const std::string& s, int startIndex) const; // læser 4 cifre

public:
    // Constructor: alle 10 attributter kan gives en værdi
    CNCPositionMeasurement(const std::string& id,
                           const std::string& machineId,
                           const std::string& time,
                           const std::string& day,
                           float x, float y, float z,
                           float roll, float pitch,
                           const std::string& deg);

    // Afstand fra objektets (x,y,z) til (x2,y2,z2)
    float distanceTo(float x2, float y2, float z2) const;

    // Gettere (praktisk til test i main)
    std::string getId() const;
    std::string getMachineId() const;
    std::string getTime() const;
    std::string getDay() const;
    float getX() const;
    float getY() const;
    float getZ() const;
    float getRoll() const;
    float getPitch() const;
    std::string getDeg() const;
};

#endif
