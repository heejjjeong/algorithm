#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> vec(9, vector<int>(9, 1));
vector<vector<bool>> check(9, vector<bool>(9, false));
vector<int> dx = { 1, 0, -1 , 0 };
vector<int> dy = { 0, 1, 0 , -1 };

int result = 0;

void dfs(int posX, int posY)
{
	int xx, yy; //³ª¾Æ °¥ ÁÂÇ¥ 

	if (posX == 7 && posY == 7)
	{
		++result;
	}
	else
	{
		for (int i = 0; i < dx.size(); ++i)
		{
			xx = posX + dx[i];
			yy = posY + dy[i];
			if (xx < 1 || xx > 7 || yy < 1 || yy > 7)
				continue;
			if (vec[xx][yy] == 0 && check[xx][yy] == 0)
			{
				check[xx][yy] = 1;
				dfs(xx, yy);
				check[xx][yy] = 0;
			}
		}
	}
	/*if (check[posX][posY] == true || vec[posX][posY] == 1)
		return;
	check[posX][posY] = true;

	cout << "PosX : " << posX << ", PosY : " << posY << endl;

	if (posX == 7 && posY == 7) 
	{
		check[posX][posY] = false;
		++result;
		cout << result << "¹ø µµÂø" << endl;
		return;
	}

	dfs(posX + 1, posY);

	dfs(posX, posY + 1);

	dfs(posX - 1, posY);

	dfs(posX, posY - 1);

	cout << posX << ", " << posY << " ´Ù½Ã open " << endl;
	check[posX][posY] = false;*/
}

#define TEST
int main()
{
#ifdef TEST
	FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);
#endif
	int temp;

	for (int i = 1; i < 8; ++i)
	{
		for (int j = 1; j < 8; ++j)
		{
			cin >> temp;
			vec[i][j] = temp;
		}
	}

	check[1][1] = 1;
	dfs(1,1);

	cout << result << endl;
	return 0;
}
