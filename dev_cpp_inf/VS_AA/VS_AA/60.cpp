#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
int n = 0, total = 0;
bool isSame = false;

void recursive(int t, vector<int>& c, vector<int>& v)
{
	if (isSame)
		return;

	if (t > n - 1)
	{
		int checkTotal = 0;
		for (int i = 0; i < t; ++i)
		{
			if (c[i] == 1)
				checkTotal += v[i];
		}
		if ((total - checkTotal) == checkTotal)
			isSame = true;
		return;
	}
	c[t] = 1;
	recursive(t + 1, c,v);
	c[t] = 0;
	recursive(t + 1, c,v);
}

//#define TEST
int main()
{
#ifdef TEST
	FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);
#endif
	int temp;
	cin >> n;

	vector<int> vec(n + 1);
	vector<int> check(n + 1);

	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		vec[i] = temp;
		total += vec[i];
	}

	recursive(0, check, vec);
	
	if (isSame)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}