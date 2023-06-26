//#include <stdio.h>
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
////#define TEST
//
//int main()
//{
//#ifdef TEST
//	FILE* stream;
//	errno_t err;
//
//	freopen_s(&stream, "input.txt", "r", stdin);
//#endif
//	int size = 0;
//	int count = 0;
//	int total = 0;
//	vector<int> vec;
//
//	cin >> size;
//	for (int i = 0; i < size; ++i)
//	{
//		int value = 0;
//		cin >> value;
//
//		total += value;
//		vec.push_back(value);
//	}
//	cin >> count;
//
//	if (total <= count)
//	{
//		cout << -1 << endl;
//		return 0;
//	}
//
//	int work = 0;
//	int temp = 0;
//	while (true)
//	{
//		if (vec[work] > temp)
//		{
//			--count;
//
//			if (count == -1)
//				break;
//		}
//
//		work = ++work % size;
//
//		if (work == 0)
//			++temp;
//	}
//
//	cout << vec[work] << endl;
//
//	//int n, k, temp, bp = 0, pos = 0, total = 0;
//	//vector<int> vec;
//
//	//cin >> n;
//	//for (int i = 0; i < n; ++i)
//	//{
//	//	cin >> temp;
//	//	vec.push_back(temp);
//	//	total += temp;
//	//}
//	//cin >> k;
//
//	////-------------------
//	//if (total <= k)
//	//{
//	//	cout << -1;
//	//	return 0;
//	//}
//	//while (true)
//	//{
//	//	if (pos >= n)
//	//		pos = 0;
//	//	if (vec[pos] == 0)
//	//	{
//	//		++pos;
//	//		continue;
//	//	}
//
//	//	--vec[pos];
//	//	++bp;
//
//	//	if (bp == k)
//	//		break;
//
//	//	++pos;
//	//}
//
//	//while (true)
//	//{
//	//	++pos;
//
//	//	if (pos >= n)
//	//		pos = 0;
//
//	//	if (0 != vec[pos])
//	//	{
//	//		cout << pos + 1;
//	//		return 0;
//	//	}
//	//}
//
//	return 0;
//}