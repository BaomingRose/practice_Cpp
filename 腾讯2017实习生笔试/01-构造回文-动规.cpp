/*================================================
 * description��
����һ���ַ���s������Դ���ɾ��һЩ�ַ���ʹ��ʣ�µĴ���һ�����Ĵ������ɾ������ʹ�û��Ĵ���أ�
�����Ҫɾ�����ַ�������

//����s�ķ���reverse��Ȼ�������ǵ���Ĺ��������У�Ҫɾ�����ַ���������֪��
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
	//��������������
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