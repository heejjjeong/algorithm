#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	//�� ������ for���� ���鼭 Ǫ�°� �ƴ϶� ���μ����ظ� ����ؼ� 2�� 5�� �������� 10�� ���ͼ� ����� 0�� ������ ���ϴ� ������
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