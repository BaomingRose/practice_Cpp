#if 0
#include<iostream>
#include<string>
using namespace std;

void swap(char& a, char& b) {
	char tmp = a;
	a = b;
	b = tmp;
}

void partReverse(string& str, int begin, int end) {
	if (begin >= end) {
		return;
	}
	while (begin < end) {
		swap(str[begin], str[end]);
		++begin, --end;
	}
}

int main() {
	string s;
	int head, tail;
	while (cin >> s) {
		cin >> head >> tail;
		partReverse(s, head, tail);
		cout << s << endl;
	}

	return 0;
}
#endif