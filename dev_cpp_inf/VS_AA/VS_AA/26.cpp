#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);

	int N = 0, temp = 0, i = 0;
	vector<int> res;
	cin >> N;
	vector<int> vec;
	for (i = 0; i < N; ++i)
	{
		cin >> temp;
		vec.push_back(temp);
		res.push_back(1);
	}

	for (i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i != j)
			{
				if (vec[i] < vec[j])
				{
					++res[i];
				}
			}
		}
	}

	for (i = 0; i < N; ++i)
	{
		cout << res[i] << endl;
	}

	return 0;
}