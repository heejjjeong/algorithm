#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//#define TEST
/*
8 32
23 87 65 12 57 32 99 81
*/
int main()
{
#ifdef TEST
	FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);
#endif
	/*
	이분검색
	*/
	int n, m, lt , rt , mid, temp;
	cin >> n; //8
	cin >> m; //32

	vector<int> vec(8);

	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		vec[i] = temp;
	}
	
	sort(vec.begin(), vec.end()); //ascending sort
	lt = 0; rt = n - 1;
	
	while (lt <= rt) //true로 하면 자료가 발견되지 않을대 멈추지 않아서 서로 엇갈렸을때 멈추도록 조건ㄴ
	{
		mid = (lt + rt) / 2;
		if (vec[mid] == m)
		{
			cout << mid + 1;
			return 0;
		}
		else if (vec[mid] > m)
		{
			rt = mid - 1;
		}
		else // vec[mid] < m
		{
			lt = mid + 1;
		}
	}
	
	return 0;
}
