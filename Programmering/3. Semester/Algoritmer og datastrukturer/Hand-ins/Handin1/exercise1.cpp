#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

class Vector{
    private:
        int m;
        int n;
        int c = 0;
        std::vector<int> r;

        std::vector <int> M;
    public:
        Vector();
        void add();
        void count();
        void print();
};


int main (){
    srand(time(0));
    Vector V;
    V.add();
    V.count();
    V.print();
}

//Metoder:

Vector::Vector(){
    m = rand() % 101;   // 1 step
    n = rand() % 101;   // 1 step
}
//Worst case Big-O

void Vector::add(){
    int m1;
    for(int i = 0; i < m; i++){     //Kør m steps 
        m1 = rand() % 101;          //Kør 1 step for hver m 
        M.push_back(m1);            //Kør 1 step for hver m 
    }
}
//Worst case: For hver m køres der 2 skridt, dvs m * 2.
//I Big-O-notation ignoreres konstante faktorer, så worst-case kompleksiteten for add() er O(m).

void Vector::count(){
    for (int i = 0; i < n; i++){                        //Kører n gange
        int h = rand() % 101;                           //Kører 1 gang for hver n
        r.push_back(h);                                 //Kører 1 gang for hver n
        for(auto it = M.begin(); it != M.end(); ++it){  //Kører m gange for hver n
            if (*it == h){                              
                c++;
            }
            else{continue;}                             //Dette if statement kører 1 sammenligning + 1 evt. tildeling for hver m * n
        }
    }
}
//Worst case er så n * (2 + m). 
//Hvis vi omsætter det til 2n + nm, bliver Big-O notationen O(nm)

void Vector::print(){
    std::cout << "M: " << m << std::endl;
    std::cout << "N: " << n << std::endl;
    std::cout << "Vector M: ";                              //1 step
    for (int i = 0; i < M.size(); i++){                     //m steps
        std::cout << M[i] << ", ";                          //1 step pr m
    }
    std::cout << std::endl;                                 //1 step
    std::cout << "Tilfældige tal: ";                        //1 step
    for(int j = 0; j < r.size(); j++){                      //n steps
        std::cout << r[j] << ", ";                          //1 step pr n
    }
    std::cout << std::endl;                                 //1 step
    std::cout << "Antal gange matches " << c << std::endl;  //1 step
}
//Worst case er 1 + (m*1) + 1 + 1 + (n*1) + 1 + 1
//Det bliver 5 + m + n = (O + m + n)