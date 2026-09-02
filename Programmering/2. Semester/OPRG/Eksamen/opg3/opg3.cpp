#include "opg3.h"

/*
Implementér en klasse Order med attributter: id (int), amount (double), status (string).
Krav: 
constructor initialiserer alle attributer.
objektet er gyldig hvis amount>0 og status =“PLACERET”. 
Implementér en metode - isValid() – som returnerer om objektet er gyldigt (dvs amount > 0 og 
status har en af følgende værdier: ”PLACERET”, ”PAKKET”, AFSENDT” eller ”LEVERET”. 
Lav derudover en metode – makeValid() – som gør objektet lovligt (amount sættes til 1 og status til
”PLACERET”) hvis det ikke er lovligt (brug isValid() til at checke om det er). 

*/

Order::Order(int i, double a, std::string s){
    id = i;
    amount = a;
    status = s;
}

bool Order::isValid(){
    if (amount > 0 && (status == "PLACERET" || status == "PAKKET" || status == "AFSENDT" || status == "LEVERET" && id > 0)){
        return true;
    }
    else{return false;}

}
void Order::makeValid(){
    if(isValid() == false){
        if(amount <= 0){
            amount = 1;
        }
        if(status != "PLACERET" && status != "PAKKET" && status != "AFSENDT" && status != "LEVERET"){
            status = "PLACERET";
        }
        
    }
}

void Order::print(){
    std::cout << "Order: " << id << std::endl;
    std::cout << "Amount: " << amount << std::endl;
    std::cout << "Status: " << status << std::endl;
    std::cout << "Verify " << isValid() << std::endl;
    std::cout << std::endl;
}