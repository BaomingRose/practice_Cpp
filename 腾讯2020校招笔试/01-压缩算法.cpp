/*================================================
 * description：
小Q想要给他的朋友发送一个神秘字符串，但是他发现字符串的过于长了，
于是小Q发明了一种压缩算法对字符串中重复的部分进行了压缩，
对于字符串中连续的m个相同字符串S将会压缩为[m | S](m为一个整数且1 <= m <= 100)，
例如字符串ABCABCABC将会被压缩为[3 | ABC]，现在小Q的同学收到了小Q发送过来的字符串，你能帮助他进行解压缩么？
HG[3|B[2|CA]]F−>HG[3|BCACA]F−>HGBCACABCACABCACAF
=================================================*/
#if 0
//源代码思路参考某大神
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int i = 0;
	while (i < s.length()) {
		if (s[i] == ']') {
			int j = i;//j用来向前寻找与]相匹配的[
			int k = 0;//k用来记录'|'所在位置
			while (s[j] != '[') {
				if (s[j] == '|')
					k = j;
				j--;
			}
			int len = stoi(s.substr(j + 1, k - j));
			string s1 = s.substr(k + 1, i - k - 1);
			string s2;
			for (int si = 0; si < len; si++) {//将识别到的括号内容进行解码
				s2 += s1;
			}
			s = s.replace(j, i - j + 1, s2);
			i = j;//替换后i所指向的内容变化，从替换部分的头开始再寻找
		}
		i++;
	}
	cout << s << endl;
}
#endif

#if 0
#include <stdio.h>
#include <string>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int end1 = 0;
string s2(string s) {
	stack<char> st;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '[') {
			st.push(s[i]);
		} else if (s[i] == ']') {
			char tmpc = st.top();
			string tmp;
			while (tmpc >= 'A' && tmpc <= 'Z') {
				tmp = tmpc + tmp;
				st.pop();
				tmpc = st.top();
			}
			if (!st.empty()) {//delete '|'
				st.pop();
			}
			int n = 0;
			int cntn = 1;
			while (st.top() >= '0' && st.top() <= '9') {
				n = n + (st.top() - '0')*cntn;
				st.pop();
				cntn *= 10;
			}
			string to_store;
			while (n > 0) {
				to_store += tmp;
				n--;
			}
			if (!st.empty()) {//delete '['
				st.pop();
			}
			for (char tmpc : to_store) {
				st.push(tmpc);
			}
		} else {
			st.push(s[i]);
		}
	}
	string res;
	while (!st.empty()) {
		res = st.top() + res;
		st.pop();
	}
	return res;
}

int main() {
	string str;
	cin >> str;
	string res = s2(str);
	cout << res << endl;
	return 0;
}
#endif


#if 1
#include<string>
#include<regex>
#include<iostream>
#include<vector>
using namespace std;

int main() {
	string line;
	getline(cin, line);
	//暂时推断：smatch的数组个数由小括号数决定
	//     \\是什么作用？
	string str = "\\[(\\d+)\\|(\\w+)\\]";
	//string str = "\\[";

	regex pattern(str);
	smatch sma;

	//regex_search   搜索,将结果保存到spattern
	while (regex_search(line, sma, pattern)) {
		vector<string> cur;

		//auto iter 遍历spattern,依次插入vector
		for (auto iter = sma.begin(); iter != sma.end(); iter++) {
			cur.push_back(iter->str());
		}

		//调式
		for (int i = 0; i < cur.size(); ++i) {
			cout << cur[i] << endl;
		}

		int num = atoi(cur[1].c_str());
		string chs = "";		//解压的文字
		for (int i = 0; i < num; i++) {
			chs += cur[2];
		}

		int len = cur[0].length();	//匹配字串的长度
		int pos = sma.position();	//匹配字串在原字串中的起始位置

		//string::replace	用新内容替换以字符pos开头并跨越len个字符的字符串部分（或[i1，i2）(迭代器)范围内的字符串部分）
		//（size_t pos，size_t len，const string＆str）;
		//（const_iterator i1，const_iterator i2，const string＆str）;
		//size_t pos，size_t len，size_t n，char c）;	//放n个char
		//（const_iterator i1，const_iterator i2，size_t n，char c）;
		line.replace(pos, len, chs);
	}

	cout << line << endl;

	return 0;
}
#endif
