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
	//n부터 1까지 작아지면서 처리
	
	int n, i, j, pos;
	cin >> n;
	vector<int> is(n + 1), os(n + 1);

	for (i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		is[i] = temp;
	}

	for (i = n; i >= 1; --i)
	{
		pos = i;
		for (j = 1; j <= is[i]; ++j)
		{
			os[pos] = os[pos] + 1;
			pos++;
		}
		os[pos] = i;
	}

	/*
	int n, temp;
	cin >> n;
	vector<int> InvSeq;
	vector<int> Res;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> temp; // 5 3 4 0 2 1 1 0
		InvSeq.push_back(temp);
		Res.push_back(i + 1);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < InvSeq[n - i - 1]; ++j) //index 7부터 0까지
		{
			temp = Res[n - i - 1 + j];
			Res[n - i - 1 + j] = Res[n - i + j];
			Res[n - i + j] = temp;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << Res[i] << " " ;
	}
	*/
	return 0;
}
