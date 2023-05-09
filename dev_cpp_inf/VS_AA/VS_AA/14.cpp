#include <stdio.h> 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int reverse(int x)
{
	int res = 0, temp;
	while (x > 0) // 3700 370 37 3
	{
		temp = x % 10; // 0 // 0 // 7 // 3
		res = res * 10 + temp; // 0 // 0 // 7 // 73
		x = x / 10; // 370 // 37 // 3 // 0
	}
	return res; // 73
}

bool isPrime(int x)
{
	int i = 0;
	bool flag = true;
	if (1 == x)
	{
		return false;
	}

	for (int i = 2; i < x; ++i)
	{
		if (0 == x % i)
		{
			flag = false;
			break;
		}
	}
	return flag;
}

int main() 
{
	FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);
	
	int n, num = 0, result, temp = 0;
	
	cin >> n;
	
	for(int i = 1; i <= n; ++i)
	{
		cin >> num;
		temp = reverse(num); //뒤집은 수
		if (isPrime(temp))
		{
			cout << temp << " " ;
		}
	}

	return 0;
}

/*
* 수정 전 코드
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int reverse(int x)
{
	string str = to_string(x);

	for(int i = 0; i < str.length() / 2; ++i)
	{
		swap(str[i], str[str.length()-i-1]);
	}

	return stoi(str);
}

bool isPrime(int x)
{
	for(int i = 2; i <= sqrt(x); ++i)
	{
		if(0 == x%i)
		{
			return false;
		}
	}
	return true;
}

int main() {
	//freopen("input.txt", "rt", stdin);

	int n, result, temp = 0;
	vector<int> vec;

	cin >> n;
	vec.reserve(n);

	for(int i = 0; i < n; ++i)
	{
		cin >> temp;
		vec.push_back(temp);
		result = reverse(vec.back());

		if(result >= 2 && isPrime(result))
		{
			cout << result << endl;
		}
	}

	return 0;
}

*/