#if 0
//问题：房子n个长廊，构成一个环形，从1开始到n，n下来是1，如果某人具有能量值，想留下痕迹需要能量，如果到了该房间，接下来一定到下一个房间
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;	//n表示几个长廊
	unsigned long long m;	//m表示某人的能量
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
			//考试的时候因少了等号浪费时间
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