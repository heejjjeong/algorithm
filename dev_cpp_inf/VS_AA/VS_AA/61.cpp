#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
int n , m , result = 0, total = 0;

void recursive(int t, vector<int>& c, vector<int>& v)
{
	if (t > n - 1)
	{
		total = 0;
		for (int i = 0; i < t; ++i)
		{
			if (c[i] == 1)
				total += v[i];
			else if (c[i] == 0)
				continue;
			else
				total -= v[i];
		}
		if (total == m)
			++result;

		return;
	}
	
	c[t] = 1; //더하기
	recursive(t + 1, c, v);
	c[t] = 0; //계산안하기
	recursive(t + 1, c, v);
	c[t] = -1; //빼기
	recursive(t + 1, c, v);
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
	cin >> n >> m;
	vector<int> vec(n + 1);
	vector<int> check(n + 1);

	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		vec[i] = temp;
	}

	recursive(0, check, vec);

	cout << result;

	return 0;
}