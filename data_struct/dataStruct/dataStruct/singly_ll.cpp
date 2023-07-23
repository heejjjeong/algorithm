#include <iostream>
#include <algorithm>

struct singly_ll_node //노드에는 값과 다음 노드의 주소가 존재
{
	int data; //값 
	singly_ll_node* next; //다음 노드의 주소
};

class singly_ll
{
public:
	//using 의 type alias
	using node = singly_ll_node;
	using node_ptr = node*;

private:
	node_ptr head; //제일 앞 노드 주소

public:
	//제일 앞에 노드 삽입
	void push_front(int val)
	{
		//새로운 노드 생성
		auto new_node = new node{ val, nullptr };

		//head가 있다면 생긴 새로운 노드의 next노드가 head가 됨
		if (head != nullptr)
			new_node->next = head;

		//그리고 head는 새로 생긴 노드가 차지함
		head = new_node;
	}

	//제일 앞에 노드 삭제
	void pop_front()
	{
		//head를 저장해두고 ( 저장 안하고 head 노드에 다른 값 덮어 씌우면 위치 못찾음 )
		auto first = head;
		if (head)
		{
			//원래 있던 head가 없어져야 하니까 원래 head에 head의 다음 노드를 저장
			head = head->next; 
			delete first; //원래 head가 있던 메모리 삭제
		}
	}

	struct singly_ll_iterator //노드 반복자
	{
	private:
		node_ptr ptr; //노드 주소

	public:
		singly_ll_iterator(node_ptr p) : ptr(p) {}

		int& operator*() { return ptr->data; }

		node_ptr get() { return ptr; }

		singly_ll_iterator& operator++() // 선행 증가
		{
			ptr = ptr->next;
			return *this;
		}

		singly_ll_iterator operator++(int) // 후행 증가
		{
			singly_ll_iterator result = *this;
			++(*this);
			return result;
		}

		friend bool operator==(const singly_ll_iterator& left, const singly_ll_iterator& right)
		{
			return left.ptr == right.ptr;
		}

		friend bool operator!=(const singly_ll_iterator& left, const singly_ll_iterator& right)
		{
			return left.ptr != right.ptr;
		}
	};

	singly_ll_iterator begin() { return singly_ll_iterator(head); }
	singly_ll_iterator end() { return singly_ll_iterator(nullptr); }
	singly_ll_iterator begin() const { return singly_ll_iterator(head); }
	singly_ll_iterator end() const { return singly_ll_iterator(nullptr); }

	singly_ll() = default;

	singly_ll(const singly_ll& other) : head(nullptr)
	{
		if (other.head)
		{
			head = new node{ 0, nullptr };
			auto cur = head;
			auto it = other.begin();
			while (true)
			{
				cur->data = *it;

				auto tmp = it;
				++tmp;
				if (tmp == other.end())
					break;

				cur->next = new node{ 0, nullptr };
				cur = cur->next;
				it = tmp;
			}
		}
	}

	singly_ll(const std::initializer_list<int>& ilist) : head(nullptr)
	{
		for (auto it = std::rbegin(ilist); it != std::rend(ilist); it++)
			push_front(*it);
	}
};

int main()
{
	singly_ll sll = { 1, 2, 3 };
	sll.push_front(0);

	std::cout << "첫 번째 리스트: ";
	for (auto i : sll)
		std::cout << i << " "; // 출력: 0 1 2 3
	std::cout << std::endl;

	auto sll2 = sll;
	sll2.push_front(-1);
	std::cout << "첫 번째 리스트를 복사한 후, 맨 앞에 -1을 추가: ";
	for (auto i : sll2)
		std::cout << i << ' '; // 출력: -1 0 1 2 3
	std::cout << std::endl;

	std::cout << "깊은 복사 후 첫 번째 리스트: ";

	for (auto i : sll)
		std::cout << i << ' '; // 출력: 0 1 2 3
	std::cout << std::endl;
}
