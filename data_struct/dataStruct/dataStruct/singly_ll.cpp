#include <iostream>
#include <algorithm>

struct singly_ll_node //��忡�� ���� ���� ����� �ּҰ� ����
{
	int data; //�� 
	singly_ll_node* next; //���� ����� �ּ�
};

class singly_ll
{
public:
	//using �� type alias
	using node = singly_ll_node;
	using node_ptr = node*;

private:
	node_ptr head; //���� �� ��� �ּ�

public:
	//���� �տ� ��� ����
	void push_front(int val)
	{
		//���ο� ��� ����
		auto new_node = new node{ val, nullptr };

		//head�� �ִٸ� ���� ���ο� ����� next��尡 head�� ��
		if (head != nullptr)
			new_node->next = head;

		//�׸��� head�� ���� ���� ��尡 ������
		head = new_node;
	}

	//���� �տ� ��� ����
	void pop_front()
	{
		//head�� �����صΰ� ( ���� ���ϰ� head ��忡 �ٸ� �� ���� ����� ��ġ ��ã�� )
		auto first = head;
		if (head)
		{
			//���� �ִ� head�� �������� �ϴϱ� ���� head�� head�� ���� ��带 ����
			head = head->next; 
			delete first; //���� head�� �ִ� �޸� ����
		}
	}

	struct singly_ll_iterator //��� �ݺ���
	{
	private:
		node_ptr ptr; //��� �ּ�

	public:
		singly_ll_iterator(node_ptr p) : ptr(p) {}

		int& operator*() { return ptr->data; }

		node_ptr get() { return ptr; }

		singly_ll_iterator& operator++() // ���� ����
		{
			ptr = ptr->next;
			return *this;
		}

		singly_ll_iterator operator++(int) // ���� ����
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

	std::cout << "ù ��° ����Ʈ: ";
	for (auto i : sll)
		std::cout << i << " "; // ���: 0 1 2 3
	std::cout << std::endl;

	auto sll2 = sll;
	sll2.push_front(-1);
	std::cout << "ù ��° ����Ʈ�� ������ ��, �� �տ� -1�� �߰�: ";
	for (auto i : sll2)
		std::cout << i << ' '; // ���: -1 0 1 2 3
	std::cout << std::endl;

	std::cout << "���� ���� �� ù ��° ����Ʈ: ";

	for (auto i : sll)
		std::cout << i << ' '; // ���: 0 1 2 3
	std::cout << std::endl;
}
