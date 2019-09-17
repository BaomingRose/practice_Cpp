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
string& reverseWords(string& s) {
	int pos = 0;
	int tmp;
	while (1) {
		tmp = pos;
		pos = s.find(' ', tmp);
		if (pos == -1) {
			partReverse(s, tmp, s.size() - 1);
			break;
		}
		partReverse(s, tmp, pos - 1);
		pos += 1;
	}
	return s;
}

int main() {
	string s;
	while (getline(cin, s)) {
		cout << reverseWords(s) << endl;
	}

	return 0;
}