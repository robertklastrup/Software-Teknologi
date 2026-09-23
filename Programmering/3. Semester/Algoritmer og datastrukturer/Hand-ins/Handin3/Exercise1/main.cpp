#include "1.h"


int main (){
    std::vector <int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    if(search(2, v) == true){
        std::cout << "2 was found in the array" << std::endl;
    }
    else{
        std::cout << "2 was not found in the array" << std::endl;
    }

}