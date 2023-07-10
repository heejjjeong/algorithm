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

	int n, k, temp, bp = 0, pos = 0, total = 0;
	vector<int> vec;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		vec.push_back(temp);
		total += temp;
	}
	cin >> k;

	//-------------------
	if (total <= k)
	{
		cout << -1;
		return 0;
	}
	while (true)
	{
		if (pos >= n)
			pos = 0;
		if (vec[pos] == 0)
		{
			++pos;
			continue;
		}

		--vec[pos];
		++bp;

		if (bp == k)
			break;

		++pos;
	}

	while (true)
	{
		++pos;

		if (pos >= n)
			pos = 0;

		if (0 != vec[pos])
		{
			cout << pos + 1;
			return 0;
		}
	}

	return 0;
}