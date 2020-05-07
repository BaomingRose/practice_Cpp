/*================================================
 * description��
����һ���ַ���s���ָ�sʹ�÷ָ����ÿһ���Ӵ����ǻ��Ĵ�
���㽫�ַ���s�ָ�ɻ��ķָ�������С�и���
����:�����ַ���s="aab",
����1����Ϊ���ķָ���["aa","b"]���и�һ�����ɵġ�
=================================================*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#if 0
//�ж��Ƿ���Ĵ�
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
	// F(i)��ʼ��
	// F(0��= -1����Ҫ����û����һ������ص��ַ�����aaaaa�����������Ľ��
	for (int i = 0; i < 1 + len; ++i) {
		cut.push_back(i - 1);
	}
	for (int i = 1; i < 1 + len; ++i) {
		for (int j = 0; j < i; ++j) {
			// F(i) = min{F(i), 1 + F(j)}, where j<i && j+1��i�ǻ��Ĵ�
			// ������жϣ�����ӵ�j+1��iΪ�����ַ���
			// ���ټ�һ�ηָ��1��j��j+1��i���ַ���ȫ���ֳ��˻����ַ���
			if (isPalindrome(s, j, i - 1)) {
				cut[i] = min(cut[i], 1 + cut[j]);
			}
		}
	}
	return cut[len];
}
#endif

//�ö���ķ�ʽ�ж��ַ������Ӵ��Ƿ����
vector<vector<bool>> getMat(string s) {
	int len = s.size();
	vector<vector<bool>> mat(len, vector<bool>(len, false));

	for (int i = len - 1; i >= 0; --i) {
		for (int j = i; j < len; ++j) {
			if (j == i) 
				// ���ַ�Ϊ�����ַ���
				mat[i][j] = true;
			else if (j == i + 1) 
				// �����ַ������ͬ����Ϊ�����ַ���
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

	// F(i)��ʼ��
	// F(0��= -1����Ҫ����û����һ������ص��ַ�����aaaaa�����������Ľ��
	for (int i = 0; i < 1 + len; ++i) {
		cut.push_back(i - 1);
	}

	vector<vector<bool>> mat = getMat(s);

	for (int i = 1; i < 1 + len; ++i) {
		for (int j = 0; j < i; ++j) {
			// F(i) = min{F(i), 1 + F(j)}, where j<i && j+1��i�ǻ��Ĵ�
			// ������жϣ�����ӵ�j+1��iΪ�����ַ���
			// ���ټ�һ�ηָ��1��j��j+1��i���ַ���ȫ���ֳ��˻����ַ���
			if (mat[j][i - 1]) 
				cut[i] = min(cut[i], 1 + cut[j]);
		}
	}
	return cut[len];
}
