/*================================================
 * description��
СQ�ĸ�ĸҪ����N�죬��֮ǰ��СQ������M���ɿ�����СQ����ÿ��Ե��ɿ�������������ǰһ��Ե�һ�룬
�������ֲ����ڸ�ĸ����֮ǰ��ĳһ��û���ɿ����ԣ���������һ������ܳԶ��ٿ��ɿ���
=================================================*/
#if 0
//�ҵĴ𰸣���Ϊ˳�����Ч�ʵͣ�ֻ����80%����˳����Ҹĳɶ��ֲ������Ч�ʼ���
#include <iostream>
#include <cmath>
using namespace std;

int sumNDay(int i, int n) {
	int sum = 0;
	for (int j = 1; j <= n; ++j) {
		sum += i;
		i = ceil(i * 1.0 / 2);
	}
	return sum;
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		int i;
		for (i = 0; sumNDay(i, n) <= m; ++i);
		cout << i - 1 << endl;
	}

	return 0;
}
#endif

#if 0
//ʹ�ö��ֲ���
#include<iostream>
using namespace std;

int eatsum(int mid, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + mid;
		mid = (mid + 1) / 2;
	}
	return sum;
}

int eatmax(int n, int m) {
	if (n == 1) 
		return m;
	int low = 1;
	int high = m;
	int sum = 0;
	while (low < high) {
		int mid = (low + high + 1) / 2;
		sum = eatsum(mid, n);
		if (sum == m) {
			return mid;
		} else if (sum < m) {
			low = mid;
		} else {
			high = mid - 1;
		}
	}
	return high;
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		int res = eatmax(n, m);
		cout << res << endl;
		return 0;
	}
}
#endif