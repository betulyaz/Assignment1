
#include <cmath>
#include <cstdlib>
#include <stdint.h>
#include <stdio.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <functional>
#include <fstream>
#include <math.h>
#include <algorithm>

using namespace std;

void getPrimes(int64_t low, int64_t limit, int64_t threads)
{

    int64_t square_root = (int64_t)sqrt(limit);
    int64_t segment_size = max(square_root, limit / threads);

    vector<char> segment(segment_size);
    vector<char> is_prime(square_root + 1, true);


    vector<int64_t> primes;
    vector<int64_t> all_primes;
    vector<int64_t> multiples;

    float sumOfPrimes = 0;
    clock_t startTimer, stopTimer;

    // push 2 on to the stack  then set counter to 3
    all_primes.push_back(2);
    int64_t y = 3;
    int64_t pr = 3;


    //Start the timer
    startTimer = clock();

    for (; low <= limit; low += segment_size)
    {
        std::fill(segment.begin(), segment.end(), true);
        int64_t high = low + segment_size - 1;
        high = std::min(high, limit);

        //generate sieving primes
        for (int64_t i = 3; i * i <= high; i += 2)
        {

            if (is_prime[i])
            {

                for (int64_t j = i * i; j <= square_root; j += i)
                {

                    is_prime[j] = false;
                }
            }
        }
        // get primes for current segment
        for (; y * y <= high; y += 2)
        {
            if (is_prime[y] == true)
            {
                primes.push_back(y);
                multiples.push_back(y * y - low);
            }
        }

        // sieve current segment
        for (std::size_t i = 0; i < primes.size(); i++)
        {
            int64_t j = multiples[i];

            for (int64_t k = primes[i] * 2; j < segment_size; j += k)
            {
                segment[j] = false;
            }
            multiples[i] = j - segment_size;
        }
        // Save the primes to the main primes vector
        // Calculate the sum here.
        for (; pr <= high; pr += 2)
        {
            if (segment[pr - low] == true)
            {
                all_primes.push_back(pr);
                sumOfPrimes += pr;
            }
        }

        //Copy the last 10 elements of the main primes array to the new largest primes array
        vector<int> B(all_primes.begin() + (all_primes.size() - 10), all_primes.end());
        int64_t totalPrimes = all_primes.size();
        stopTimer = clock();

        std::ofstream outputFile("primes.txt");
        outputFile << std::fixed << "Execution Time: " << (stopTimer - startTimer) << " Milliseconds\n";
        outputFile << "Total Primes: " << totalPrimes << "\n";
        outputFile << "Sum of Primes: " << sumOfPrimes << "\n";
        outputFile << "Top Ten Maximum Primes: ";

        // Iterate over the Priority que to get the max prime list
        for (int64_t x = 0; x < B.size(); x++)
        {
            outputFile << B[x] << ", ";
        }

        outputFile << "\n";
        outputFile.close();
    }

    std::cout << all_primes.size() << " primes found." << std::endl;
    cout << "The time it took to complete is: " << (double)(stopTimer - startTimer) / CLOCKS_PER_SEC << endl;
}

int main()
{

    const int numThreads = 8;
    const int rangeStart = 1;
    const int rangeEnd = 100000000; // 10^8

    getPrimes(rangeStart, rangeEnd, numThreads);

    // You can delete this part of the code
    string myText;
    ifstream MyReadFile("primes.txt");
    while (getline(MyReadFile, myText))
    {
        cout << myText;
    }
    MyReadFile.close();
    // =========================================

    return 0;
}
