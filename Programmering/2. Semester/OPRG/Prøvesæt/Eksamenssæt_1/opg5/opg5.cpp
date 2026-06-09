#include "opg5.h"


Student::Student(std::string n, int a, Karakter g){
    name = n;
    age = a;
    grade = g;
}
//Grundet at vi bruger enum, kan man ikke bruge en anden karakter end dem der er defineret i vores opremsningsliste 
bool Student::isValid() const {
    if ((age > 0)){
        std::cout << "Objektet er for eleven "<< name << " er gyldigt" << std::endl;
        return true;
    }
    else{
        std::cout << "Objektet er for eleven "<< name << " er ugyldigt" << std::endl;
        return false;
    }
}

//Opgave 4 med Karakter
void gennemsnit(std::vector <Karakter> grade, int n){
    int sum = 0;
    std::sort(grade.begin(), grade.end());
    for(int i = n; i < grade.size(); i++){
        //konvertering fra enum til int
        int conv = static_cast<int>(grade[i]);
        sum = sum + conv;
    }
    std::vector <Karakter> non_used;
    for (int i = 0; i < n; i++){
        int conv = static_cast<int>(grade[i]);
        non_used.push_back(grade[i]);
    }

    int total = grade.size();
    std::cout << "Gennemsnit af karakterer uden ";
    for (int i = 0; i < non_used.size(); i++){
        int conv = static_cast<int>(non_used[i]);
        std::cout << conv << " ";
    }
    
    std::cout << ": " << (sum/(total - n)) << std::endl;
}

    