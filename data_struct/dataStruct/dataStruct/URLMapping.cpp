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
			//ShortURL에 등록된게 있으니까.. 실패
			return false;
		}
	}

	string lookUp(const string& InShortURL)
	{
		cout << InShortURL << " 검색" << endl;
		//원본URL반환하는 검색함수
		if (url.find(InShortURL) == url.end())
			return "찾는 url 없음";

		return "기존 URL : " + url.find(InShortURL)->second;
	}
};

int main()
{
	URL tinyurl;
	if (tinyurl.insert("www.heejeong.co.kr", "heejeong.co.kr"))
	{
		//넣은게 true라면
		cout << "url삽입성공" << endl;
	}
	else
	{
		cout << "url삽입실패" << endl;
	}

	auto temp = tinyurl.lookUp("heejeong.co.kr");
	cout << temp << endl;
	return 0;
}