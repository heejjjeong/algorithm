//#include <stdio.h>
//#include <iostream>
//#include <string>
//#include <stack>
//
//using namespace std;
//
//#define TEST
//int main()
//{
//#ifdef TEST
//	FILE* stream;
//	errno_t err;
//
//	freopen_s(&stream, "input.txt", "r", stdin);
//#endif
//	int n, P = 0, O = 1;
//	int a[31] = {};
//	stack<int> step;
//	cin >> n;
//	string str;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> a[i];
//	}
//	while (O <= n)
//	{
//		if (step.empty())
//		{
//			step.push(a[P]);
//			str += "P";
//			P++;
//			continue;
//		}
//		if (step.top() == O)
//		{
//			step.pop();
//			str += "O";
//			O++;
//			continue;
//		}
//		step.push(a[P]);
//		P++;
//		if (P > n)
//		{
//			cout << "impossible";
//			return 0;
//		}
//		str +="P";
//	}
//	
//	cout << str;
//
//	return 0;
//}