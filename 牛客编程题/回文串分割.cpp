/*================================================
 * description：
给出一个字符串s，分割s使得分割出的每一个子串都是回文串
计算将字符串s分割成回文分割结果的最小切割数
例如:给定字符串s="aab",
返回1，因为回文分割结果["aa","b"]是切割一次生成的。
=================================================*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#if 0
//判断是否回文串
bool isPalindrome(string s, int i, int j) {
	while (i < j) {
		if (s[i] != s[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int minCut(string s) {
	if (s.empty()) return 0;
	int len = s.size();
	vector<int> cut;
	// F(i)初始化
	// F(0）= -1，必要项，如果没有这一项，对于重叠字符串“aaaaa”会产生错误的结果
	for (int i = 0; i < 1 + len; ++i) {
		cut.push_back(i - 1);
	}
	for (int i = 1; i < 1 + len; ++i) {
		for (int j = 0; j < i; ++j) {
			// F(i) = min{F(i), 1 + F(j)}, where j<i && j+1到i是回文串
			// 从最长串判断，如果从第j+1到i为回文字符串
			// 则再加一次分割，从1到j，j+1到i的字符就全部分成了回文字符串
			if (isPalindrome(s, j, i - 1)) {
				cut[i] = min(cut[i], 1 + cut[j]);
			}
		}
	}
	return cut[len];
}
#endif

//用动规的方式判断字符串的子串是否回文
vector<vector<bool>> getMat(string s) {
	int len = s.size();
	vector<vector<bool>> mat(len, vector<bool>(len, false));

	for (int i = len - 1; i >= 0; --i) {
		for (int j = i; j < len; ++j) {
			if (j == i) 
				// 单字符为回文字符串
				mat[i][j] = true;
			else if (j == i + 1) 
				// 相邻字符如果相同，则为回文字符串
				mat[i][j] = (s[i] == s[j]);
			else 
				// F(i,j) = {s[i]==s[j] && F(i+1,j-1)
				// j > i+1
				mat[i][j] = ((s[i] == s[j]) && mat[i + 1][j - 1]);
		}
	}
	return mat;
}

int minCut(string s) {
	if (s.empty()) return 0;

	int len = s.size();
	vector<int> cut;

	// F(i)初始化
	// F(0）= -1，必要项，如果没有这一项，对于重叠字符串“aaaaa”会产生错误的结果
	for (int i = 0; i < 1 + len; ++i) {
		cut.push_back(i - 1);
	}

	vector<vector<bool>> mat = getMat(s);

	for (int i = 1; i < 1 + len; ++i) {
		for (int j = 0; j < i; ++j) {
			// F(i) = min{F(i), 1 + F(j)}, where j<i && j+1到i是回文串
			// 从最长串判断，如果从第j+1到i为回文字符串
			// 则再加一次分割，从1到j，j+1到i的字符就全部分成了回文字符串
			if (mat[j][i - 1]) 
				cut[i] = min(cut[i], 1 + cut[j]);
		}
	}
	return cut[len];
}
