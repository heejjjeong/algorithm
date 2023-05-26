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
	//삽입정렬로 푸는 문제
	int n, s, temp, pos;

	cin >> s; //5
	vector<int> cache(s);
	cin >> n; //9

	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		bool check = false;
		pos = -1;
		for (int j = 0; j < s; ++j)
		{
			if (temp == cache[j]) // 캐시 있으면 
			{
				check = true;
				pos = j;
				break;
			}
		}

		int j = check ? pos : s - 1; //check true : 캐시히트, check false : 캐시미스
		for (; j >= 1; --j)
		{
			cache[j] = cache[j - 1];
		}
		cache[0] = temp;
	}

	for (int i = 0; i < s; ++i) //출력할 5개의 수
	{
		cout << cache[i] << " ";
	}

	/*
	int s, n, temp = 0;
	cin >> s; //5
	vector<int> vec;
	cin >> n; //9

	for (int i = 0; i < n; ++i) //들어올때마다 바로바로 넣어주기
	{
		cin >> temp;
		bool check = false;
		//같은 수가 없다면 맨앞에 insert함
		for (int j = 0; j < vec.size(); ++j)
		{
			if (temp == vec[j]) //같은게 있다면
			{
				check = true;
				vec.erase(vec.begin() + j); //j위치원소 삭제하고
				vec.insert(vec.begin(), temp); //앞에 temp넣기
			}
		}

		if (!check) //같은게 없었다
		{
			vec.insert(vec.begin(), temp); //앞에 temp넣기
		}
	}

	for (int i = 0; i < s; ++i) //출력할 5개의 수
	{
		cout << vec[i] << " ";
	}
	*/
	return 0;
}
