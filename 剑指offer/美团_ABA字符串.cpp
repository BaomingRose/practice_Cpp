#include <iostream>
#include <string>
using namespace std;

//�ж��ַ����ǲ��� ABA ��ʽ���ַ�����A��B��Ϊ�ַ���
bool isABA(const string& str) {
	size_t len = str.size();
	for (int i = 1; i <= len / 2; ++i) {
		//���ż�����ȣ����ܵ�len/2
		if (((len & 1) == 0) && i == len / 2) {
			return false;
		}
		string s_left = str.substr(0, i);
		string s_right = str.substr(len - i, i);
		if (s_left == s_right) {
			return true;
		}
	}
	return false;
}

int main() {
	string s("abcdefgsgfgsgfsgabcdef");
	string s2("aba");
	string s3("a");
	string s4("aa");
	string s5("abba");

	if (isABA(s)) {
		cout << "s is ABAstr" << endl;
	}
	if (isABA(s2)) {
		cout << "s2 is ABAstr" << endl;
	}
	if (isABA(s3)) {
		cout << "s3 is ABAstr" << endl;
	}
	if (isABA(s4)) {
		cout << "s4 is ABAstr" << endl;
	}
	if (isABA(s5)) {
		cout << "s5 is ABAstr" << endl;
	}

	return 0;
}