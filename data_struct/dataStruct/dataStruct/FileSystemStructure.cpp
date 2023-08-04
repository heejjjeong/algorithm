#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct nTree
{
	//int data;
	string name;
	bool IsFile; //true : file , false : Directory
	vector<nTree*> children;
};

/*
* ���͸� �̵�
* ����, ���͸� �˻�
* ����, ���͸� �߰�
* ����, ���͸� ��� ���
*/
struct bst
{
	nTree* root = nullptr;
	nTree* CurrentDirectory = nullptr;


	nTree* findTree(string path)
	{
		return find_impl(root, path);
	}
	
	private:
	nTree* find_impl(nTree* current, string path)
	{
		if (!current)
		{
			std::cout << std::endl;
			return nullptr;
		}

		if (current->name == path)
		{
			std::cout << str << "��(��) ã�ҽ��ϴ�." << std::endl;
			return current;
		}

		if (str < current->data) // value ���� ���� ��� ���ʿ� �ִ� ���
		{
			std::cout << current->data << "���� �������� �̵�: ";
			return find_impl(current->left, value);
		}

		// value ���� ���� ��� �����ʿ� �ִ� ���
		std::cout << current->data << "���� ���������� �̵�: ";
		return find_impl(current->right, value);
	}

public:
	void insert(string path, bool IsFileCheck)
	{
		if (!root)
		{
			root = new nTree{ path, IsFileCheck, vector<nTree*>() };
			CurrentDirectory = root;
		}
		else
		{
			insert_impl(root, path, IsFileCheck); //heejeong , directory
		}
	}

private:
	void insert_impl(nTree* current, string path, bool IsFileCheck)
	{
		/*
		* ��ο� / ��¼�� ������ �ش� ��η� �־��ְ�.. �ƴϸ� �ٷ� ��Ʈ�� �־������
		*/

		if (string::npos == path.find('/')) // /�� ���ٸ� �׳� ��Ʈ�� �߰��ϴ� ��
		{
			if (IsFileCheck) //�߰��ϴ� ���� �����̶��
			{
				nTree* file = new nTree{ path, IsFileCheck, vector<nTree*>(0) };
				current->children.emplace_back(file);
			}
			else //���丮���
			{
				nTree* directory = new nTree{ path, IsFileCheck, vector<nTree*>() };
				current->children.emplace_back(directory);
				CurrentDirectory = current->children.back(); //���� �������� �־��� ������ CurrentDirectory ����
			}
		}
		else //�ٸ� ��ο� �߰��ϴ� ��
		{
			int idx = path.find('/'); //�� ó�� ���������� �ε��� �˾Ƴ�
			string currentPath = path.substr(0, idx); //ó�� �����̸� �˾Ƴ�
			string subPath = path.substr(path.find('/')); //�� ������ �̸� ����
			subPath = subPath.substr(1, subPath.length()); // /������ ��

			for (auto data : current->children)
			{
				//�ȿ� �������̳� ���ϵ��� ����
				if (data->IsFile) //�����̸� �߰��ȵ�
				{
					cout << "�ش� ��δ� �����Դϴ�. ���Ͽ��� �߰��� �� �����ϴ�" << endl;
				}
				else //������� �߰�
				{
					if (data->name == currentPath) //�տ� ������ ������ �� ������ ��
					{
						insert_impl(data, subPath, IsFileCheck); //heejeong , directory
					}
					else //�ش� ��ο� ���� ������ 
					{
						continue;
					}
				}
			}
		}
	}

public:
//	void inorder()
//	{
//		inorder_impl(root);
//	}
//
//private:
//	void inorder_impl(node* start)
//	{
//		if (!start)
//			return;
//
//		inorder_impl(start->left);			// ���� ���� Ʈ�� �湮
//		std::cout << start->data << " ";	// ���� ��� ���
//		inorder_impl(start->right);			// ������ ���� Ʈ�� �湮
//	}
//
//public:
//	node* successor(node* start)
//	{
//		auto current = start->right;
//		while (current && current->left)
//			current = current->left;
//		return current;
//	}
//
//	void deleteValue(int value)
//	{
//		root = delete_impl(root, value);
//	}
//
//private:
//	node* delete_impl(node* start, int value)
//	{
//		if (!start)
//			return nullptr;
//
//		if (value < start->data)
//			start->left = delete_impl(start->left, value);
//		else if (value > start->data)
//			start->right = delete_impl(start->right, value);
//		else
//		{
//			if (!start->left) // �ڽ� ��尡 ���� ���ų�, ���� �ڽ� ��常 ���� ���
//			{
//				auto tmp = start->right;
//				delete start;
//				return tmp;
//			}
//
//			if (!start->right) // ������ �ڽ� ��常 ���� ���
//			{
//				auto tmp = start->left;
//				delete start;
//				return tmp;
//			}
//
//			// �ڽ� ��尡 �� �� �ִ� ���
//			auto succNode = successor(start);
//			start->data = succNode->data;
//
//			// ������ ���� Ʈ������ �İ���(successor)�� ã�� ����
//			start->right = delete_impl(start->right, succNode->data);
//		}
//
//		return start;
//	}
};

int main()
{
	bst tree;
	tree.insert("/", false);
	tree.insert("hee", false);
	tree.insert("jeong", false);
	tree.insert("jeong/ing", false);
	tree.findTree("jeong/ing"); //����
	tree.findTree("jeong/king"); //����
	tree.insert("jeong/imFile", true);
	tree.findTree("jeong/imFile"); //����
	tree.findTree("jeong/NoFile"); //����

	//std::cout << "���� ��ȸ: ";
	//tree.inorder(); // BST�� ��� ���Ҹ� ������������ ����մϴ�.
	//std::cout << std::endl;

	//tree.deleteValue(12);
	//std::cout << "12�� ������ �� ���� ��ȸ: ";
	//tree.inorder(); // BST�� ��� ���Ҹ� ������������ ����մϴ�.
	//std::cout << std::endl;

	//if (tree.find(12))
	//	std::cout << "���� 12�� Ʈ���� �ֽ��ϴ�." << std::endl;
	//else
	//	std::cout << "���� 12�� Ʈ���� �����ϴ�." << std::endl;
}
