#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

//ü�̴��� ����ϴ� �ؽ����̺�
using uint = unsigned int;

class hash_map
{
	std::vector<std::list<int>> data;

public:
	hash_map(size_t dataSize)
	{
		//��� ���� -1�� �ʱ�ȭ ( ���������� ���X, �ش���ġ�� ����� ���� ������ ��
		data.resize(dataSize);
	}

	//�����Լ�
	void insert(uint value)
	{
		//�� �Լ��� ���� �ؽ� �� ��ġ�� �̹� �ٸ� ���� �����ϴ��� Ȯ������ �ʴ´�.
		//�� Ư�� ��ġ�� �̹� �ٸ� ���� ���� �ϴ��� �ܼ� ������ �ȴ�.
		//�ؽ� �� �ߺ��� �� ��� ���� ���� ���� ����ȴ�.
		int n = data.size();
		data[value % n].push_back(value);
		std::cout << value << "��(��) ���� �߽��ϴ�." << std::endl;
	}

	//Ư�� ���Ұ� �ʿ� �ִ��� Ȯ���ϴ� ��� �Լ�
	bool find(uint value)
	{
		//����Ʈ ��ȸ�ϸ鼭 value���� �ִ��� Ȯ��
		int n = data.size();
		auto& entries = data[value % n]; //����Ʈ����
		return std::find(entries.begin(), entries.end(), value) != entries.end();
	}

	void erase(uint value)
	{
		int n = data.size();
		auto& entries = data[value % n];
		auto iter = std::find(entries.begin(), entries.end(), value);
		if (iter != entries.end())
		{
			entries.erase(iter);
			std::cout << value << "��(��) �����߽��ϴ�." << std::endl;
		}
	}
};

int main()
{
	//��� ����� ����ϴ� ���� �Լ�
	hash_map MyHashMap(7);

	auto print = [&](int value)
	{
		if (MyHashMap.find(value))
			std::cout << "�ؽ� �ʿ���" << value << "��(��) ã�ҽ��ϴ�.";
		else
			std::cout << "�ؽ� �ʿ��� " << value << "��(��) ã�� ���߽��ϴ�.";
		std::cout << std::endl;
	};

	MyHashMap.insert(2);
	MyHashMap.insert(25);
	MyHashMap.insert(10);
	print(25);

	MyHashMap.insert(100);
	print(100);
	print(2);

	MyHashMap.erase(25);

	return 0;
}