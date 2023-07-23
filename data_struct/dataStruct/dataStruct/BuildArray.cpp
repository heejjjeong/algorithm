#include <array>
#include <iostream>
#include <type_traits>

//다양한 타입의 데이터 여러개를 인자로 받아 공통 타입으로 변환하는 함수
//입력 데이터 타입이 모호할 때에 효과적으로 사용 가능
template<typename ... Args>
//이 작업은 함수 인자에 의존적이기 때문에 함수 반환형을 후행 리턴 타입으로 지정
auto BuildArray(Args&&... args) -> std::array<typename std::common_type <Args...>::type, sizeof...(args) >
{
	using commonType = typename std::common_type<Args...>::type;

	//배열 성성
	return { std::forward<commonType>((Args&&)args)... };
}

int main()
{
	auto data = BuildArray(1, 0u, 'a', 3.2f, false); //모두 float 형으로 변환가능
	
	//하나의 공통 타입으로 변환 불가능
	//문자열과 숫자를 모두 표현할 수 있는 공통의 자료형이 존재하지 않음
	//auto data = BuildArray(1, "packet", 2.0);

	for (auto i : data)
		std::cout << i << " ";

	std::cout << std::endl;
}