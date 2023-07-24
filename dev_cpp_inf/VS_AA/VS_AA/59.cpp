#include <stdio.h>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;
int n = 0;

void recursive(int t, vector<int>& vec)
{
	if (t > n)
	{
		for (int i = 0; i < t; ++i)
		{
			if (vec[i] == 1)
				cout << i << " " ;
		}
		cout << endl;
		return;
	}
	
	vec[t] = 1;
	recursive(t+1, vec);
	vec[t] = 0;
	recursive(t + 1, vec);
}

#define TEST
int main()
{
#ifdef TEST
	FILE* stream;
	errno_t err;

	freopen_s(&stream, "input.txt", "r", stdin);
#endif

	cin >> n;
	vector<int> vec(n + 1, 0);

	recursive(1,vec);

	return 0;
}