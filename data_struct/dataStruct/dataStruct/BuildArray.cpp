#include <array>
#include <iostream>
#include <type_traits>

//�پ��� Ÿ���� ������ �������� ���ڷ� �޾� ���� Ÿ������ ��ȯ�ϴ� �Լ�
//�Է� ������ Ÿ���� ��ȣ�� ���� ȿ�������� ��� ����
template<typename ... Args>
//�� �۾��� �Լ� ���ڿ� �������̱� ������ �Լ� ��ȯ���� ���� ���� Ÿ������ ����
auto BuildArray(Args&&... args) -> std::array<typename std::common_type <Args...>::type, sizeof...(args) >
{
	using commonType = typename std::common_type<Args...>::type;

	//�迭 ����
	return { std::forward<commonType>((Args&&)args)... };
}

int main()
{
	auto data = BuildArray(1, 0u, 'a', 3.2f, false); //��� float ������ ��ȯ����
	
	//�ϳ��� ���� Ÿ������ ��ȯ �Ұ���
	//���ڿ��� ���ڸ� ��� ǥ���� �� �ִ� ������ �ڷ����� �������� ����
	//auto data = BuildArray(1, "packet", 2.0);

	for (auto i : data)
		std::cout << i << " ";

	std::cout << std::endl;
}