#include <iostream>
#include <vector>

int main()
{
    srand(time(0));

    std::vector<int> numbersM;
    for (int i = 0; i < 11; i++){
        int m = rand() % 51;
        numbersM.push_back(m);
        std::cout << "M: " << numbersM[i] << " ";
    }
    
    std::cout << "\n";

    std::vector<int> numbersN;
    for (int i = 0; i < 11; i++){
        int n = rand() % 51;
        numbersN.push_back(n);
        std::cout << "N: " << numbersN[i] << " ";
    }

    std::cout << "\n";
    std::vector<int>::iterator it;
    int duplicateCount = 0;
    
    for (int i = 0; i < 10; i++){
        bool match = false;
            for (it = numbersM.begin(); it != numbersM.end(); ++it) {
                if (numbersN[i] == *it) {
                    match = true;
                    duplicateCount++;
                }
            }
        if (match){
            std::cout << "Match på: " << numbersN[i] << " ";    
    
        }
    
    }
        std::cout << "\nCount af duplicates: " << duplicateCount << std::endl;
    
        return 0;
}
