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

	//freopen_s(&stream, "input.txt", "r", stdin);

	int N = 0, temp = 0;
	cin >> N;

	vector<int> vec;
	vector<bool> check;
	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		vec.push_back(temp);

		if (i < N - 1)
		{
			check.push_back(false);
		}
	}

	for (int i = 0; i < N - 1; ++i)
	{
		temp = abs(vec[i] - vec[i + 1]);
		if (temp <= check.size())
		{
			check[temp - 1] = true;
		}
	}
	
	for (int i = 0; i < check.size(); ++i)
	{
		if (check[i] == false)
		{
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;


	
	return 0;
}