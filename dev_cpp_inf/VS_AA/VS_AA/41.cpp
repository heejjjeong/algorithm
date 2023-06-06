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
	
	int a, b = 1, cnt = 0, temp = 0, i;
	cin >> a;

	temp = a;
	--a;
	while (a > 0)
	{
		b++;
		a -= b;
		if (0 == a % b)
		{
			for (i = 1; i < b; ++i)
			{
				cout << (a / b) + i << " + ";
			}
			cout << (a / b) + i << " = " << temp << endl;
			cnt++;
		}
	}

	cout << cnt << endl;
	/*

	div = (num + 1) / 2;

	bool check = false;

	for (int i = div; i > 0; --i)
	{
		int temp = i;
		while (!check)
		{
			if (num == sum)
			{
				++cnt;
				break;
			}

			sum += (temp--);

			if (sum > num) // sum 이 15보다 커지면
			{
				sum = 0;
				break;
			}

			if (0 == temp)
			{
				check = true;
				if (num == sum)
				{
					++cnt;
					break;
				}
			}
		}

		if (sum == num)
		{
			sum = 0;
			check = false;

			for (int j = temp + 1; j <= i; ++j)
			{
				if (j != i)
				{
					cout << j << " + ";
				}
				else
				{
					cout << j << " = " << num << endl;
				}
			}
		}
	}

	cout << cnt << endl;
	*/
	return 0;
}
