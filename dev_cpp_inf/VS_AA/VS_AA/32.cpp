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
	
	int n = 0, temp = 0, pos = 0;
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
			if (sort[pos] > sort[i])
			{
				pos = i;
			}
		}

		//swap
		temp = sort[j];
		sort[j] = sort[pos];
		sort[pos] = temp;
	}
	
	for (int i = 0; i < n; ++i)
	{
		cout << sort[i] << endl;
	}
	return 0;
}
