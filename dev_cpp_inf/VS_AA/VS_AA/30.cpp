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
	1. 1의 자리엔 무조건 1개가 들어감
	2. 1의 자리가 3보다 크거나 같고 2의 자리수가 넘어가면
	   2의 자리에 있는 수 만큼 갯수가 있는 것 (24면 2개)
	3. 근데 2의 자리수가 3을 넘으면 2의 자리수니까 10 에다 
	   1의 자리가 3보다 큰지 보고 2의 자리에 있는 수 만큼 갯수 있는 것
	   3개. 
	4. 근데 만약 34 같은 수면 앞이 3이긴 하지만 2자리수 3은 5개 이기때문에 
	   1의 자리수 + 1 에다가 1의 자리수 4개 해서 9개
	*/
	int n, temp, pos, cnt = 0;

	cin >> n;
	/*
	temp = n;
	while (temp > 0) //temp = 24;
	{ 
		pos = temp % 10; //pos = 4;

		if (pos > 3)
		{

		}
	}
	*/
	string str = to_string(n);
	unsigned int strSize = str.size();
	for (int i = 0; i < strSize; ++i) //strSize자리수 라는 것
	{
		int num = str[strSize - 1 - i] - '0'; // 1의 자리부터 접근
		if (3 <= num)
		{
			
		}

		else //less 3
		{
			strSize + i

		}

	}
	//4721
	return 0;
}