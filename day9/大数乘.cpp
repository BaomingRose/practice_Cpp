#if 0
#include<iostream>
#include<string>
#include<algorithm>
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

string Multi(string m, string n) {
	if (m == "0" || n == "0") {
		return "0";
	}
	reverseString(m);
	reverseString(n);
	string res;
	int len = m.length() + n.length();
	res.reserve(len);
	m.resize(len, '0');
	n.resize(len, '0');
	int sum = 0, lastSum = 0;
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j <= i; ++j) {
			sum += (m[j]  - '0') * (n[i - j] - '0');
		}
		sum += lastSum / 10;
		if (i == len - 1 && !sum) {
			break;
		}
		lastSum = sum;
		res.push_back(sum % 10 + '0');
		sum = 0;
	}
	reverseString(res);
	return res;	
}

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		cout << Multi(s1, s2) << endl;
	}
	return 0;
}
#endif