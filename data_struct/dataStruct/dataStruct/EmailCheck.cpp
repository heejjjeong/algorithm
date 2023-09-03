#include <iostream>
#include <vector>

#include <Windows.h>
#include <wincrypt.h>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

string CalculateMD5Hash(const string& input) {
	HCRYPTPROV hProv = NULL;
	HCRYPTHASH hHash = NULL;

	if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT)) {
		return "";
	}

	if (!CryptCreateHash(hProv, CALG_MD5, 0, 0, &hHash)) {
		CryptReleaseContext(hProv, 0);
		return "";
	}

	if (!CryptHashData(hHash, reinterpret_cast<const BYTE*>(input.c_str()), input.size(), 0)) {
		CryptDestroyHash(hHash);
		CryptReleaseContext(hProv, 0);
		return "";
	}

	DWORD dwHashSize = 16;  // MD5 hash size
	BYTE hash[16];

	if (!CryptGetHashParam(hHash, HP_HASHVAL, hash, &dwHashSize, 0)) {
		CryptDestroyHash(hHash);
		CryptReleaseContext(hProv, 0);
		return "";
	}

	CryptDestroyHash(hHash);
	CryptReleaseContext(hProv, 0);

	stringstream ss;
	ss << hex << setfill('0');
	for (int i = 0; i < dwHashSize; ++i) {
		ss << std::setw(2) << static_cast<unsigned>(hash[i]);
	}

	return ss.str();
}

class bloom_filter
{
	vector<bool> data;
	int nBits;
	int hashNum;

public:
	bloom_filter(int n, int size) : nBits(n), hashNum(size)
	{
		//��������� �����...?�־�..?
		data = vector<bool>(nBits, false);
	}

	void insertEmail(string key)
	{
		auto temp = CalculateMD5Hash(key);

		for (auto a : temp)
		{
			data[a] = true;
		}

		cout << " �̸��� �߰� �Ϸ�" << endl;
	}

	void lookUp(string key)
	{
		//���ִٰ��ñ�...
		auto temp = CalculateMD5Hash(key);
		
		for (auto a : temp)
		{
			if (data[a] == false)
			{
				cout << "�ش� �̸��� ����" << endl;
				return;
			}
		}

		cout << "�ش� �̸��� ����" << endl;
	}
};

int main()
{
	bloom_filter bf(128, 1);

	bf.insertEmail("heejeong");
	bf.insertEmail("hyodoll");
	bf.insertEmail("heejeong");

	//���ڲ� ���µ� �ִٴ°ɱ�,,���������ɱ�..?
	bf.lookUp("hyeongsoon");

	return 0;
}