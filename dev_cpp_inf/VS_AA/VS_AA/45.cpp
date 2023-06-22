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
	int n, k, pos = 0, bp = 0, cnt = 0;
	cin >> n >> k;
	vector<int> prince(n + 1);
	while (true)
	{
		pos++;
		if (pos > n)
			pos = 1;
		if (prince[pos] == 0)
		{
			cnt++;
			if (cnt == k)
			{
				prince[pos] = 1;
				cnt = 0;
				bp++;
			}
		}
		if (bp == n - 1)
			break;
	}

	for (int i = 0; i <= n; ++i)
	{
		if (prince[i] == 0)
		{
			cin >> i;
			break;
		}
	}

	/*
	vector<int> vec;
	int n, k, temp, curPos = 0, pin = 0;

	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		vec.push_back(i);
	}

	while (vec.size() > 1)
	{
		++curPos;
		if (curPos == k - 1)
		{
			if (vec.size() <= curPos + pin)
			{
				curPos = (curPos + pin) % vec.size();
				pin = 0;

			}
			vec.erase(vec.begin() + curPos + pin);
			pin += curPos;
			curPos = 0;
		}
	}

	cout << vec[0];
	*/
	return 0;
}