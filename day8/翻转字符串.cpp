#if 0
#include<iostream>
#include<string>
using namespace std;

void swap(char& a, char& b) {
	char tmp = a;
	a = b;
	b = tmp;
}

string& reverseString(string & str) {
	if (str.empty()) {
		return str;
	}
	int i = 0, j = str.size() - 1;
	for (; i < j; ++i, --j) {
		swap(str[i], str[j]);
	}
	return str;
}

int main() {
	string s1;
	getline(cin, s1);
	cout << reverseString(s1) << endl;

	char s2[100];
	//接收一行
	cin.getline(s2, 100);
	cout << s2 << endl;

	return 0;
}
#endif