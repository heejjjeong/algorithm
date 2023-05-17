#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//#define TEST

int main()
{
#ifdef TEST
	FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);
#endif

	int n = 0, temp = 0, min = 0, pos = 0;
	vector<int> sort;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		sort.push_back(temp);
	}

	for (int j = 0; j < n; ++j)
	{
		pos = j;
		for (int i = j + 1; i < n; ++i)
		{
			if (sort[pos] < sort[i])
			{
				pos = i;
			}
		}

		//swap
		temp = sort[j];
		sort[j] = sort[pos];
		sort[pos] = temp;
	}
	int cnt = 0;
	for (int i = 1; i < n; ++i)
	{
		if (sort[i-1] != sort[i])
		{
			++cnt;

			if (2 == cnt)
			{
				cout << sort[i] << endl;
				break;
			}
		}
	}

	return 0;
}
