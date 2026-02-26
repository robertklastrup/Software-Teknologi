#include "CNCPositionMeasurement.h"
#include <cmath> 

CNCPositionMeasurement::CNCPositionMeasurement(const std::string& id,
                                               const std::string& machineId,
                                               const std::string& time,
                                               const std::string& day,
                                               float x, float y, float z,
                                               float roll, float pitch,
                                               const std::string& deg)
{
    // De "nemme" attributter (ingen krav om validering på id/machineId)
    this->id = id;
    this->machineId = machineId;

    // Defaultværdier vi selv vælger (bruges hvis input er ugyldigt)
    const std::string defaultTime = "00:00";
    const std::string defaultDay  = "01-01-1901";
    const std::string defaultDeg  = "360";

    // Validering af time
    if (isValidTime(time))
        this->time = time;
    else
        this->time = defaultTime;

    // Validering af day
    if (isValidDay(day))
        this->day = day;
    else
        this->day = defaultDay;

    // Position og orientering (ingen krav om validering på float-værdier)
    this->x = x;
    this->y = y;
    this->z = z;
    this->roll = roll;
    this->pitch = pitch;

    // Validering af deg
    if (isValidDeg(deg))
        this->deg = deg;
    else
        this->deg = defaultDeg;
}

float CNCPositionMeasurement::distanceTo(float x2, float y2, float z2) const
{
    // 3D afstand: sqrt(dx^2 + dy^2 + dz^2)
    float dx = x - x2;
    float dy = y - y2;
    float dz = z - z2;

    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

// ---------- Private hjælpefunktioner ----------

bool CNCPositionMeasurement::isDigitChar(char c) const
{
    return (c >= '0' && c <= '9');
}

int CNCPositionMeasurement::toInt2(const std::string& s, int startIndex) const
{
    // Forventer to cifre: s[startIndex] og s[startIndex+1]
    int tens = s[startIndex] - '0';
    int ones = s[startIndex + 1] - '0';
    return tens * 10 + ones;
}

int CNCPositionMeasurement::toInt4(const std::string& s, int startIndex) const
{
    // Forventer fire cifre
    int a = s[startIndex]     - '0';
    int b = s[startIndex + 1] - '0';
    int c = s[startIndex + 2] - '0';
    int d = s[startIndex + 3] - '0';
    return a * 1000 + b * 100 + c * 10 + d;
}

bool CNCPositionMeasurement::isValidTime(const std::string& t) const
{
    // Format: "HH:MM" (længde 5, ':' i midten)
    if (t.length() != 5) return false;
    if (t[2] != ':') return false; //Det er 3 plads i array, hvis den ikke er : er det ikke godt.

    // Tjek at de relevante tegn er cifre
    if (!isDigitChar(t[0]) || !isDigitChar(t[1]) || !isDigitChar(t[3]) || !isDigitChar(t[4]))
        return false;

    int hh = toInt2(t, 0);
    int mm = toInt2(t, 3);

    if (hh < 0 || hh > 23) return false;
    if (mm < 0 || mm > 59) return false;

    return true;
}

bool CNCPositionMeasurement::isValidDay(const std::string& d) const
{
    // Format: "DD-MM-YYYY" (længde 10, '-' på position 2 og 5)
    if (d.length() != 10) return false;
    if (d[2] != '-' || d[5] != '-') return false;

    // Tjek cifre i DD, MM og YYYY
    if (!isDigitChar(d[0]) || !isDigitChar(d[1])) return false;
    if (!isDigitChar(d[3]) || !isDigitChar(d[4])) return false;
    if (!isDigitChar(d[6]) || !isDigitChar(d[7]) || !isDigitChar(d[8]) || !isDigitChar(d[9]))
        return false;

    int dd = toInt2(d, 0);
    int mm = toInt2(d, 3);
    int yy = toInt4(d, 6);

    // Krav: DD 01-31, MM 01-12, YYYY > 1900
    if (dd < 1 || dd > 31) return false;
    if (mm < 1 || mm > 12) return false;
    if (yy <= 1900) return false;

    return true;
}

bool CNCPositionMeasurement::isValidDeg(const std::string& dg) const
{
    // Krav: "RAD" eller "360"
    return (dg == "RAD" || dg == "360");
}

// ---------- Gettere ----------

std::string CNCPositionMeasurement::getId() const { return id; }
std::string CNCPositionMeasurement::getMachineId() const { return machineId; }
std::string CNCPositionMeasurement::getTime() const { return time; }
std::string CNCPositionMeasurement::getDay() const { return day; }
float CNCPositionMeasurement::getX() const { return x; }
float CNCPositionMeasurement::getY() const { return y; }
float CNCPositionMeasurement::getZ() const { return z; }
float CNCPositionMeasurement::getRoll() const { return roll; }
float CNCPositionMeasurement::getPitch() const { return pitch; }
std::string CNCPositionMeasurement::getDeg() const { return deg; }
