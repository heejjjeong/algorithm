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

	int n, temp, cnt = 0, max;
	vector<int> student;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		student.push_back(temp);
	}
	max = student.back();
	for (int i = n - 1; i >= 1 ; --i)
	{
		if (max < student[i])
		{
			cnt++;
			max = student[i];
		}
	}

	cout << cnt << endl;

	return 0;
}