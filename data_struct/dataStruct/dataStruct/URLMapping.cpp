#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
class URL
{
	unordered_map<string, string> url;

public:
	bool insert(const string& LongURL, const string& ShortURL)
	{
		if (url.find(ShortURL) == url.end())
		{
			url[ShortURL] = LongURL;
			cout << LongURL << " ";
			return true;
		}
		else
		{
			//ShortURL�� ��ϵȰ� �����ϱ�.. ����
			return false;
		}
	}

	string lookUp(const string& InShortURL)
	{
		cout << InShortURL << " �˻�" << endl;
		//����URL��ȯ�ϴ� �˻��Լ�
		if (url.find(InShortURL) == url.end())
			return "ã�� url ����";

		return "���� URL : " + url.find(InShortURL)->second;
	}
};

int main()
{
	URL tinyurl;
	if (tinyurl.insert("www.heejeong.co.kr", "heejeong.co.kr"))
	{
		//������ true���
		cout << "url���Լ���" << endl;
	}
	else
	{
		cout << "url���Խ���" << endl;
	}

	auto temp = tinyurl.lookUp("heejeong.co.kr");
	cout << temp << endl;
	return 0;
}