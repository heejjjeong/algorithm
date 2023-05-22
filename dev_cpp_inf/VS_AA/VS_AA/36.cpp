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
	int n, temp = 0, i , j;
	vector<int> vec;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}

	for (i = 1; i < n - 1; ++i)
	{
		temp = vec[i];
		for (j = i - 1; j >= 0; --j)
		{
			if (vec[j] > temp)
			{
				vec[j + 1] = vec[j];
			}
			else
				break;
		}
		vec[j+1] = temp;
	}

	for (i = 0; i < n; ++i)
	{
		cout << vec[i] << " ";
	}

	return 0;
}
