#include <stdio.h> 
#include <iostream>
using namespace std;

int main() {
	freopen("input.txt", "rt", stdin);
	/*
	<설명>
	한자리숫자는 9개, 두자리숫자는 90개, 세자리 숫자는 900개,
	네자리 숫자는 9000개 이런식으로 규칙 존재
	256 기준, 한자리 숫자는 9개, 두자리 숫자는 90개여서 각 자리수 곱하면 9 + 180
	인데, 256은 999보다는 작으니까 곱하기처리 하면 안되고 
	256에서 99까지는 나왔으니까 빼주면 157개가 있는거임.. 157개의 3자리 숫자가 있는거임..
	여기에(157) 곱하기 3 해서 더해서 출력하면 됨
	*/
	
	//설명 듣고 다시 푼 문제 풀이
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
//처음 문제 풀이
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
