#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

static void one()
{
	int len;
	cout << "Enter array length: " << endl;
	cin >> len;
	vector<int> arr(len);
	vector<int> even;
	vector<int> odd;

	for (int i = 0; i < arr.size(); i++)  
	{
		cout << "Enter variable " << (i + 1) << ": " << endl;
		cin >> arr[i];
	}

	for (int i = 0; i < arr.size(); i++)
	{
		(arr[i] % 2) ? even.push_back(arr[i]) : odd.push_back(arr[i]);
	}

	for (int i : even)
	{
		cout << i << ' ';
	}

	cout << endl;

	for (int i : odd)
	{
		cout << i << ' ';
	}

	cout << endl;
}

static void two()
{
	int len;
	cout << "Enter array length: " << endl;
	cin >> len;
	vector<int> arr(len);
	int count = 0;
	vector<int> check;

	for (size_t i = 0; i < arr.size(); i++)
	{
		cout << "Enter variable " << (i + 1) << ": " << endl;
		cin >> arr[i];
	}

	for (size_t i = 0; i < (arr.size() - 1); i++)
	{
		if (arr[i] > arr[i + 1])
		{
			check.push_back(1);
		}
		else if (arr[i] < arr[i + 1])
		{
			check.push_back(0);
		}
	}

	for (size_t i = 0; i < (check.size() - 1); i++)
	{
		if (check[i] != check[i + 1])
		{
			count++;
		}
	}

	cout << "There are " << count << " directional changes." << endl;
}

static void three()
{
	int len;
	cout << "Enter array length: " << endl;
	cin >> len;
	vector<int> vec(len);
	int sma = INT_MAX;
	int lar = INT_MIN;

	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << "Enter variable " << (i + 1) << endl;
		cin >> vec[i];
	}

	for (int i : vec)
	{
		for (int j = i + 1; j < vec.size(); j++)
		{
			if (vec[i] > vec[j])
			{
				int temp = vec[i];
				vec[i] = vec[j];
				vec[j] = temp;
			}
		}
	}

	for (int k = 0; k < vec.size() - 1; k++)
	{
		if (vec[k + 1] - vec[k] < sma)
		{
			sma = vec[k + 1] - vec[k];
		}
		else if (vec[k + 1] - vec[k] > lar)
		{
			lar = vec[k + 1] - vec[k];
		}
	}

	cout << "The smallest difference is " << sma << "\nThe largest difference is " << lar << endl;
}

static bool checkVec1(vector<int> vec1, vector<int> vec2)
{
	return includes(vec1.begin(), vec1.end(), vec2.begin(), vec2.end());
}

static bool checkVec2(vector<int> vec1, vector<int> vec2)
{
	return includes(vec2.begin(), vec2.end(), vec1.begin(), vec1.end());
}

static void four()
{
	cout << "Enter first vector length: " << endl;
	int len = 0;
	cin >> len;
	vector<int> vec1(len);
	cout << "Enter second vector length: " << endl;
	cin >> len;
	vector<int> vec2(len);

	for (int i = 0; i < vec1.size(); i++)
	{
		cout << "Enter element " << (i + 1) << " for first vector: " << endl;
		cin >> vec1[i];
	}

	for (int i = 0; i < vec2.size(); i++)
	{
		cout << "Enter element " << (i + 1) << " for second vector: " << endl;
		cin >> vec2[i];
	}

	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());

	if (checkVec1(vec1, vec2))
	{
		cout << "Vector 1 contains vector 2" << endl;
	}
	else if (checkVec2(vec1, vec2))
	{
		cout << "Vector 2 contains vector 1" << endl;
	}
	else
	{
		cout << "One or more elements are not present" << endl;
	}
}

static void five()
{
	vector<vector<int>> vec(3, vector<int>(3, 0));
	int row1 = 0;
	int row2 = 0;
	int row3 = 0;
	int col1 = 0;
	int col2 = 0;
	int col3 = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "Enter element " << (j + 1) << " for row " << (i + 1) << endl;
			cin >> vec[i][j]; //Crash
		}
	}

	for (int i = 0; i < 3; i++)
	{
		row1 += vec[0][i];
		row2 += vec[1][i];
		row3 += vec[2][i];
		col1 += vec[i][0];
		col2 += vec[i][1];
		col3 += vec[i][2];
	}

	if (row1 == col1 || row1 == col2 || row1 == col3 || row2 == col1 || row2 == col2 || row2 == col3 || row3 == col1 || row3 == col2 || row3 == col3)
	{
		cout << "The vector is symmetrical" << endl;
	}
	else
	{
		cout << "The vector is not symmetrical" << endl;
	}
}

static void six()
{
	double game;
	cout << "Enter number of games: " << endl;
	cin >> game;
	int win = 0;
	int rolls = 0;
	srand(time(nullptr));

	for (int i = 0; i < game; ++i)
	{
		int player = 0; 
		int dealer = 0;

		for (int j = 0; j < 3; ++j)
		{
			dealer += (rand() % 11) + 1;
		}

		if (dealer > 21)
		{
			cout << "Dealer bust." << endl;
			win++;
			continue;
		}
		else if (dealer == 21)
		{
			cout << "Dealer natural victory." << endl;
			continue;
		}

		while (player < dealer && player < 21)
		{
			cout << "Player: " << player << "\nDealer: " << dealer << endl;
			player += rand() % 6 + 1;
			rolls++;
		}

		if (player > dealer && player <= 21)
		{
			cout << "Player: " << player << "\nDealer: " << dealer << "\nWin!" << endl;
			win++;
		}
		else
		{
			cout << "Player: " << player << "\nDealer: " << dealer << "\nLoss." << endl;
		}
	}

	cout << "Win percentage: " << (static_cast<double>(win) / game) * 100.0 << "\nAverage rolls: " << (rolls / game) << endl;
}

static void select()
{
	int var;
	cout << "1. A tale of two arrays\n2. Direction\n3. Difference\n4. Compare\n5. Symmetry\n6. Blackjack" << endl;
	cin >> var;

	switch (var)
	{
		case 1:
			one();
			return;

		case 2:
			two();
			return;

		case 3:
			three();
			return;

		case 4:
			four();
			return;

		case 5:
			five();
			return;

		case 6:
			six();
			return;

		default:
			MessageBox(nullptr, L"ERROR", L"RETRY", MB_OK);
			cout << endl;
	}
}

int main()
{
	while (true)
	{
		select();
	}
}