#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

//체이닝을 사용하는 해시테이블
using uint = unsigned int;

class hash_map
{
	std::vector<std::list<int>> data;

public:
	hash_map(size_t dataSize)
	{
		//모든 원소 -1로 초기화 ( 음수데이터 사용X, 해당위치에 저장된 원소 없음을 함
		data.resize(dataSize);
	}

	//삽입함수
	void insert(uint value)
	{
		//이 함수는 계산된 해시 값 위치에 이미 다른 값이 존재하는지 확인하지 않는다.
		//즉 특정 위치에 이미 다른 값이 존재 하더라도 단순 덮어씌우기 된다.
		//해시 값 중복이 될 경우 나중 삽입 값만 저장된다.
		int n = data.size();
		data[value % n].push_back(value);
		std::cout << value << "을(를) 삽입 했습니다." << std::endl;
	}

	//특정 원소가 맵에 있는지 확인하는 룩업 함수
	bool find(uint value)
	{
		//리스트 순회하면서 value값이 있는지 확인
		int n = data.size();
		auto& entries = data[value % n]; //리스트나옴
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
			std::cout << value << "을(를) 삭제했습니다." << std::endl;
		}
	}
};

int main()
{
	//룩업 결과를 출력하는 람다 함수
	hash_map MyHashMap(7);

	auto print = [&](int value)
	{
		if (MyHashMap.find(value))
			std::cout << "해시 맵에서" << value << "을(를) 찾았습니다.";
		else
			std::cout << "해시 맵에서 " << value << "을(를) 찾지 못했습니다.";
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