#if 0
//���⣺����n�����ȣ�����һ�����Σ���1��ʼ��n��n������1�����ĳ�˾�������ֵ�������ºۼ���Ҫ������������˸÷��䣬������һ������һ������
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;	//n��ʾ��������
	unsigned long long m;	//m��ʾĳ�˵�����
	while (cin >> n >> m) {
		unsigned long long count = 0;
		vector<unsigned long long> v(n);
		unsigned long long min = 0xffffffffffffffff;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			if (v[i] < min) {
				min = v[i];
			}
		}

		int i = 0;
		while (m >= min) {
			//���Ե�ʱ�������˵Ⱥ��˷�ʱ��
			if (m >= v[i % n]) {
				m -= v[i % n];
				++count;
			}
			++i;
		}

		cout << count << endl;

	}

	return 0;
}
#endif