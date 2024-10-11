#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string one(double cash)
{
    vector<double> vec = {20, 10, 5, 2, 1, 0.25, 0.1, 0.05};
    vector<int> count(8);
    vector<double>::iterator iter;
    vector<int>::iterator itero = count.begin();
    string output = "";

    for (iter = vec.begin(); iter != vec.end(); ++iter)
    {
        while (cash - *iter >= 0)
        {
            cash -= *iter;
            ++*itero;
            cash = ceil(cash * 100.0) / 100.0;
        }

        //output += *itero + " x $" + *iter + "\n";
        output.append(to_string(*itero));
        output += " x $";
        output.append(to_string(*iter));
        output += "\n";
        ++itero;
    }

    return output;
}

string two(vector<int> vec)
{
    vector<int> output;

    for (size_t i = 0; i != vec.size() - 1; ++i)
    {
        if ((i + 1) % 2 != 0)
        {
            output.push_back(vec[i] + vec[i + 1]);
        }
        else if (i == vec.size() - 2)
        {
            output.push_back(vec[i + 1]);
        }
    }

    stringstream ss;
    for (auto it = output.begin(); it != output.end(); it++)
    {
        if (it != output.begin())
        {
            ss << " ";
        }

        ss << *it;
    }

    return ss.str();
}

void three(string str, char chara)
{
    vector<string> brokenString;
    str += chara;
    bool flag = true;

    while (flag)
    {
        int split = str.find(chara);

        if (split >= 1)
        {
            brokenString.push_back(str.substr(0, split));
            str.erase(0, split + 1);
        }
        else
        {
            flag = false;
        }
    }

    for (string i : brokenString)
    {
        cout << i << ", ";
    }

    cout << endl;
}

vector<int> four(vector<int> vec)
{
    vector<int> zeroed;
    vector<int>::iterator iter;
    int count = 0;

    for (iter = vec.begin(); iter < vec.end(); ++iter)
    {
        if (*iter == 0)
        {
            ++count;
        }
        else
        {
            zeroed.push_back(*iter);
        }
    }

    fill_n(back_inserter(zeroed), count, 0);
    return zeroed;
}

string five(int n)
{
    srand(time(nullptr));
    string output = "Die Number\tFrequency\tHistogram\n==========\t=========\t=========";
    vector<int> nums(6);
    vector<string> stars(6);
    int roll = 0;

    while (n >= 0)
    {
        roll = rand() % 6 + 1;
        ++nums[roll - 1];
        stars[roll - 1] += "*";
        --n;
    }

    for (size_t i = 0; i < 6; ++i)
    {
        output += "\n  " + to_string(i + 1) + "\t\t" + to_string(nums[i]) + "\t\t" + stars[i];
    }

    return output;
}

void six()
{
    char blar = ' ';
    char flar;
    double count = 0, score = 0;

    while (blar != 'N' && blar != 'n')
    {
         cout << "What is your answer (as a letter)?" << endl;
         flar = getchar();
         cin.ignore();

         if (flar == 'A' || flar == 'a')
         {
             ++count;
             ++score;
         }
         else
         {
             ++count;
             score -= 0.2;
         }

        cout << "Do you want to continue? (Y/N)" << endl;
        blar = getchar();
        cin.ignore();
    }

    cout << "Score: " << (score / count) * 100.0 << "%" << endl;
}

void seven(double nume, double deno)
{
    int divisor = min(nume, deno);
    int numnum = INT_MAX;
    int denden = INT_MAX;
    string frac = "";

    for (size_t i = 1; i <= divisor; ++i)
    {
        if (nume / i == (int)(nume / i) && deno / i == (int)(deno / i))
        {
            numnum = nume / i;
            denden = deno / i;
            frac = to_string(numnum) + "/" + to_string(denden);
        }
    }

    cout << "Lowest Fraction: " << frac << endl;
}

int getint()
{
    int num;
    cin >> num;
    return num;
}

void select()
{
    int choice;
    cout << "1. Coins\n2. Vector Add\n3. Split that String\n4. Zeroed out\n5. Die\n6. Test\n7. Fractions" << endl;
    cin >> choice;
    cin.ignore();
    int (*getInt)() = &getint;
    string (*ones)(double) = &one;
    string (*twos)(vector<int>) = &two;
    void (*threes)(string, char) = &three;
    vector<int> (*fours)(vector<int>) = &four;
    string (*fives)(int) = &five;
    void (*sixes)() = &six;
    void (*sevens)(double, double) = &seven;
    vector<int> vec;
    string str;

    switch (choice)
    {
        case 1:
            double num;
            cout << "Enter monetary value: ";
            cin >> num;
            cout << (*ones)(num);
            return;

        case 2:
            int len;
            cout << "Enter vector length: ";
            cin >> len;
            vec.resize(len);

            for (size_t i = 0; i != vec.size(); ++i)
            {
                cout << "Enter element " << i + 1 << ": ";
                cin >> vec[i];
            }

            cout << (*twos)(vec) << endl;
            return;

        case 3:
            char chara;
            cout << "Enter string: ";
            getline(cin, str);
            cout << "Enter splitter attribute: ";
            chara = getchar();
            (*threes)(str, chara);
            return;

        case 4:
            int ben;
            cout << "Enter vector length: ";
            cin >> ben;

            for (size_t i = 0; i < ben; i++)
            {
                cout << "Enter element " << (i + 1) << ": ";
                vec.push_back((*getInt)());
            }

            for (int i : (*fours)(vec))
            {
                cout << i << " ";
            }
            return;

        case 5:
            int n;
            cout << "Enter number of rolls: ";
            cin >> n;
            cout << (*fives)(n) << endl;
            return;

        case 6:
            (*sixes)();
            return;

        case 7:
            double nume, deno;
            cout << "Enter numerator: ";
            cin >> nume;
            cout << "Enter denomonator: ";
            cin >> deno;
            (*sevens)(nume, deno);
            return;

        default:
            MessageBox(nullptr, L"ERROR", L"ERROR", MB_OK);
            return;
    }
}

int main()
{
    void (*sele)() = &select;
    
    while (true)
    {
        (*sele)();
    }
}