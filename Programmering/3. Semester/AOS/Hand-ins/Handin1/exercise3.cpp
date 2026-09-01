#include <iostream>
#include <chrono>

//a) Give an analysis of the running time in Big-Oh notation:

//(1)
int frag1(int n){
    int sum = 0;                    //1
    for (int i = 0; i < n; i++){    
        sum++;                      //n
    }
    return sum;
}
//Worst case: O(n)

//(2)
int frag2(int n){
    int sum = 0;                        //1
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sum++;                   //n*n
        }
    }
    return sum;
}
//Worst case: O(n^2)



//(3)
int frag3(int n){
    int sum = 0;                            //1
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n * n; j++){
            sum++;                      //n*n*n
        }
    }
    return sum;
}
//Worst case: O(n^3)


//(4)
int frag4(int n){
    int sum = 0;                        //1
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            sum++;                      //n*n-1
        }
    }
    return sum;
}
//Worst case: O(n*(n-1))=n^2-n -> since n^2 is dominating, the final notation will be O(n^2)

