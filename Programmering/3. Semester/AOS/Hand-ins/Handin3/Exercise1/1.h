#include <iostream>
#include <vector>
#include <algorithm>



template <typename Object>
bool search (Object x, std::vector <Object> A){
    int n = A.size();
    if(n == 0){
        return false;
    }
    else if(x == A[n - 1]){
        return true;
    }
    else{
        std::vector<Object> downsize(A.begin(), A.end() - 1);
        return search(x, downsize);
    }   
}

