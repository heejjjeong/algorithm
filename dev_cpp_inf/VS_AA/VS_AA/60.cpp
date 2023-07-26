#include <stdio.h>
#include <iostream>
#include <vector>
//#include <map>
//#include <utility>
#include <algorithm>

using namespace std;
int n = 0, numSum = 0;

void recursive(int t, /*multimap<int, pair<int,int>>& _m,*/ vector<int>& c, vector<int>& v, vector<int>& s)
{
	if (t > n - 1)
	{
		for (int i = 0; i < t; ++i)
		{
			if (c[i] == 1)
				numSum += v[i];
		}
		s.push_back(numSum);
		numSum = 0;
		return;
	}
	c[t] = 1;
	recursive(t + 1, c,v,s);
	c[t] = 0;
	recursive(t + 1, c,v,s);
}

#define TEST
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
	vector<int> sum;
	//multimap<int, pair<int, int>> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		vec[i] = temp;
	}

	/*
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < pow(2, i); ++j)
		{
			m.emplace(vec[i], pair<int, int>(vec[i + 1], vec[i + 1]));
		}
	}
	*/
	recursive(0,/* m,*/ check, vec, sum);
	
	sort(sum.begin(), sum.end());
	temp = -1;
	for (int i = 0; i < sum.size(); ++i) 
	{
		if (temp == sum[i])
		{
			cout << "YES";
			return 0;
		}
		else
			temp = sum[i];
	}

	cout << "NO";
	return 0;
}