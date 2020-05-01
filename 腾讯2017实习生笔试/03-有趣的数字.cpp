/*================================================
 * description：
小Q今天在上厕所时想到了这个问题：有n个数，两两组成二元组，相差最小的有多少对呢？相差最大呢？
=================================================*/
//先sort排序一下，如果有重复的，那么最小肯定是重复的，看有多少组。
//最大肯定是最大值的个数*最小值的个数
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int *a = new int[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		sort(a, a + n);

		int min = a[n - 1] - a[0];
		int max = a[n - 1] - a[0];
		int min_count = 0;
		int max_count = 0;

		//找到最小差值
		for (int i = 1; i < n; i++)
			if (min > a[i] - a[i - 1])
				min = a[i] - a[i - 1];

		//如果数组全都相等
		if (a[0] == a[n - 1]) {
			max_count = n * (n - 1) / 2;
		} else {
			int first = 0;
			int last = 0;
			//统计最大值和最小值的个数
			for (int i = 0; i < n; i++) {
				if (a[i] == a[0])
					first++;
				if (a[i] == a[n - 1])
					last++;
			}
			max_count = first * last;
		}

		//如果最小值为0，有相等的值存在
		if (min == 0) {
			//从左向右查找与值相等的（怎么没有想到，一直想使用组合公式了，※※※）
			for (int i = 0; i < n; i++) {
				int j = i + 1;
				while (j < n) {
					if (a[i] == a[j])
						min_count++;
					j++;
				}
			}
		} else {
			for (int i = 1; i < n; i++)
				if (min == a[i] - a[i - 1])
					min_count++;
		}

		cout << min_count << " " << max_count << endl;

	}
}