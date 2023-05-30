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

	int a[101] = {}, b[101] = {}, c[301] = {};

	int n, m, i, p1=1, p2=1, p3=1;
	cin >> n;
	for (i = 1; i <= n; ++i)
		scanf_s("%d", &a[i]);

	cin >> m;
	for (i = 1; i <= m; ++i)
		scanf_s("%d", &b[i]);


	while (p1 <= n && p2 <= m)
	{
		if (a[p1] < b[p2])
		{
			c[p3++] = a[p1++];
		}
		else
		{
			c[p3++] = b[p2++];
		}
	}

	while (p1 <= n)
	{
		c[p3++] = a[p1++];
	}
	while (p2 <= m)
	{
		c[p3++] = b[p2++];
	}

	for (i = 1; i < p3 ; ++i)
	{
		cout << c[i] << " ";
	}

	/*int n, temp;
	vector<int> left;
	vector<int> right;
	vector<int> res;

	int leftPos = 0, rightPos = 0;

	for (int j = 0; j < 2; ++j)
	{
		cin >> n;
		
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			if (0 == j)
				left.push_back(temp);
			if (1 == j)
				right.push_back(temp);
		}
	}

	while (leftPos < left.size() && rightPos < right.size())
	{
		if (left[leftPos] < right[rightPos])
		{
			res.push_back(left[leftPos]);
			leftPos++;
		}
		else if (right[rightPos] < left[leftPos])
		{
			res.push_back(right[rightPos]);
			rightPos++;
		}
		else //°°´Ù¸é
		{
			res.push_back(left[leftPos]);
			leftPos++;
			res.push_back(right[rightPos]);
			rightPos++;
		}
	}
	
	if (left.size() > right.size())
	{
		for (int i = leftPos; i < left.size(); ++i)
		{
			res.push_back(left[i]);
		}
	}
	else if (left.size() < right.size())
	{
		for (int i = rightPos; i < right.size(); ++i)
		{
			res.push_back(right[i]);
		}
	}


	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << " ";
	}
	*/
	return 0;
}
