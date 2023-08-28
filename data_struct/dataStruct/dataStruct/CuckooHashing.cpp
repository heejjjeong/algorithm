#include <iostream>
#include <vector>

//뻐꾸기해싱
class hash_map
{
	//2개의 해시테이블 사용, 테이블 크기 저장
	std::vector<int> data1;
	std::vector<int> data2;
	int size;

public:
	//2개의 해시함수 ( 각각의 해시테이블은 다른 해시함수를 가져야함)
	int hashFunc1(int key) const
	{
		return key % size;
	}
	int hashFunc2(int key) const
	{
		return (key / size) % size;
	}

	//해시테이블 초기화
	hash_map(int n) : size(n)
	{
		data1 = std::vector<int>(size, -1);
		data2 = std::vector<int>(size, -1);
	}

	//룩업을 수행하는 함수
	std::vector<int>::iterator lookup(int key)
	{
		//양쪽 해시테이블에서 키를 검색하고 해당 위치를 나타내는 반복자를 반환.
		auto hash_value1 = hashFunc1(key);
		if (data1[hash_value1] == key)
		{
			std::cout << "1번 테이블에서 " << key << "을(를) 찾았습니다" << std::endl;
			return data1.begin() + hash_value1;
		}

		auto hash_value2 = hashFunc2(key);
		if (data2[hash_value2] == key)
		{
			std::cout << "2번 테이블에서 " << key << "을(를) 찾았습니다" << std::endl;
			return data2.begin() + hash_value2;
		}

		//만약 원소를 찾지 못하면 data2 테이블의 마지막 반복자 반환
		return data2.end();
	}

	void erase(int key)
	{
		auto position = lookup(key);
		if (position != data2.end()) //찾았으면
		{
			*position = -1; //초기화
			std::cout << key << "에 해당하는 원소를 삭제했습니다." << std::endl;
		}
		else
		{
			std::cout << key << "키를 찾지 못해 삭제하지 못했니다." << std::endl;
		}
	}

	void insert(int key)
	{
		insert_impl(key, 0, 1);
	}

	//삽입은 재귀적으로 동작
	//삽입함수에서는 순환 여부를 검사해야함
	//그러나 방문한 위치의 모든 값을 기억하는 것은 부담이 크다.
	//그러므로 단순히 재귀 호출 횟수가 몇회이상이 되면 순환으로 간주
	//이때 최대 재귀 호출 횟수는 테이블 크기와 같게 설정한다.
	void insert_impl(int key, int cnt, int table)
	{
		if (cnt >= size)
		{
			std::cout << key << " 삽입 시 사이클 발생! 재해싱이 필요합니다!" << std::endl;
			return;
		}

		if (table == 1)
		{
			int hash = hashFunc1(key);
			if (data1[hash] == -1)
			{
				std::cout << table << "번 테이블에 " << key << " 삽입" << std::endl;
				data1[hash] = key;
			}
			else
			{
				int old = data1[hash];
				data1[hash] = key;
				std::cout << table << "번 테이블에 " << key << " 삽입: 기존의 " << old << " 이동 -> ";
				insert_impl(old, cnt + 1, 2);
			}
		}
		else
		{
			int hash = hashFunc2(key);
			if (data2[hash] == -1)
			{
				std::cout << table << "번 테이블에 " << key << " 삽입" << std::endl;
				data2[hash] = key;
			}
			else
			{
				int old = data2[hash];
				data2[hash] = key;
				std::cout << table << "번 테이블에 " << key << " 삽입: 기존의 " << old << " 이동 -> ";
				insert_impl(old, cnt + 1, 1);
			}
		}
	}

	void print()
	{
		std::cout << "Index: ";
		for (int i = 0; i < size; i++)
			std::cout << i << '\t';
		std::cout << std::endl;

		std::cout << "Data1: ";
		for (auto i : data1)
			std::cout << i << '\t';
		std::cout << std::endl;

		std::cout << "Data2: ";
		for (auto i : data2)
			std::cout << i << '\t';
		std::cout << std::endl;
	}
};


int main()
{
	hash_map map(7);
	map.print();
	std::cout << std::endl;

	map.insert(10);
	map.insert(20);
	map.insert(30);
	std::cout << std::endl;

	map.insert(104);
	map.insert(2);
	map.insert(70);
	map.insert(9);
	map.insert(90);
	map.insert(2);
	map.insert(7);
	std::cout << std::endl;

	map.print();
	std::cout << std::endl;

	map.insert(14); // 사이클 발생!
	return 0;
}