#include <stdio.h> 
#include <stack>
#include <algorithm>
int a[50001]; //�ʱ�ȭ������ ������������ 
 	
int main() {
	//freopen("input.txt", "rt", stdin);

	int n;
	
	scanf("%d", &n);
	 
	for(int i = 1; i <= n; ++i)
	{
		for(int j = i; j <= n; j = j + i)	
		{
			++a[j];
		}
		printf("%d ", a[i]);
	}
	
	 
	return 0;
}
