#include <string>
#include <iostream>
#include <forward_list>

struct citizen
{
	std::string name;
	int age;
};

std::ostream &operator<<(std::ostream& os, const citizen& c)
{
	return (os << "[" << c.name << ", " << c.age << "]");
}

int main()
{
	std::forward_list<citizen> citizens =
	{
		{"kim", 22}, {"Lee", 25},{"Part", 18},{"Jin", 16}
	};

	auto citizens_copy = citizens; // 깊은 복사

	std::cout << "전체 시민들 : ";
	for (const auto& c : citizens)
		std::cout << c << " ";

	//투표권이 없는 시민 제거 ( 나이 19 미만 )
	citizens.remove_if([](const citizen& c)
		{
			return (c.age < 19);
		});

	std::cout << "투표권이 있는 시민들 : ";
	for (const auto& c : citizens)
		std::cout << c << " ";

	//내년에 투표권이 생기는 사람
	citizens_copy.remove_if([](const citizen& c)
		{
			return (c.age != 18);
		});

	std::cout << "내년에 투표권이 생기는 시민들 : ";
	for (const auto& c : citizens)
		std::cout << c << " ";
	std::cout << std::endl;
}