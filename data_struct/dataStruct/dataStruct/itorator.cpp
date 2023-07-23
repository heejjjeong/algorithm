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
	
	auto it = vec.begin(); //����ð�
	std::cout << "���� �ֱ� �����: " << *it << std::endl;

	it += 8; //����ð�
	std::cout << "8���� �����: " << *it << std::endl;

	advance(it, -3); //����ð�
	std::cout << "�� �� 3�� �� �����: " << *it << std::endl;

	//forward list ���
	std::forward_list<std::string> fwd(vec.begin(), vec.end());

	auto it_f = fwd.begin();
	std::cout << "���� �ֱ� �����: " << *it_f << std::endl;

	advance(it_f, 5); // �����ð�
	std::cout << "5�� �� �����: " << *it_f << std::endl;

	//std::forward_list�� ���������θ� �̵��� �� �����Ƿ� �Ʒ��� ���� �ڵ�� error
	//advance(it_f, -2);
	//it_f += 8;
}