#include <iostream>
#include <chrono>
#include <cmath>
#include <random>

using namespace std;
class movement
{
public:
    template <class T>
    /*struct TypeIsInt
    {
        static const bool value = false;
    };

    template<>
    struct TypeIsInt<int>
    {
        static const bool value = true;
    };

    template <typename T>*/
    double xcord(T theta)
    {
        return cos(theta);
    }

    template <typename T>
    double ycord(T theta)
    {
        return sin(theta);
    }
};

class chaser : public movement
{
public:
    double theta(double chy, double tay, double distance)
    {
        return asin(((tay - chy) / distance));
    }
};

class target : public movement
{
public:
    int theta()
    {
        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<int> distribution(0, 360);
        return distribution(generator);
    }
};

int main()
{
    using std::chrono::high_resolution_clock;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    bool flag = 1;
    chaser* chase = new chaser;
    target* targ = new target;
    double chx, chy, tax, tay, distance, chtheta, disx, disy;
    int tatheta;
    int count;

    while (flag)
    {
        chx = 0, chy = 0, tax = 10, tay = 10, distance = 2, chtheta, disx = 0, disy = 0, tatheta, count = 0;
        distance = sqrt((pow((tax - chx), 2) + pow((tay - chy), 2)));

        while (distance > 1)
        {
            tatheta = targ->theta();
            chtheta = chase->theta(chy, tay, distance);
            chx += chase->xcord(chtheta);
            chy += chase->ycord(chtheta);
            tax += targ->xcord(tatheta);
            tay += targ->ycord(tatheta);
            disx += chase->xcord(chtheta);
            disy += chase->ycord(chtheta);
            ++count;
            distance = sqrt((pow((tax - chx), 2) + pow((tay - chy), 2)));
        }

        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        auto time = chrono::duration_cast<chrono::milliseconds>(t2 - t1) / 100;
        cout << "It took " << count << " moves to catch the target.\nChaser coordinates: (" << chx << ", " << chy << ")\nTarget coordinates: (" << tax << ", " << tay << ")\nDistance: " << distance << "m\nChaser travelled " << disx << "m on the x - axis\nChaser travelled " << disy << "m on the y - axis\nChaser offset is " << (chx - 0) << "m x - axis and " << (chy - 0) << "m y - axis\nTarget offset is " << (tax - 10) << "m x - axis and " << (tay - 10) << "m y - axis\nTime to execute: " << time.count() << "ms\n\nEnter 0 to close or 1 to go again." << endl;
        cin >> flag;
    }

    delete chase;
    delete targ;
}