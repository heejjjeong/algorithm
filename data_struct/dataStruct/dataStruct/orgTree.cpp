#include <iostream>
#include <queue>

struct node
{
	std::string position; //��å
	node* first; //��������1
	node* second; //��������2
};

struct org_tree
{
	node* root;

	static org_tree create_org_structure(const std::string& pos)
	{
		org_tree tree;
		tree.root = new node{ pos, NULL, NULL };
		return tree;
	}

	//���� ������ ��带 ã�� �Լ�
	static node* find(node* root, const std::string& value)
	{
		if (root == NULL)
			return NULL;

		if (root->position == value)
			return root;

		auto firstFound = org_tree::find(root->first, value);

		if (firstFound != NULL)
			return firstFound;

		return org_tree::find(root->second, value);
	}

	//������ ��带 ã�Ƽ� �Ʒ��� �߰��ϴ� �Լ�
	bool addSubordinate(const std::string& manager, const std::string& subordinate)
	{
		auto managerNode = org_tree::find(root, manager);

		if (!managerNode)
		{
			std::cout << manager << "��(��) ã�� �� �����ϴ�: " << std::endl;
			return false;
		}

		if (managerNode->first && managerNode->second)
		{
			std::cout << manager << " �Ʒ��� " << subordinate << "�� �߰��� �� �����ϴ�." << std::endl;
			return false;
		}

		if (!managerNode->first)
			managerNode->first = new node{ subordinate, NULL, NULL };
		else
			managerNode->second = new node{ subordinate, NULL, NULL };

		std::cout << manager << " �Ʒ��� " << subordinate << "�� �߰��߽��ϴ�." << std::endl;

		return true;
	}

	static void preOrder(node* start)
	{
		if (!start)
			return;

		std::cout << start->position << ", ";
		preOrder(start->first);
		preOrder(start->second);
	}

	static void inOrder(node* start)
	{
		if (!start)
			return;

		inOrder(start->first);
		std::cout << start->position << ", ";
		inOrder(start->second);
	}

	static void postOrder(node* start)
	{
		if (!start)
			return;

		postOrder(start->first);
		postOrder(start->second);
		std::cout << start->position << ", ";
	}
};

int main()
{
	//root��� �ϳ� �����
	auto tree = org_tree::create_org_structure("CEO");

	//root �Ʒ��� ���� ä�� ���� ( ��Ʈ ��� �Ʒ��δ� ��� 2���ۿ� �߰� ���� ) 
	tree.addSubordinate("CEO", "�λ���");
	tree.addSubordinate("�λ���", "IT����");
	tree.addSubordinate("�λ���", "�����ú���");
	tree.addSubordinate("IT����", "��������");
	tree.addSubordinate("IT����", "�۰�������");
	tree.addSubordinate("�����ú���", "��������");
	tree.addSubordinate("�����ú���", "ȫ������");
	tree.addSubordinate("�λ���", "�繫����");
}
