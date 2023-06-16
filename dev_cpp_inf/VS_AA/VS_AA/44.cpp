#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//#define TEST

int Count(int Dis, const int N, const vector<int>& Vec)
{
	int pos = 0, next = 1, cnt = 1;

	for (int i = 0; i < N - 1; ++i)
	{
		if (Dis <= Vec[pos + next] - Vec[pos])
		{
			pos += next;
			next = 1;
			++cnt;
		}
		else
			++next;
	}
	
	return cnt;
}
int main()
{
#ifdef TEST
	FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);
#endif
	/*
	이분검색 결정알고리즘
	결정 알고리즘 : 답을 정해두고 답이 맞는지 아닌지 좁혀 나아가는 알고리즘
	좁혀 나아가는 과정에서 이분 검색을 사용한다.

	<풀이과정>
	
	*/
	
	int n, c, temp, lt, rt, mid, max = -1, cnt = 0;
	vector<int> vec;
	cin >> n >> c;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end());

	lt = vec.front();
	rt = vec.back();
	while (lt <= rt)
	{
		mid = (lt + rt) / 2;
		cnt = Count(mid, n, vec);
		if (cnt < c)
		{
			rt = mid - 1;
		}
		else if (cnt >= c)
		{
			lt = mid + 1;
			if (max < mid)
			{
				max = mid;
			}
		}
	}
	cout << max;

	return 0;
}