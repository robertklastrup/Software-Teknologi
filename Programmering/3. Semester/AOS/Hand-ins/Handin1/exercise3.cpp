#include <iostream>
#include <chrono>

//a) Give an analysis of the running time in Big-Oh notation:

//(1)
long long frag1(int n){
    long long sum = 0;                  //1
    for (int i = 0; i < n; i++){    
        sum++;                          //n
    }
    return sum;
}
//Worst case: O(n)

//(2)
long long frag2(int n){
    long long sum = 0;                      //1
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sum++;                          //n*n
        }
    }
    return sum;
}
//Worst case: O(n^2)



//(3)
long long frag3(int n){
    long long sum = 0;                  //1
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n * n; j++){
            sum++;                      //n*n*n
        }
    }
    return sum;
}
//Worst case: O(n^3)


//(4)
long long frag4(int n){
    long long sum = 0;                      //1
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            sum++;                          //n*n-1
        }
    }
    return sum;
}
//Worst case: O(n*(n-1))=n^2-n -> since n^2 is dominating, the final notation will be O(n^2)

int main (){
    auto start1 = std::chrono::high_resolution_clock::now();
    long long result1 = frag1(1000);
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);
    std::cout << "Time for (1): " << duration1.count() << " µs" << std::endl;
    std::cout << "Result 1: " << result1 << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    long long result2 = frag2(1000);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);
    std::cout << "Time for (2): " << duration2.count() << " ms" << std::endl;
    std::cout << "Result 2: " << result2 << std::endl;

    auto start3 = std::chrono::high_resolution_clock::now();
    long long result3 = frag3(1000);
    auto end3 = std::chrono::high_resolution_clock::now();
    auto duration3 = std::chrono::duration_cast<std::chrono::milliseconds>(end3 - start3);
    std::cout << "Time for (3): " << duration3.count() << " ms" << std::endl;
    std::cout << "Result 3: " << result3 << std::endl;

    auto start4 = std::chrono::high_resolution_clock::now();
    long long result4 = frag4(2000);
    auto end4 = std::chrono::high_resolution_clock::now();
    auto duration4 = std::chrono::duration_cast<std::chrono::milliseconds>(end4 - start4);
    std::cout << "Time for (4): " << duration4.count() << " ms" << std::endl;
    std::cout << "Result 4: " << result4 << std::endl;

}

//b)
//n = 100:
//1) 0 ms
//2) 0 ms
//3) 2 ms
//4) 0 ms

//n = 500:
//1) 0 ms
//2) 0 ms
//3) 210 ms
//4) 0 ms

//n = 1000:
//1) 0 ms
//2) 1 ms
//3) 1659 ms 
//4) 0 ms

//n = 2000:
//1) 0 ms
//2) 5 ms
//3) 13109 ms (2000^3)
//4) 3 ms


//c)
//Obviously we can see that (3) is taking a much longer time, since there are many more steps in the loop.
//If we double n, the time should for:
//O(n) x2 - well since all my test results got 0 ms, there's not much to show, though if i do it with microseconds i get:
//n = 1500 -> 2 µs
//n = 3000 -> 4 µs
//So thats right on.
//O(n^2) x4 - From n = 1000 to n = 2000, went from 1 ms to 5 ms, so that sounds about right
//O(n^3) x8 - From n = 1000 to n = 2000, went from 1659 ms to 13109 ms, right on would be 13272, but it is very close to my analysis


//d) Well, with -O0 i got:
//n = 1000:
//1) 1 µs
//2) 1 ms
//3) 1703 ms 
//4) 1 ms

//n = 2000:
//1) 3 µs
//2) 6 ms
//3) 13001 ms 
//4) 2 ms

//So that's basicly the same, with -O1, i had to print the results, so it didn't skip:
//n = 1000:
//1) 0 µs - 1000 steps
//2) 0 ms - 1000000 steps
//3) 721 ms - 1000000000 steps
//4) 0 ms - 499500 steps

//n = 2000:
//1) 1 µs - 2000 steps
//2) 2 ms - 4000000 steps
//3) 4979 ms - 8000000000 steps
//4) 1 ms - 1999000 steps

//Similar results, since the algorithms structure is the same