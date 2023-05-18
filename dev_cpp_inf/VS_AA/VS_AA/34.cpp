#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define TEST

int main()
{
#ifdef TEST
	FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);
#endif
	int n;
	vector<int> vec;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}

	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1 ; ++j)
		{
			if (vec[j] > vec[j + 1])
			{
				int temp = vec[j + 1];
				vec[j + 1] = vec[j];
				vec[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << vec[i] << " ";
	}

	return 0;
}
