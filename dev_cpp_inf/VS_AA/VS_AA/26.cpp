#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	//FILE* stream;
	//errno_t err;

	//freopen_s(&stream, "input.txt", "r", stdin);

	int N, i = 0, temp = 0;
	vector<int> vec;
	vector<int> res;

	cin >> N;
	for (i = 0; i < N; ++i)
	{
		cin >> temp;
		vec.push_back(temp);
		res.push_back(i + 1);
	}
	
	for (i = 0; i < N; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (vec[j] < vec[i])
			{
				--res[i];
			}
		}
	}

	for (i = 0; i < N; ++i)
	{
		cout << res[i] << endl;
	}
	return 0;
}