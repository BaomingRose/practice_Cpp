#if 0
#include<iostream>
#include<string>
using namespace std;

void swap(char& a, char& b) {
	char tmp = a;
	a = b;
	b = tmp;
}

void reverseString(string& str) {
	int start = 0, end = str.size() - 1;
	while (start < end) {
		swap(str[start], str[end]);
		++start, --end;
	}
}

string Add(string a, string b) {
	reverseString(a);
	reverseString(b);
	string res;
	int len;

	len = a.length() < b.length() ? b.length() : a.length();
	a.resize(len + 1, '0');
	b.resize(len + 1, '0');
	res.reserve(len + 1);
	res.push_back(((a[0] - '0' + b[0] - '0') % 10) + '0');
	char c;
	for (int i = 0; i < len; ++i) {
		c = (a[i + 1] - '0' + b[i + 1] - '0' + (a[i] - '0' + b[i] - '0') / 10) % 10 + '0';
		if (i == len - 1 && c == '0') {
			break;
		}
		res.push_back(c);
	}

	reverseString(res);
	return res;

}

int main() {
	string a, b;
	while (cin >> a >> b) {
		cout << Add(a, b) << endl;
	}
	return 0;
}
#endif