#include "opg5.h"


Order::Order(int i, double a, Status s){
    id = i;
    amount = a;
    status = s;
}

bool Order::isValid(){
    if (amount > 0){
        return true;
    }
    else{return false;}

}
void Order::makeValid(){
    if(isValid() == false){
        if(amount <= 0){
            amount = 1;
        }
    }
}

void Order::print(){
    std::cout << "Order: " << id << std::endl;
    std::cout << "Amount: " << amount << std::endl;
    std::cout << "Status: " << status << std::endl;
    std::cout << std::endl;
}

int Order::getID(){
    return id;
}
double Order::getAmount(){
    return amount;
}

Status Order::getStatus(){
    return status;
}


double gennemsnit(std::vector<Order> ordre){
    double sum = 0;
    int total = 0;

    for (int i = 0; i < ordre.size(); i++){
        if(ordre[i].getStatus() == AFSENDT || ordre[i].getStatus() == LEVERET){
            sum = sum + ordre[i].getAmount();
            total++;
        }
        else{continue;}
    }
    return (sum / total);
}


Firma::Firma(std::string n, std::vector<Order> o){
    navn = n;
    ordre = o;
    
}
double Firma::firma_gennemsnit(){
    return gennemsnit(ordre);
}

void Firma::opretOrdre(Order o){
    ordre.push_back(o);
}