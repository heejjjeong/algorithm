#include <iostream>

int main() {
	//freopen("input.txt","rt",stdin);
	int n,min = 2147483646,max = -2147483647,tempAge,result = 0;

	std::cin>>n;
	
	for(int i = 0; i < n; ++i)
	{
		std::cin>>tempAge;
		
		if(tempAge < min)
			min = tempAge;
		if(tempAge > max)
			max = tempAge;
	}
	
	std::cout << max - min ;
	return 0;
}
