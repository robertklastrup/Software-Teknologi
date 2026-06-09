#include "opg4.h"


void gennemsnit(std::vector <int> grade, int n){
    int sum = 0;
    std::sort(grade.begin(), grade.end());

    for(int i = n; i < grade.size(); i++){
        sum = sum + grade[i];
    }
    std::vector <int> non_used;
    for (int i = 0; i < n; i++){
        non_used.push_back(grade[i]);
    }

    int total = grade.size();
    std::cout << "Gennemsnit af karakterer uden ";
    for (int i = 0; i < non_used.size(); i++){
        std::cout << non_used[i] << " ";
    }
    
    std::cout << ": " << (sum/(total - n)) << std::endl;
}