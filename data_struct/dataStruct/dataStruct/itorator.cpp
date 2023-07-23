#include <iostream>
#include <forward_list>
#include <vector>

int main()
{
	std::vector<std::string> vec = {
	"Lewis Hamilton", "Lewis Hamilton", "Nico Roseberg",
	"Sebastian Vettel", "Lewis Hamilton", "Sebastian Vettel",
	"Sebastian Vettel", "Sebastian Vettel", "Fernando Alonso"
	};
	
	auto it = vec.begin(); //상수시간
	std::cout << "가장 최근 우승자: " << *it << std::endl;

	it += 8; //상수시간
	std::cout << "8년전 우승자: " << *it << std::endl;

	advance(it, -3); //상수시간
	std::cout << "그 후 3년 뒤 우승자: " << *it << std::endl;

	//forward list 사용
	std::forward_list<std::string> fwd(vec.begin(), vec.end());

	auto it_f = fwd.begin();
	std::cout << "가장 최근 우승자: " << *it_f << std::endl;

	advance(it_f, 5); // 선형시간
	std::cout << "5년 전 우승자: " << *it_f << std::endl;

	//std::forward_list는 순방향으로만 이동할 수 있으므로 아래와 같은 코드는 error
	//advance(it_f, -2);
	//it_f += 8;
}