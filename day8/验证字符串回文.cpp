#if 1
/*要求:不论大小写,也不包括标点空格等其他字符,只要是同字母即可*/
/*思想:先创建临时字符串,判断原字符串是否为数字、英文,是则尾插到临时字符串,在判断临时字符串是否回文*/

#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

bool isNumOrLetter(char c) {
	return  c >= '0' && c <= '9' ||
			c >= 'a' && c <= 'z' ||
			c >= 'A' && c <= 'Z';
}

bool isSame(char a, char b) {
	return a == b ||
		(a | 1 << 5) == (b | 1 << 5);	//精辟的写法
}

bool isPalindrome(const string& str) {
	if (str.empty()) {
		return true;
	}

	string tmp;
	for (auto i : str) {
		if (isNumOrLetter(i)) {
			tmp.push_back(i);
		}
	}
	
	int i = 0, j = tmp.size() - 1;
	while (i < j) {
		if (!isSame(tmp[i], tmp[j])) {
			return false;
		}
		++i, --j;
	}
	return true;
}

int main() {

	char s[3] = "ab";
	char (&rs)[3] = s;
	printf("%d\n", rs + 1);

#if 0

	string s1("A man, a plan, a canal : Panama");
	cout << isPalindrome(s1) << endl;

	string s2("dsfgdss");
	cout << isPalindrome(s2) << endl;

#endif
	return 0;
}
#endif