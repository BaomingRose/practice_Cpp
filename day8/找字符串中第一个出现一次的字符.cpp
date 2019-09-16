#if 0
#include<iostream>
#include<string>
using namespace std;

int firstUniqueChar(const string& s) {
	int count[26] = { 0 };
	for (auto i : s) {
		++count[i - 'a'];
	}
	for (int i = 0; i < s.size(); ++i) {
		if (count[s[i] - 'a'] == 1) {
			return i;
		}
	}
	return -1;
}

int main() {
	string s1;
	while (cin >> s1) {
		cout << s1[firstUniqueChar(s1)] << endl;
	}

	return 0;
}
#endif