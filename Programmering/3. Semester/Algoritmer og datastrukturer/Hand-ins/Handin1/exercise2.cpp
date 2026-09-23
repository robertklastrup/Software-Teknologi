#include <iostream>
#include <cmath>


int myMethod(int N)
    {
        int x = 0;                                      //1 step
        int y = 0;                                      //1 step
        for (int i = 0; i < N; i++)                     
        {
            for (int j = 0; j < N; j++)                 
            {
                for (int k = 0; k < N * sqrt(N); k++)   
                {
                    x++;                                //1 step
                }                                       //(N*N*(N * sqrt(N))) = N^3.5
            }
        }
        for (int i = 0; i < N * N; i++)
        {
            y++;                                        //N * N
        }
        return x + y;                                   //1
    }
//Worst case: O(N^3.5+N^2) -> since N^3.5 is the dominating N, the final big-O will be O(N^3.5)