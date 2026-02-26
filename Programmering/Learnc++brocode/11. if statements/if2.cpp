#include <iostream>


//Lad os finde på noget vi kan køre if statement på
//lad os gøre det for køb af alkohol



int main (){

    int age;
    double alkoholProcent;

    std::cout << "Indtast din alder" << '\n';
    std::cin >> age;


    if (age < 16){
        std::cout << "Er ikke gammel nok til at købe alkohol";
    }
    else if (age<=16<=17 && alkoholProcent >= 16){
        std::cout << "indtast alkoholprocent" << '\n';
        std::cin >> alkoholProcent;
        std::cout << "Du er ikke gammel nok til at købe alkohol over 16%";

    }
    else if (age<=16<=17 && alkoholProcent <= 16){
        std::cout << "indtast alkoholprocent" << '\n';
        std::cin >> alkoholProcent;
        std::cout << "Du er gammel nok til at købe alkohollen";

    }
    else if (age<=18){
        std::cout << "Du er gammel nok til at købe alkohollen";

    }
    else {
        std::cout << "Du er ikke gammel nok til at købe alkoholen";
    }
        


    return 0;
}