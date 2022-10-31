#include <stdio.h> 
#include <string>
#include <iostream>
using namespace std;

//나는 문자열이용해서 풀었는데 선생님은 내가 맨처음에 나누기,모드 연산 했던 걸로 해결함
//방식은 좀 다르지만 그래도,,, 비슷은 했다

int digit_sum(int x) //자연수의 자릿수 합을 구하는 함수 
{
	int temp, sum = 0;
	
	// 125가 들어왔다고 했을 때.. 3자리 수 인것을 알아낼수있는 방법.. 
	// string 으로 받아서 길이 계산?	
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