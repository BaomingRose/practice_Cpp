#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void show(vector<string>& v,vector<size_t>& pre, int x) {
	//��������һ���ˣ����ӡ����
	if (pre[x] == x) {
		cout << v[x];
		return;
	}
	show(v, pre, pre[x]);
	cout << v[x];
}

size_t riseString(vector<string>& v) {
	//��¼��ǰ�ַ����������
	vector<size_t> len(v.size(), 0);
	//��¼������һ�����ĺ���
	vector<size_t> pre(v.size(), 0);
	for (size_t i = 0; i < v.size(); ++i) {
		len[0] = v[0].size();
		//��ǰ���ַ����Ľ����Լ��ĺ���
		pre[i] = i;
		for (size_t j = 0; j < i; ++j) {
			if (len[i] < len[j] + v[i].size() && v[i][0] >= v[j][v[j].size() - 1]) {
				len[i] = len[j] + v[i].size();
				pre[i] = j;
			}
		}
	}
	int k;
	size_t res = 0;
	for (int i = 0; i < len.size(); ++i) {
		if (len[i] > res) {
			res = len[i];
			k = i;
		}
	}
	show(v, pre, k);
	cout << endl;
	return res;
}

int main() {
	int n;
	cin >> n;
	char ch = getchar();
	vector<string> v;
	for (int i = 0; i < n; ++i) {
		string s;
		getline(cin, s);
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	cout << riseString(v) << endl;

	//cout << strlen("aaabcdfghijklmnopqrstzzz") << endl;

	return 0;
}
