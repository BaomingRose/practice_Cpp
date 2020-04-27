/*================================================
 * description：
 小Q定义了一种数列称为翻转数列:
给定整数n和m, 满足n能被2m整除。对于一串连续递增整数数列1, 2, 3, 4..., 每隔m个符号翻转一次, 最初符号为'-';。
例如n = 8, m = 2, 数列就是: -1, -2, +3, +4, -5, -6, +7, +8.
而n = 4, m = 1, 数列就是: -1, +2, -3, + 4.
小Q现在希望你能帮他算算前n项和为多少。
=================================================*/
#if 0
//我的方法：已经正确，但是没有公式法更好
#include <iostream>
using namespace std;

int main() {
	int n, m;
	while (cin >> n >> m) {
		long long sum = 0;
		long long tmp = 0;
		int flag = -1;
		for (int i = 1; i <= n; ++i) {
			sum += (flag * i);
			++tmp;
			if (tmp == m) {
				tmp = 0;
				flag *= -1;
			}
		}
		cout << sum << endl;
	}

	return 0;
}
#endif

#if 0
//公式法
/*首先观察数列，我们可以将一组负正的数出现（如 - 1， - 2, 3, 4）看做一组，则n个数一共有n / (2m)组，而每一组求和结果为m*m，
于是得到前n项和公式为Sn = n * m*m / 2m = m * n / 2*/
#include<iostream>
using namespace std;
typedef long long LL;

int main() {
	LL n, m;
	cin >> n >> m;
	cout << n * m / 2 << endl;
}
#endif