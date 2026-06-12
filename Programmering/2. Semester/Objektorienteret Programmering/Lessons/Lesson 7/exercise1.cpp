#include    <iostream>
#include    <string>
#include    <iomanip>
#include    <sstream>

// resistor-klasse med modstand i Ohm:
class resistor {
    public:
        // sætter modstandsværdi:
        resistor(double resistance){
            resistance_ = resistance;
        };

        // returnerer modstand som formateret string:
        std::string to_string() const{
            std::stringstream ss;
            ss << std::fixed << std::setprecision(2) << resistance_;
            return "Resistance: " + ss.str() + " Ohm";
        };

        // lægger to modstande sammen (seriekobling):
        resistor add(const resistor& other) const{
            return resistor(resistance_ + other.resistance_);
        }

        // ganger to modstande (parallel formel tæller):
        resistor multiply(const resistor& other) const{
            return resistor((resistance_ * other.resistance_));
        }

        // dividerer to modstande:
        resistor divide(const resistor& other) const{
            return resistor (resistance_ / other.resistance_);
        }

    private:
        double resistance_;
};



int main (){
    // opretter to modstande og beregner sum, produkt, kvotient:
    resistor r1(50);
    resistor r2(20);
    resistor r3 = r1.add(r2);
    resistor r4 = r1.multiply(r2);
    resistor r5 = r1.divide(r2);

    std::cout << r1.to_string() << std::endl;
    std::cout << r2.to_string() << std::endl;
    std::cout << r3.to_string() << std::endl;
    std::cout << r4.to_string() << std::endl;
    std::cout << r5.to_string() << std::endl;

    return 0;
}
