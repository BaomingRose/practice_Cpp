/*================================================
 * description：
给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
输出需要删除的字符个数。

//先求s的反串reverse，然后求他们的最长的公共子序列，要删除的字符个数就能知道
=================================================*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getDelNum(const string& s) {
	string rever = s;
	reverse(rever.begin(), rever.end());

	int len = s.size();
	vector<vector<int>> vv(len + 1, vector<int>(len + 1, 0));
	//填表：最长公共子序列
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			if (s[i] == rever[j]) {
				vv[i + 1][j + 1] = vv[i][j] + 1;
			} else {
				vv[i + 1][j + 1] = max(vv[i + 1][j], vv[i][j + 1]);
			}
		}
	}

	return len - vv[len][len];
}

int main() {
	string s;
	while (cin >> s) {
		cout << getDelNum(s) << endl;
	}

	return 0;
}