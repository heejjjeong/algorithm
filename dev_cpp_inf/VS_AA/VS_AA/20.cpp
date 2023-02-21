#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	//FILE* stream;
	//errno_t err;
	//
	//freopen_s(&stream, "input.txt", "r", stdin);

	int n = 0, temp = 0, i = 0;
	cin >> n;

	vector<int> A;
	vector<int> B;

	for (i = 0; i < n; ++i)
	{
		cin >> temp;
		A.push_back(temp);
	}
	for (i = 0; i < n; ++i)
	{
		cin >> temp;
		B.push_back(temp);
	}

	for (i = 0; i < n; ++i)
	{
		int result = abs(A[i] - B[i]);
		if (0 == result)
			cout << "D" << endl;
		else if (1 == result)
		{
			if (A[i] > B[i])
				cout << "A" << endl;
			else
				cout << "B" << endl;
		}
		else if (2 == result)
		{
			if (A[i] > B[i])
				cout << "B" << endl;
			else
				cout << "A" << endl;
		}	
	}


	return 0;
}