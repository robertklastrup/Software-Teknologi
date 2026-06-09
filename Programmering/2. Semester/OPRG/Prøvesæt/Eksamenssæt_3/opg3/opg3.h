#include <iostream>


/*
Implementér en UML-klasse SensorMåling med attributter: time (string), value (double), status
(string).
Krav: constructor initialiserer alle attributter. 
Objektet er gyldigt hvis status er en af følgende værdier:
”OK”, ”ERROR”, ”WARNING” eller ”OFFLINE” og time er på formen ”TT:MM.SS” hvor TT er mellem 00 og
23, MM og SS mellem 00 og 59. 
Implementér en metode - isValid() – som returnerer om objektet er gyldigt. 
Lav derudover en metode – makeValid() – som gør objektet lovligt (status sættes til ”OK” og
time til ”00:00:00”) hvis det ikke er lovligt (brug isValid() til at checke om det er). 

*/

class SensorMåling{
    private:
        std::string time;
        double value;
        std::string status;
    public:
        SensorMåling(std::string t, double v, std::string s);
        bool isValid();
        void makeValid();
};