#include <stdio.h> 
#include <string>
#include <iostream>
using namespace std;

//���� ���ڿ��̿��ؼ� Ǯ���µ� �������� ���� ��ó���� ������,��� ���� �ߴ� �ɷ� �ذ���
//����� �� �ٸ����� �׷���,,, ����� �ߴ�

int digit_sum(int x) //�ڿ����� �ڸ��� ���� ���ϴ� �Լ� 
{
	int temp, sum = 0;
	
	// 125�� ���Դٰ� ���� ��.. 3�ڸ� �� �ΰ��� �˾Ƴ����ִ� ���.. 
	// string ���� �޾Ƽ� ���� ���?	
	string xstr = to_string(x);
	const int xLength =  xstr.length();
	
	for(int i = 0; i < xLength; ++i)
	{
		sum += xstr[i] - '0';
	}
	return sum;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, num, sum, max = -2147000000, result = 0;
	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &num);
		sum = digit_sum(num);
		
		if(max < sum)
		{
			max = sum;
			result = num;
		}
		else if(max == sum)
		{
			if(result < num)
			{
				result = num;
			}
		}
	}
	
	printf("%d\n", result);
	return 0;
}