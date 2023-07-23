#include <iostream>

using namespace std;

template <typename T>
struct cir_list_node 
{
	T* data;
	cir_list_node* next;
	cir_list_node* prev;

	~cir_list_node()
	{
		delete data;
	}
};

template <typename T> 
struct cir_list 
{
public:
	using node = cir_list_node<T>;
	using node_ptr = node*;
	
	node_ptr head;
	size_t n;
public:
	cir_list() : n()
	{
		head = new node{ nullptr,nullptr,nullptr }; //모두 널로 구성된 더미 노드
		head->next = head;
		head->prev = head;
	}

	size_t size() const 
	{
		return n;
	}

	void insert(const T& value) 
	{
		node_ptr newNode = new node{ new T(value), nullptr, nullptr };
		n++;

		//여기서부터 다시 짜기
		circle_ll_node* new_node = new circle_ll_node;
		new_node->music_title = music_title;

		if (head == nullptr) 
		{
			head = new_node;
			head->next = head;
			current = head;
		}
		else 
		{
			new_node->next = head;
			current->next = new_node;
			current = new_node;
		}
	}

	void remove(const string& music_title) 
	{
		if (head == nullptr) {
			cout << "재생 목록이 비어있습니다." << endl;
			return;
		}

		circle_ll_node* prev_node = head;
		circle_ll_node* cur_node = head->next;

		if (head->music_title == music_title) {
			if (head == head->next) { // 리스트에 하나의 노드만 있는 경우
				delete head;
				head = nullptr;
				current = nullptr;
				return;
			}

			head = head->next;
			current->next = head;
			delete prev_node;
			return;
		}

		while (cur_node != head) 
		{
			if (cur_node->music_title == music_title) 
			{
				prev_node->next = cur_node->next;
				delete cur_node;
				return;
			}
			prev_node = cur_node;
			cur_node = cur_node->next;
		}

		cout << "재생 목록에서 해당 음악을 찾을 수 없습니다." << endl;
	}

	void next() {
		if (current != nullptr)
			current = current->next;
	}

	void previous() {
		if (head != nullptr) 
		{
			circle_ll_node* prev_node = head;
			while (prev_node->next != current)
				prev_node = prev_node->next;
			current = prev_node;
		}
	}

	void printall() {
		if (head == nullptr)
		{
			cout << "재생 목록이 비어있습니다." << endl;
			return;
		}

		circle_ll_node* cur_node = head;
		cout << "재생 목록: ";
		while (true) 
		{
			cout << cur_node->music_title << " -> ";
			cur_node = cur_node->next;
			if (cur_node == head)
			{
				break;
			}
		}


		cout << "처음으로 돌아감" << endl;
	}

	~circle_ll() 
	{
		if (head != nullptr) 
		{
			circle_ll_node* cur_node = head;
			circle_ll_node* next_node = nullptr;

			while (cur_node != head) 
			{
				next_node = cur_node->next;
				delete cur_node;
				cur_node = next_node;
			}

		}
	}
};

int main() 
{
	circle_ll playlist;
	playlist.insert("노래 1");
	playlist.insert("노래 2");
	playlist.insert("노래 3");
	playlist.insert("노래 4");

	playlist.printall(); // 출력: 재생 목록: 노래 1 -> 노래 2 -> 노래 3 -> 노래 4 -> 처음으로 돌아감

	playlist.next();
	playlist.next();
	playlist.printall(); // 출력: 재생 목록: 노래 3 -> 노래 4 -> 노래 1 -> 노래 2 -> 처음으로 돌아감

	playlist.remove("노래 3");
	playlist.printall(); // 출력: 재생 목록: 노래 4 -> 노래 1 -> 노래 2 -> 처음으로 돌아감

	playlist.previous();
	playlist.printall(); // 출력: 재생 목록: 노래 1 -> 노래 2 -> 노래 4 -> 처음으로 돌아감

	return 0;
}
