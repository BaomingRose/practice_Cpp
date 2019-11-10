//将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数后变为：beijing. like I

/*解题思路1：
先将整个字符串逆置过来，再遍历字符串，找出每个单词，对单词逆置。这里我们使用了stl算法中的
reverse，所以这里使用迭代器遍历string*/

#if 0
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	string s;
	// 注意这里要使用getline，cin>>s遇到空格就接收结束了
	getline(cin, s);
	// 翻转整个句子
	reverse(s.begin(), s.end());
	// 翻转单词
	string::iterator start = s.begin();
	while (start != s.end())
	{
		string::iterator end = start;
		while (end != s.end() && *end != ' ')
			end++;
		reverse(start, end);
		if (end != s.end())
			start = end + 1;
		else
			start = end;
	}
	cout << s << endl;
	return 0;
}
#endif

/*第二思路是一个比较讨巧的思路，直接利用cin>>s接收输入，遇到空格就结束了，自然就分割开了每个单词，
其次将每次接收到的单词拼接到之前串的前面就逆置过来了*/

#include <iostream>
#include <string>
using namespace std;
// cin读取string时自动会被空格分隔开，用另一个字符串存储进行逆序输出
int main() {
	string s1, s2;
	cin >> s2;
	while (cin >> s1)
		s2 = s1 + " " + s2;
	cout << s2 << endl;
	return 0;
}
