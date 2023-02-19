#include <stdio.h> 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//FILE* stream;
	//errno_t err;
	//err = freopen_s(&stream, "input.txt", "r", stdin);

	int n = 0, sum = -1, count = 0, current = 0, temp = 0; 
	cin >> n; // 10
	cin >> count; // 90

	for (int i = 0; i < n; ++i)
	{
		cin >> current;
		if (count < current) // ¿ï¸²
			temp++;
		else
			temp = 0;

		if (sum < temp)
			sum = temp;
	}

	cout << sum;
	return 0;
}