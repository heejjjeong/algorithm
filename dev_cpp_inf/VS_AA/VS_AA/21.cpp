#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdlib.h>

using namespace std;

int main()
{
	//FILE* stream;
	//errno_t err;
	//
	//freopen_s(&stream, "input.txt", "r", stdin);

	int round = 10, temp = 0, i = 0, resA = 0, resB = 0;
	string win = "";
	vector<int> A;
	vector<int> B;

	for (i = 0; i < round; ++i)
	{
		cin >> temp;
		A.push_back(temp);
	}
	for (i = 0; i < round; ++i)
	{
		cin >> temp;
		B.push_back(temp);
	}
	
	for (i = 0; i < round; ++i)
	{
		if (A[i] > B[i])
		{
			resA += 3;
			win = 'A';
		}
		else if (A[i] < B[i])
		{
			resB += 3;
			win = 'B';
		}
		else if (A[i] == B[i])
		{
			resA += 1;
			resB += 1;
		}
	}
	if ("" == win)
	{
		win = 'D';
	}

	cout << resA << " " << resB << endl;
	cout << win << endl;

	return 0;
}