/*================================================
 * description：
小Q的父母要出差N天，走之前给小Q留下了M块巧克力。小Q决定每天吃的巧克力数量不少于前一天吃的一半，
但是他又不想在父母回来之前的某一天没有巧克力吃，请问他第一天最多能吃多少块巧克力
=================================================*/
#if 0
//我的答案：因为顺序查找效率低，只过了80%，将顺序查找改成二分查找提高效率即可
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
//使用二分查找
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