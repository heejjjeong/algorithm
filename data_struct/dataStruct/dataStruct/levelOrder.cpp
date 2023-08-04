#include <iostream>
#include <queue>

struct node
{
	std::string position; //직책
	node* first; //부하직원1
	node* second; //부하직원2
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

	//나의 관리자 노드를 찾는 함수
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

	//관리자 노드를 찾아서 아래에 추가하는 함수
	bool addSubordinate(const std::string& manager, const std::string& subordinate)
	{
		auto managerNode = org_tree::find(root, manager);

		if (!managerNode)
		{
			std::cout << manager << "을(를) 찾을 수 없습니다: " << std::endl;
			return false;
		}

		if (managerNode->first && managerNode->second)
		{
			std::cout << manager << " 아래에 " << subordinate << "를 추가할 수 없습니다." << std::endl;
			return false;
		}

		if (!managerNode->first)
			managerNode->first = new node{ subordinate, NULL, NULL };
		else
			managerNode->second = new node{ subordinate, NULL, NULL };

		std::cout << manager << " 아래에 " << subordinate << "를 추가했습니다." << std::endl;

		return true;
	}

	static void levelOrder(node* start)
	{
		if (!start)
			return;

		std::queue<node*> q;
		q.push(start);

		while (!q.empty())
		{
			int size = q.size();
			for (int i = 0; i < size; i++)
			{
				auto current = q.front();
				q.pop();

				std::cout << current->position << ", ";
				if (current->first)
					q.push(current->first);
				if (current->second)
					q.push(current->second);
			}

			std::cout << std::endl;
		}
	}
};

int main()
{
	//root노드 하나 만들고
	auto tree = org_tree::create_org_structure("CEO");

	//root 아래로 노드들 채워 넣음 ( 루트 노드 아래로는 노드 2개밖에 추가 못함 ) 
	tree.addSubordinate("CEO", "부사장");
	tree.addSubordinate("부사장", "IT부장");
	tree.addSubordinate("부사장", "마케팅부장");
	tree.addSubordinate("IT부장", "보안팀장");
	tree.addSubordinate("IT부장", "앱개발팀장");
	tree.addSubordinate("마케팅부장", "물류팀장");
	tree.addSubordinate("마케팅부장", "홍보팀장");
	tree.addSubordinate("부사장", "재무부장");

	org_tree::levelOrder(tree.root);
}
