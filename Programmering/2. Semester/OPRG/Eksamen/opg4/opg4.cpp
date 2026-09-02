#include "opg4.h"

Order::Order(int i, double a, std::string s){
    id = i;
    amount = a;
    status = s;
}

bool Order::isValid(){
    if (amount > 0 && (status == "PLACERET" || status == "PAKKET" || status == "AFSENDT" || status == "LEVERET")){
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
    std::cout << std::endl;
}

int Order::getID(){
    return id;
}
double Order::getAmount(){
    return amount;
}



double gennemsnit(std::vector<Order> ordre, int id){
    double sum = 0;
    int total = 0;

    for (int i = 0; i < ordre.size(); i++){
        if(ordre[i].getID() == id){
            sum = sum + ordre[i].getAmount();
            total++;
        }
        else{continue;}
    }
    return (sum / total);
}