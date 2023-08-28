#include <iostream>
#include <vector>

//정수값을 저장하는 간단한 사전
using uint = unsigned int;

class hash_map
{
	std::vector<int> data;

public:
	hash_map(size_t dataSize)
	{
		//모든 원소 -1로 초기화 ( 음수데이터 사용X, 해당위치에 저장된 원소 없음을 함
		data = std::vector<int>(dataSize, -1);
	}

	//삽입함수
	void insert(uint value)
	{
		//이 함수는 계산된 해시 값 위치에 이미 다른 값이 존재하는지 확인하지 않는다.
		//즉 특정 위치에 이미 다른 값이 존재 하더라도 단순 덮어씌우기 된다.
		//해시 값 중복이 될 경우 나중 삽입 값만 저장된다.
		int n = data.size();
		data[value % n] = value; 
		std::cout << value << "을(를) 삽입 했습니다." << std::endl;
	}

	//특정 원소가 맵에 있는지 확인하는 룩업 함수
	bool find(uint value)
	{
		//해당 위치에 저장된 값이 value와 같은지 확인
		int n = data.size();
		return (data[value % n] == value);
	}

	void erase(uint value)
	{
		int n = data.size();
		if (data[value % n] == value)
		{
			data[value % n] = -1;
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
			std::cout << " 해시 맵에서" << value << "을(를) 찾았습니다.";

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