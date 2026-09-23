#include <iostream>
#include <chrono>

// 1
int addUpN(int N)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        ++sum;
    }
    return sum;
}

// 2
int addUpNSquared(int N)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ++sum;
        }
    }

    return sum;
}

// 3
int addUpNCubed(int N)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N * N; j++)
        {
            ++sum;
        }
    }

    return sum;
}

// 4
int addUpNSquared2(int N)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            ++sum;
        }
    }

    return sum;
}

int main()
{
    // 1
    std::cout << "Algorithm 1: " << std::endl;

    auto start_1_1 = std::chrono::high_resolution_clock::now();
    int result_1_1 = addUpN(1000000); // Save as variable and print -> does not get deleted as dead code when running optimisation flag
    auto stop_1_1 = std::chrono::high_resolution_clock::now();
    auto duration_1_1 = std::chrono::duration_cast<std::chrono::microseconds>(stop_1_1 - start_1_1);
    std::cout << "Time taken (sum = " << result_1_1 << "): " << duration_1_1.count() << " microseconds" << std::endl
              << std::endl;

    auto start_2_1 = std::chrono::high_resolution_clock::now();
    int result_2_1 = addUpN(10000000);
    auto stop_2_1 = std::chrono::high_resolution_clock::now();
    auto duration_2_1 = std::chrono::duration_cast<std::chrono::microseconds>(stop_2_1 - start_2_1);
    std::cout << "Time taken (sum = " << result_2_1 << "): " << duration_2_1.count() << " microseconds" << std::endl
              << std::endl;

    auto start_3_1 = std::chrono::high_resolution_clock::now();
    int result_3_1 = addUpN(100000000);
    auto stop_3_1 = std::chrono::high_resolution_clock::now();
    auto duration_3_1 = std::chrono::duration_cast<std::chrono::microseconds>(stop_3_1 - start_3_1);
    std::cout << "Time taken (sum = " << result_3_1 << "): " << duration_3_1.count() << " microseconds" << std::endl
              << std::endl;

    // 2
    std::cout << "Algorithm 2: " << std::endl;

    auto start_1_2 = std::chrono::high_resolution_clock::now();
    int result_1_2 = addUpNSquared(100); // Save as variable and print -> does not get deleted as dead code when running optimisation flag
    auto stop_1_2 = std::chrono::high_resolution_clock::now();
    auto duration_1_2 = std::chrono::duration_cast<std::chrono::microseconds>(stop_1_2 - start_1_2);
    std::cout << "Time taken (sum = " << result_1_2 << "): " << duration_1_2.count() << " microseconds" << std::endl
              << std::endl;

    auto start_2_2 = std::chrono::high_resolution_clock::now();
    int result_2_2 = addUpNSquared(1000);
    auto stop_2_2 = std::chrono::high_resolution_clock::now();
    auto duration_2_2 = std::chrono::duration_cast<std::chrono::microseconds>(stop_2_2 - start_2_2);
    std::cout << "Time taken (sum = " << result_2_2 << "): " << duration_2_2.count() << " microseconds" << std::endl
              << std::endl;

    auto start_3_2 = std::chrono::high_resolution_clock::now();
    int result_3_2 = addUpNSquared(10000);
    auto stop_3_2 = std::chrono::high_resolution_clock::now();
    auto duration_3_2 = std::chrono::duration_cast<std::chrono::microseconds>(stop_3_2 - start_3_2);
    std::cout << "Time taken (sum = " << result_3_2 << "): " << duration_3_2.count() << " microseconds" << std::endl
              << std::endl;

    // 3
    std::cout << "Algorithm 3: " << std::endl;

    auto start_1_3 = std::chrono::high_resolution_clock::now();
    int result_1_3 = addUpNCubed(10); // Save as variable and print -> does not get deleted as dead code when running optimisation flag
    auto stop_1_3 = std::chrono::high_resolution_clock::now();
    auto duration_1_3 = std::chrono::duration_cast<std::chrono::microseconds>(stop_1_3 - start_1_3);
    std::cout << "Time taken (sum = " << result_1_3 << "): " << duration_1_3.count() << " microseconds" << std::endl
              << std::endl;

    auto start_2_3 = std::chrono::high_resolution_clock::now();
    int result_2_3 = addUpNCubed(100);
    auto stop_2_3 = std::chrono::high_resolution_clock::now();
    auto duration_2_3 = std::chrono::duration_cast<std::chrono::microseconds>(stop_2_3 - start_2_3);
    std::cout << "Time taken (sum = " << result_2_3 << "): " << duration_2_3.count() << " microseconds" << std::endl
              << std::endl;

    auto start_3_3 = std::chrono::high_resolution_clock::now();
    int result_3_3 = addUpNCubed(1000);
    auto stop_3_3 = std::chrono::high_resolution_clock::now();
    auto duration_3_3 = std::chrono::duration_cast<std::chrono::microseconds>(stop_3_3 - start_3_3);
    std::cout << "Time taken (sum = " << result_3_3 << "): " << duration_3_3.count() << " microseconds" << std::endl
              << std::endl;

    // 4
    std::cout << "Algorithm 4: " << std::endl;

    auto start_1_4 = std::chrono::high_resolution_clock::now();
    int result_1_4 = addUpNSquared2(100); // Save as variable and print -> does not get deleted as dead code when running optimisation flag
    auto stop_1_4 = std::chrono::high_resolution_clock::now();
    auto duration_1_4 = std::chrono::duration_cast<std::chrono::microseconds>(stop_1_4 - start_1_4);
    std::cout << "Time taken (sum = " << result_1_4 << "): " << duration_1_4.count() << " microseconds" << std::endl
              << std::endl;

    auto start_2_4 = std::chrono::high_resolution_clock::now();
    int result_2_4 = addUpNSquared2(1000);
    auto stop_2_4 = std::chrono::high_resolution_clock::now();
    auto duration_2_4 = std::chrono::duration_cast<std::chrono::microseconds>(stop_2_4 - start_2_4);
    std::cout << "Time taken (sum = " << result_2_4 << "): " << duration_2_4.count() << " microseconds" << std::endl
              << std::endl;

    auto start_3_4 = std::chrono::high_resolution_clock::now();
    int result_3_4 = addUpNSquared2(10000);
    auto stop_3_4 = std::chrono::high_resolution_clock::now();
    auto duration_3_4 = std::chrono::duration_cast<std::chrono::microseconds>(stop_3_4 - start_3_4);
    std::cout << "Time taken (sum = " << result_3_4 << "): " << duration_3_4.count() << " microseconds" << std::endl
              << std::endl;

    return 0;
}