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
* 디렉터리 이동
* 파일, 디렉터리 검색
* 파일, 디렉터리 추가
* 파일, 디렉터리 목록 출력
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
			std::cout << str << "을(를) 찾았습니다." << std::endl;
			return current;
		}

		if (str < current->data) // value 값이 현재 노드 왼쪽에 있는 경우
		{
			std::cout << current->data << "에서 왼쪽으로 이동: ";
			return find_impl(current->left, value);
		}

		// value 값이 현재 노드 오른쪽에 있는 경우
		std::cout << current->data << "에서 오른쪽으로 이동: ";
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
		* 경로에 / 어쩌구 있으면 해당 경로로 넣어주고.. 아니면 바로 루트에 넣어버리기
		*/

		if (string::npos == path.find('/')) // /가 없다면 그냥 루트에 추가하는 것
		{
			if (IsFileCheck) //추가하는 것이 파일이라면
			{
				nTree* file = new nTree{ path, IsFileCheck, vector<nTree*>(0) };
				current->children.emplace_back(file);
			}
			else //디렉토리라면
			{
				nTree* directory = new nTree{ path, IsFileCheck, vector<nTree*>() };
				current->children.emplace_back(directory);
				CurrentDirectory = current->children.back(); //제일 마지막에 넣어준 폴더로 CurrentDirectory 변갱
			}
		}
		else //다른 경로에 추가하는 것
		{
			int idx = path.find('/'); //맨 처음 폴더까지의 인덱스 알아냄
			string currentPath = path.substr(0, idx); //처음 폴더이름 알아냄
			string subPath = path.substr(path.find('/')); //뒷 폴더들 이름 저장
			subPath = subPath.substr(1, subPath.length()); // /제거한 자

			for (auto data : current->children)
			{
				//안에 폴더들이나 파일들이 있음
				if (data->IsFile) //파일이면 추가안됨
				{
					cout << "해당 경로는 파일입니다. 파일에는 추가할 수 없습니다" << endl;
				}
				else //폴더라면 추가
				{
					if (data->name == currentPath) //앞에 폴더가 있으면 그 안으로 들어감
					{
						insert_impl(data, subPath, IsFileCheck); //heejeong , directory
					}
					else //해당 경로에 폴더 없으면 
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
//		inorder_impl(start->left);			// 왼쪽 하위 트리 방문
//		std::cout << start->data << " ";	// 현재 노드 출력
//		inorder_impl(start->right);			// 오른쪽 하위 트리 방문
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
//			if (!start->left) // 자식 노드가 전혀 없거나, 왼쪽 자식 노드만 없는 경우
//			{
//				auto tmp = start->right;
//				delete start;
//				return tmp;
//			}
//
//			if (!start->right) // 오른쪽 자식 노드만 없는 경우
//			{
//				auto tmp = start->left;
//				delete start;
//				return tmp;
//			}
//
//			// 자식 노드가 둘 다 있는 경우
//			auto succNode = successor(start);
//			start->data = succNode->data;
//
//			// 오른쪽 하위 트리에서 후계자(successor)를 찾아 삭제
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
	tree.findTree("jeong/ing"); //있음
	tree.findTree("jeong/king"); //없음
	tree.insert("jeong/imFile", true);
	tree.findTree("jeong/imFile"); //있음
	tree.findTree("jeong/NoFile"); //없음

	//std::cout << "중위 순회: ";
	//tree.inorder(); // BST의 모든 원소를 오름차순으로 출력합니다.
	//std::cout << std::endl;

	//tree.deleteValue(12);
	//std::cout << "12를 삭제한 후 중위 순회: ";
	//tree.inorder(); // BST의 모든 원소를 오름차순으로 출력합니다.
	//std::cout << std::endl;

	//if (tree.find(12))
	//	std::cout << "원소 12는 트리에 있습니다." << std::endl;
	//else
	//	std::cout << "원소 12는 트리에 없습니다." << std::endl;
}
