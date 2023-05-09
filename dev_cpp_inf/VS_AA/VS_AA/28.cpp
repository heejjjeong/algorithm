#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	//이 문제는 for문을 돌면서 푸는게 아니라 소인수분해를 사용해서 2와 5를 곱했을때 10이 나와서 생기는 0의 갯수는 구하는 문제ㄴ
	/*FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);*/

	int n, i, j, cnt1 = 0, cnt2 = 0, temp;

	cin >> n;

	for (i = 2; i <= n; ++i)
	{
		temp = i;
		j = 2;
		while (true)
		{
			if (0 == temp % j)
			{
				if (2 == j)
				{
					++cnt1;
				}
				else if (5 == j)
				{
					++cnt2;
				}
				temp = temp / j;
			}
			else
				++j;

			if (1 == temp)
				break;
		}
	}

	if (cnt1 < cnt2)
		cout << cnt1;
	else
		cout << cnt2;

	return 0;
}