#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

//최소비용 (DFS: 인접행렬)

int procession[30][30]; int check[30][30]; int n, m ; int sum = 0, sumMin = 2147000000;

void DFS(int vertex)
{
    if (n == vertex)
    {
        if (sumMin > sum)
        {
            sumMin = sum;
        }
        return;
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            if (0 < procession[vertex][i] && 0 == check[vertex][i])
            {
                check[vertex][i] = 1;
                sum += procession[vertex][i];
                DFS(i);
                check[vertex][i] = 0;
                sum -= procession[vertex][i];
            }
        }
    }
}

//#define TEST
int main()
{
#ifdef TEST
    FILE* stream;
    freopen_s(&stream, "input.txt", "r", stdin);
#endif
    int tempn, tempm, weight;
    cin >> n >> m; // n = 5, m = 8
    for (int i = 1; i <= m; ++i)
    {
        cin >> tempn >> tempm >> weight;
        procession[tempn][tempm] = weight;
    }

    check[1][1] = 1;
    DFS(1);

    cout << sumMin;
	return 0;
}