#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int kvadrer (int x){
    x = x * x;
    return x;
}


int main (){
    std::vector<int> vec = {5, 3, 8, 1, 9, 2};

    //print
    auto it = vec.begin();
    while( it!=vec.end()){
        std::cout << *it << std::endl; 
        ++it;
    }
    
    //sort
    std::sort(vec.begin(), vec.end());
    it = vec.begin();
    while( it!=vec.end()){
        std::cout << *it << std::endl; 
        ++it;
    }

    //find and erase
    it = std::find(vec.begin(), vec.end(), 8);
    if (it != vec.end()){
        std::cout << "Fundet!" << std::endl;
        vec.erase(it);
    }

    it = vec.begin();
    while( it!=vec.end()){
        std::cout << *it << std::endl; 
        ++it;
    }

    //accumulate
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << sum << std::endl;


    //transform
    std::vector <int> vect{1,2,3,4,5};
    std::vector <int> result(5);
    
    std::transform(vect.begin(), vect.end(), result.begin(), kvadrer);
    
    it = result.begin();
    while (it != result.end()){
        std::cout << *it << ", ";
        ++it;
    }
}

