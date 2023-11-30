#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <Windows.h>

using namespace std;

template<typename Type>
Type GetNumber(const char* S)
{
	Type a;
	cout << S << ": ";
	while (!(cin >> a) or (a >= 9 or a < 0))
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Try again: ";
	}
	return a;
}


vector<vector<int>> fillInTheField(int n, int m);

void printMatrixCentered(const std::vector<std::vector<int>>& matrix);

void showThefield(vector<vector<int>>field);

bool isMatrixGrow(vector<vector<int>> Matrix, bool* isError);

vector<int>find_number(vector<vector<int>>Matrix, int num);

void swaps(vector<vector<int>>& Matrix, int* count);

void gotoxy(int x, int y);