#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeSort(vector<int> v1, vector<int> v2);

void recursive(vector<int>& v)
{
	int mid = v.size() / 2;

	vector<int> v1 = vector<int>(v.begin(), v.begin() + mid);
	vector<int> v2 = vector<int>(v.begin() + mid, v.end());

	if (v1.size() <= 1 && v2.size() <= 1)
	{
		v = mergeSort(v1, v2);
		return;
	}
	recursive(v1);
	recursive(v2);
	v = mergeSort(v1, v2);
}

vector<int> mergeSort(vector<int> v1, vector<int> v2)
{
	int p1 = 0, p2 = 0;
	vector<int> newVec;
	while (p1 < v1.size() && p2 < v2.size())
	{
		if (v1[p1] > v2[p2])
		{
			newVec.push_back(v2[p2]);
			++p2;
		}
		else
		{
			newVec.push_back(v1[p1]);
			++p1;
		}
	}

	if (p1 < p2)
	{
		for (int i = p1; i < v1.size(); ++i)
			newVec.push_back(v1[i]);
	}
	else
	{
		for (int i = p2; i < v2.size(); ++i)
			newVec.push_back(v2[i]);
	}

	return newVec;
}
#define TEST
int main()
{
#ifdef TEST
	FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);
#endif
	/*
	* 한 개의 배열을 계속 두개씩 쪼개다가 한개일때부터 다시 합친다.
	*/

	int n , temp;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		vec[i] = temp;
	}
	
	recursive(vec);
	
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << " ";
	}

	return 0;
}