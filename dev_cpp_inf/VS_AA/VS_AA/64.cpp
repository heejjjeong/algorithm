#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

struct Vertex
{
	//int data;
};

int n, m, tempN, tempM, cnt = 0;


void Dfs(int here, const vector<Vertex> Verties, const vector<vector<int>> Adjacent, vector<bool> Visited)
{
	if (Visited[here])
		return;

	Visited[here] = true;

	if ( n == here )
	{
		/*for (int i = 1; i < Visited.size(); ++i)
		{
			if (Visited[i])
				cout << i << " ";
		}
		cout << endl;*/
		++cnt;
		return;
	}

	for (int i = 0; i < Adjacent[here].size(); ++i)
	{
		int there = Adjacent[here][i];
		Dfs(there, Verties, Adjacent, Visited);
	}

}

//#define TEST
int main()
{
#ifdef TEST
	FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);
#endif
	std::cin >> n >> m;
	vector<Vertex> Verties(n + 1);
	vector<vector<int>> Adjacent(n + 1);
	vector<bool> Visited(n + 1, false);

	for (int i = 1; i < m + 1; ++i)
	{
		cin >> tempN >> tempM;
		Adjacent[tempN].push_back(tempM);
	};
	
	Dfs(1, Verties, Adjacent, Visited);

	cout << cnt;

	return 0;
}