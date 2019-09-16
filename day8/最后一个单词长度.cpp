#if 0
#include<iostream>
#include<string>
using namespace std;

int lastWordLen(const string& str) {
	int posSpace = str.rfind(' ');
	return str.size() - 1 - posSpace;
}

int main() {
	string s;
	while (getline(cin, s)) {
		cout << lastWordLen(s) << endl;
	}

	return 0;
}
#endif