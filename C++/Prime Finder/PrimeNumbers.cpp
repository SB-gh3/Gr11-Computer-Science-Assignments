﻿#include <iostream>
#include<vector>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <queue>

using namespace std;

static void trialDivision(int num)
{
    using namespace std::chrono;

    vector<int> prime = {2};
    auto startTime = high_resolution_clock::now();

    for (size_t i = 2; i <= num; ++i)
    {
        vector<int>::iterator iter;

        for (iter = prime.begin(); iter < prime.end(); ++iter)
        {
            if (i % *iter == 0)
            {
                break;
            }
            else if (i % *iter != 0 && iter == prime.end() - 1)
            {
                prime.push_back(i);
                break;
            }
        }
    }
    
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime - startTime).count();
    cout << "Time to execute Trial Division: " << duration << "us" << endl;
}

static void sieveOfEratosthenes(int num)
{
    using namespace std::chrono;

    vector<bool> check(num, true);
    vector<int> prime;
    int index = 2;
    auto startTime = high_resolution_clock::now();

    while (index < num)
    {
        if (check[index])
        {
            for (int j = index; j != check.size(); ++j)
            {
                if (j % index == 0)
                {
                    check[j] = false;
                }
            }
            prime.push_back(index);
        }
        ++index;
    }

    /*vector<bool> isPrime(num + 1, true);
    vector<int> primes;
    auto startTime = high_resolution_clock::now();

    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= num; ++i)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= num; j += i)
            {
                isPrime[j] = false;
            }
        }
    }*/

    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime - startTime).count();
    cout << "Time to execute Sieve of Eratosthenes: " << duration << "us" << endl;
}

static void dijkstraMethod(int num)
{
    using namespace std::chrono;

    /*vector<int> initial = {2};
    vector<int> multiple = {4};
    vector<int> prime = {2};
    auto startTime = high_resolution_clock::now();

    for (size_t i = 3; i <= num; ++i)
    {
        int mini = *min_element(multiple.begin(), multiple.end());

        if (i < mini)
        {
            prime.push_back(i);
            initial.push_back(i);
            multiple.push_back(pow(i, 2));
        }
        else if (i == mini)
        {
            vector<int>::iterator iter;
            vector<int>::iterator itero = initial.begin();
            
            for (iter = multiple.begin(); iter < multiple.end(); ++iter)
            {
                if (*iter == mini)
                {
                    *iter += *itero;
                }
                ++itero;
            }
        }
    }*/

    vector<int> primes = {2};
    priority_queue<int, vector<int>, greater<int>> nextMultiple;
    nextMultiple.push(4);
    auto startTime = high_resolution_clock::now();

    for (int i = 3; i <= num; ++i)
    {
        if (i < nextMultiple.top())
        {
            primes.push_back(i);
            nextMultiple.push(i * i);
        }
        else
        {
            nextMultiple.pop();
        }
    }

    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(endTime - startTime).count();
    cout << "Time to execute Dijkstra's Method: " << duration << "us" << endl;
}

static void input()
{
    int num;
    cout << "Enter test length:" << endl;
    cin >> num;
    void (*divi)(int) = &trialDivision;
    void (*sieve)(int) = &sieveOfEratosthenes;
    void (*dijk)(int) = &dijkstraMethod;
    (*divi)(num);
    (*sieve)(num);
    (*dijk)(num);
}

int main()
{
    void (*sele)() = &input;
    while (true)
    {
        (*sele)();
    }
}