#include <stdio.h> 
#include <iostream>
using namespace std;

int main() {
	freopen("input.txt", "rt", stdin);
	/*
	<����>
	���ڸ����ڴ� 9��, ���ڸ����ڴ� 90��, ���ڸ� ���ڴ� 900��,
	���ڸ� ���ڴ� 9000�� �̷������� ��Ģ ����
	256 ����, ���ڸ� ���ڴ� 9��, ���ڸ� ���ڴ� 90������ �� �ڸ��� ���ϸ� 9 + 180
	�ε�, 256�� 999���ٴ� �����ϱ� ���ϱ�ó�� �ϸ� �ȵǰ� 
	256���� 99������ �������ϱ� ���ָ� 157���� �ִ°���.. 157���� 3�ڸ� ���ڰ� �ִ°���..
	���⿡(157) ���ϱ� 3 �ؼ� ���ؼ� ����ϸ� ��
	*/
	
	//���� ��� �ٽ� Ǭ ���� Ǯ��
	int n, count = 1, sum = 0, mul = 9, res = 0;
	scanf("%d", &n);
	
	
	while( (sum + mul) < n )
	{
		sum += mul;
		res += count * mul;
		++count;
		mul *= 10;
	}
	res += (n-sum) * count;


	printf("%d", res);
	return 0; 
}

/*
//ó�� ���� Ǯ��
#include <stdio.h> 
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);

	int n, count = 0, sum = 0;
	scanf("%d", &n);
	
	string numstr = to_string(n);
	int strlength = numstr.length();
	int temp = n;
	int gap = 0;
	
	while( 9 < temp )
	{
		if(1 < strlength)
		{
			gap = temp - pow(10,strlength - 1);
		}
		
		sum += (gap + 1) * strlength;
		
		temp -= gap + 1;
		
		--strlength;
	}
	if(9 >= temp)
	{
		sum += temp;
	}


	printf("%d", sum);
	return 0; 
}

*/
