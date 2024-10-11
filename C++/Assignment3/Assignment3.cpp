#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <algorithm>

using namespace std;

bool checkbool(vector<bool> boo, bool parameter)
{
    for (auto iter = boo.begin(); iter < boo.end(); ++iter)
    {
        if (*iter == parameter)
        {
            return true;
        }
    }

    return false;
}

int getInt()
{
    int temp;
    cin >> temp;
    cin.ignore();
    return temp;
}

bool checkint(vector<int> name, int num, int top)
{
    for (auto iter = name.end() - top; iter < name.end(); ++iter)
    {
        if (*iter == num)
        {
            return true;
        }
    }

    return false;
}

int one(vector<vector<int>> vec, string choose, int num, int size)
{
    int sum = 0;

    if (num > size)
    {
        MessageBox(nullptr, L"ERROR", L"ERROR", MB_OK);
        return -1;
    }

    if (choose == "r" || choose == "R")
    {
        for (size_t i = 0; i < size; i++)
        {
            sum += vec[num][i];
        }
    }
    else if (choose == "c" || choose == "C")
    {
        for (size_t i = 0; i < size; i++)
        {
            sum += vec[i][num];
        }
    }
    else if (choose == "fd" || choose == "FD")
    {
        for (size_t i = 0; i < size; i++)
        {
            sum += vec[num - i][i];
        }
    }
    else if (choose == "rd" || choose == "RD")
    {
        for (size_t i = 0; i < size; i++)
        {
            sum += vec[i][i];
        }
    }

    return sum;
}

string two(int n)
{
    int dire = 1;
    int direr = 1;
    int count = 1;
    int countr = 1;
    string diamond = "";

    if (n % 2 == 0)
    {
        MessageBox(nullptr, L"ERROR", L"ERROR", MB_OK);
        return "ERROR";
    }
    else
    {
        int counto = n * 2;

        while (dire > 0)
        {
            if (dire % 2 != 0)
            {
                if (dire <= n)
                {
                    diamond.insert(diamond.end(), counto, ' ');
                    diamond.insert(diamond.end(), dire, '*');
                    diamond += "\n";
                    --counto;

                    if (dire == n)
                    {
                        counto += 2;
                    }

                    ++dire;
                }
                else if (dire > n)
                {
                    diamond.insert(diamond.end(), counto, ' ');
                    diamond.insert(diamond.end(), dire - 2 * (count + 1), '*');
                    ++dire;

                    if (dire == 2 * n)
                    {
                        break;
                    }

                    diamond += "\n";
                    count += 2;
                    ++counto;
                }
            }

            ++dire;
        }

        diamond += "\n\n";

        int countor = n * 2;

        while (direr > 0)
        {
            if (direr % 2 != 0)
            {
                if (direr <= n)
                {
                    diamond.insert(diamond.end(), countor, ' ');
                    diamond += "*";

                    if (direr != 1)
                    {
                        diamond.insert(diamond.end(), direr - 2, ' ');
                        diamond += "*";
                    }

                    diamond += "\n";
                    --countor;

                    if (direr == n)
                    {
                        countor += 2;
                    }

                    ++direr;
                }
                else if (direr > n)
                {
                    diamond.insert(diamond.end(), countor, ' ');
                    diamond += "*";

                    if (direr != 2 * n - 1)
                    {
                        diamond.insert(diamond.end(), (direr - 2 * (countr + 1)) - 2, ' ');
                        diamond += "*";
                    }

                    ++direr;

                    if (direr == 2 * n)
                    {
                        break;
                    }

                    diamond += "\n";
                    countr += 2;
                    ++countor;
                }
            }

            ++direr;
        }
    }

    return diamond;
}

bool three(string num)
{
    string copy = num;
    reverse(num.begin(), num.end());

    if (copy == num)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void four(int lim)
{
    for (unsigned int i = 2; i <= lim; ++i)
    {
        int adf = 0;

        for (unsigned int j = 1; j <= i; ++j)
        {
            if (i % j == 0 && j != i)
            {
                adf += j;
            }
        }

        if (adf == i)
        {
            cout << i << " is a perfect number!" << endl;
        }
    }
}

void five(int min, int max)
{
    vector<bool> check(max, true);

    while (min < max)
    {
        if (check[min])
        {
            for (int j = min; j != check.size(); ++j)
            {
                if (j % min == 0)
                {
                    check[j] = false;
                }
            }
            cout << min << ", ";
        }
        ++min;
    }

    cout << endl;
}

void six()
{
    bool (*checkBool)(vector<bool>, bool) = &checkbool;
    string password, output;
    bool repeat = true;
    vector<bool> rules(4, true);
    string::iterator iter;
    vector<string> build{"password must be longer than equal to six charachters, ", "passowrd must begin with a capital, ", "password must contain two digits, ", "password must contain one and only one special charachter (!,@,#,$,%,^,&,*)"};
    
    while (repeat)
    {
        cout << "Enter a password: ";
        cin >> password;
        cin.ignore();
        output.clear();

        if (password.size() < 6)
        {
            rules[0] = false;
            output += build[0];
        }

        if (password.front() != toupper(password.front()) || isdigit(password.front()))
        {
            rules[1] = false;
            output += build[1];
        }

        int count = 0;

        for (iter = password.begin(); iter < password.end(); ++iter)
        {
            if (isdigit(*iter))
            {
                ++count;
            }
        }

        if (count < 2)
        {
            rules[2] = false;
            output += build[2];
        }

        int counto = 0;

        for (auto i = password.begin(); i < password.end(); ++i)
        {
            if (*i == '!' || *i == '@' || *i == '#' || *i == '$' || *i == '%' || *i == '^' || *i == '&' || *i == '*')
            {
                ++counto;
            }
        }

        if (counto != 1)
        {
            rules[3] = false;
            output += build[3];
        }

        if ((*checkBool)(rules, false))
        {
            cout << output << endl;
        }
        else
        {
            cout << "Accepted" << endl;
            repeat = false;
        }
    }
}

string seven(vector<int> rain, vector<string> month)
{
    bool (*checkInt)(vector<int>, int, int) = &checkint;
    string output = "Month\tRainfall Amount\n=====\t===============\n";
    vector<int> raino = rain;
    nth_element(rain.begin(), rain.begin() + 2, rain.end());

    for (size_t i = 0; i < month.size(); ++i)
    {
        output += month[i] + "\t\t";
        output += to_string(raino[i]);

        if ((*checkInt)(rain, raino[i], 3))
        {
            output += "\tBring an umbrella";
        }

        output += "\n";
    }

    return output;
}

void select()
{
    int (*getint)() = &getInt;
    int (*ones)(vector<vector<int>>, string, int, int) = &one;
    string (*twos)(int) = &two;
    bool (*threes)(string) = &three;
    void (*fours)(int) = &four;
    void (*fives)(int, int) = &five;
    void (*sixes)() = &six;
    string (*sevens)(vector<int>, vector<string>) = &seven;
    vector<vector<int>> vec;
    vector<int> rain;
    vector<string> month{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int choice;
    string choose;
    string numo;
    cout << "1. 2D addition\n2. Diamond\n3. Palindrome\n4. Perfect Numbers\n5. Prime Numbers(Sieve of Eratosthenes)\n6. Password\n7. Rain" << endl;
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
        case 1:
            unsigned int size, num;
            cout << "Enter vector size: ";
            cin >> size;
            cin.ignore();
            vec.resize(size, vector<int>(size));

            for (size_t i = 0; i < size; ++i)
            {
                for (size_t j = 0; j < size; ++j)
                {
                    cout << "Enter element " << (j + 1) << " in row " << (i + 1) << ": ";
                    cin >> vec[i][j];
                    cin.ignore();
                }
            }

            cout << "Which section do you want to add? (r, c, fd, rd)" << endl;
            cin >> choose;
            cin.ignore();
            cout << "Which index do you want to check (0 for fd, rd)" << endl;
            cin >> num;
            cin.ignore();
            cout << "Return value: " << to_string((*ones)(vec, choose, num, size)) << endl;
            return;

        case 2: 
            unsigned int n;
            cout << "Enter size: ";
            cin >> n;
            cin.ignore();
            cout << (*twos)(n) << endl;
            return;

        case 3:
            cout << "Enter number: ";
            cin >> numo;
            cin.ignore();
            cout << boolalpha << (*threes)(numo) << endl;
            return;

        case 4:
            int lim;
            cout << "Enter limit: ";
            cin >> lim;
            cin.ignore();
            (*fours)(lim);
            return;

        case 5:
            int min, max;
            cout << "Enter minimum: ";
            cin >> min;
            cin.ignore();
            cout << "Enter maximum: ";
            cin >> max;
            cin.ignore();
            (*fives)(min, max);
            return;

        case 6:
            (*sixes)();
            return;

        case 7:

            for (size_t i = 0; i < month.size(); ++i)
            {
                cout << "Enter rainfall amount for " << month[i] << ": ";
                rain.push_back((*getint)());
            }

            cout << (*sevens)(rain, month) << endl;
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