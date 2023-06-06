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
	/*
	2중for문 돌리면 시간초과 뜨고
	2point로 풀기..
	*/

	int n, m, i, p1 = 0, p2 = 0, p3 = 0;
	cin >> n;
	vector<int> a(n);
	for (i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		a[i] = temp;
	}
	cin >> m;
	vector<int> b(m), c(n + m);
	for (i = 0; i < m; ++i)
	{
		int temp;
		cin >> temp;
		b[i] = temp;
	}
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	while (p1 < n && p2 < m)
	{
		if (a[p1] == b[p2])
		{
			c[p3++] = a[p1++];
			p2++; //교집합일때 동시 증가
		}
		else if (a[p1] < b[p2])
			p1++;
		else
			p2++;
	}

	for (i = 0; i < p3; ++i)
	{
		cout << c[i] << " ";
	}
	/*vector<int> first, second, res;
	int N, M, pos1 = 0, pos2 = 0, temp;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		first.push_back(temp);
	}

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> temp;
		second.push_back(temp);
	}

	sort(first.begin(), first.end());
	sort(second.begin(), second.end());

	int Size = N >= M ? N : M;
	while(true)
	{
		if (pos1 > N - 1 || pos2 > M - 1 )
			break;

		if (first[pos1] == second[pos2])
		{
			res.push_back(first[pos1]);
			pos1++;
		}

		else if (first[pos1] < second[pos2])
			pos1++;
		else if (first[pos1] > second[pos2])
			pos2++;
	}


	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << " ";
	}*/
	return 0;
}
