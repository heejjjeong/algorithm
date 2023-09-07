#include <iostream>
#include <vector>

using namespace std;

int map[30][30], ch[30], cnt = 0, n;
void DFS(int v) {
	int i;
	if (v == n) {
		cnt++;
	}
	else {
		for (i = 1; i <= n; i++) {
			if (map[v][i] == 1 && ch[i] == 0) {
				ch[i] = 1;
				DFS(i);
				ch[i] = 0;
			}
		}
	}
}


#define TEST
int main()
{
#ifdef TEST
	FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);
#endif
	int m, a, b;

	std::cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		map[a][b] = 1;
	}
	ch[1] = 1;
	DFS(1);
	cout << cnt;

	return 0;
}

