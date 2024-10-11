#include <iostream>
#include <windows.h>
#include <vector>
#include <math.h>
#include <stdio.h>

using namespace std;

static void one()
{
    vector<vector<int>> arr;

    for (size_t i = 0; i != 3; ++i)
    {
        vector<int> row;

        for (size_t j = 0; j != 3; ++j)
        {
            int temp;
            cout << "Enter element " << j + 1 << " for line " << i + 1 << endl;
            cin >> temp;
            row.push_back(temp);
        }
        arr.push_back(row);
    }

    for (size_t i = 0; i != 3; ++i)
    {
        for (size_t j = 0; j != 3; ++j)
        {
            (arr[i][j] % 2 == 0) ? arr[i][j] = pow(arr[i][j], 2) : arr[i][j] = pow(arr[i][j], 3);
        }
    }

    for (size_t i = 0; i != 3; ++i)
    {
        for (size_t j = 0; j != 3; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

static void two()
{
    vector<int> vec = {2, 5, 7, 9, 13, 15, 16, 18, 23, 24};
    vector<int> vecList;
    vector<int>::iterator iter;
    vecList.push_back(14);
    vecList.push_back(23);
    vecList.push_back(27);
    vecList.push_back(31);
    vecList.push_back(34);
    vecList.push_back(39);
    vecList.push_back(40);
    vector<int> vecL;

    for (iter = vec.begin(); iter != vec.end(); ++iter)
    {
        if (*iter % 3 == 0)
        {
            vecL.push_back(*iter);
        }
    }

    for (iter = vecList.begin(); iter != vecList.end(); ++iter)
    {
        if (*iter % 3 == 0)
        {
            vecL.push_back(*iter);
        }
    }

    copy(vecL.begin(), vecL.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

static void input()
{
    int choice;
    cout << "1. Squared and Cubed\n2. Aray Senanigans" << endl;
    cin >> choice;
    void (*ones)() = &one;
    void (*twos)() = &two;

    switch (choice)
    {
        case 1:
            (*ones)();
            return;

        case 2:
            (*twos)();
            return;

        default: 
            MessageBox(nullptr, L"ERROR", L"ERROR", MB_OK);
    }
}

int main()
{
    while (true)
    {
        input();
    }
}