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
		head = new node{ nullptr,nullptr,nullptr }; //��� �η� ������ ���� ���
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

		//���⼭���� �ٽ� ¥��
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
			cout << "��� ����� ����ֽ��ϴ�." << endl;
			return;
		}

		circle_ll_node* prev_node = head;
		circle_ll_node* cur_node = head->next;

		if (head->music_title == music_title) {
			if (head == head->next) { // ����Ʈ�� �ϳ��� ��常 �ִ� ���
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

		cout << "��� ��Ͽ��� �ش� ������ ã�� �� �����ϴ�." << endl;
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
			cout << "��� ����� ����ֽ��ϴ�." << endl;
			return;
		}

		circle_ll_node* cur_node = head;
		cout << "��� ���: ";
		while (true) 
		{
			cout << cur_node->music_title << " -> ";
			cur_node = cur_node->next;
			if (cur_node == head)
			{
				break;
			}
		}


		cout << "ó������ ���ư�" << endl;
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
	playlist.insert("�뷡 1");
	playlist.insert("�뷡 2");
	playlist.insert("�뷡 3");
	playlist.insert("�뷡 4");

	playlist.printall(); // ���: ��� ���: �뷡 1 -> �뷡 2 -> �뷡 3 -> �뷡 4 -> ó������ ���ư�

	playlist.next();
	playlist.next();
	playlist.printall(); // ���: ��� ���: �뷡 3 -> �뷡 4 -> �뷡 1 -> �뷡 2 -> ó������ ���ư�

	playlist.remove("�뷡 3");
	playlist.printall(); // ���: ��� ���: �뷡 4 -> �뷡 1 -> �뷡 2 -> ó������ ���ư�

	playlist.previous();
	playlist.printall(); // ���: ��� ���: �뷡 1 -> �뷡 2 -> �뷡 4 -> ó������ ���ư�

	return 0;
}
