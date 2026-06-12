#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

//delopgave A
struct Studerende {
    std::string navn;
    int karakter;
};

//Delopgave B
bool sammenlign(Studerende a, Studerende b) {
        if (a.karakter < b.karakter){
            return true;
        }
        else{return false;}
}

//Delopgave C
bool harKarakter10 (Studerende s){
    return (s.karakter == 10);
}

//Delopgave D
int summer(int sum, Studerende s) {
    return sum + s.karakter;
}

int main (){

    //Delopgave A
    Studerende s1 {"Anna", 7};
    Studerende s2 {"Bo", 4};
    Studerende s3 {"Clara", 10};
    Studerende s4 {"David", 2};
    Studerende s5 {"Emma", 12};

    std::vector <Studerende> vec {s1, s2, s3, s4, s5};

    auto it = vec.begin();
    while( it!=vec.end()){
        std::cout << it->navn << std::endl; 
        ++it;
    }

    //Delopgave B
    

    std::sort(vec.begin(), vec.end(), sammenlign);
    it = vec.begin();
    while( it!=vec.end()){
        std::cout << it->navn << " "<< it->karakter << std::endl; 
        ++it;
    }
    
    //Delopgave C
    it = std::find_if(vec.begin(), vec.end(), harKarakter10);
    if (it != vec.end()){
        std::cout << it->navn << std::endl;
    }

    //Delopgave D
    int sum = std::accumulate(vec.begin(), vec.end(), 0, summer);
    int size = vec.size();
    double gennemsnit = (double)sum / size;

    std::cout << "Gennemsnit: " << gennemsnit << std::endl;
    
    

}