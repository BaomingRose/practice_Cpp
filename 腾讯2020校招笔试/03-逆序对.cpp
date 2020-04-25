/*================================================
 * description：
 作为程序员的小Q，他的数列和其他人的不太一样，他有个数。
老板问了小Q一共 m次，每次给出一个整数, 要求小Q把这些数每分为一组，然后把每组进行翻转，小Q想知道每次操作后整个序列中的逆序对个数是多少呢？
例如:
对于序列1 3 4 2，逆序对有(4, 2),(3, 2),总数量为2。
翻转之后为2 4 3 1，逆序对有(2, 1),(4, 3), (4, 1), (3, 1),总数量为4。
输入例子1:
2
2 1 4 3
4
1 2 0 2

输出例子1:
0
6
6
0
例子说明1:
初始序列2 1 4 3
2^{q_1} = 2 ->
第一次：1 2 3 4 -> 逆序对数为0
2^{q_2} = 4 ->
第二次：4 3 2 1 -> 逆序对数为6
2^{q_3} = 1 ->
第三次：4 3 2 1 -> 逆序对数为6
2^{q_4} = 4 ->
第四次：1 2 3 4 -> 逆序对数为0
=================================================*/
#if 0	
//我的答案：复杂
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numOfReverse(const vector<int>& v) {
	int res = 0;
	for (int i = 0; i < v.size(); ++i) {
		for (int j = i + 1; j < v.size(); ++j) {
			if (v[j] < v[i]) {
				++res;
			}
		}
	}
	return res;
}

void Reverse(vector<int>& v, int num) {
	auto ib = v.begin();
	auto ie = v.end();
	while (ib <= ie - num) {
		reverse(ib, ib + num);
		ib = ib + num;
	}
}

int main() {
	int n;
	while (cin >> n) {
		int size = (1 << n);
		vector<int> vdata(size);
		for (int i = 0; i < size; ++i) {
			cin >> vdata[i];
		}
		int qsize;
		cin >> qsize;
		for (int i = 0; i < qsize; ++i) {
			int tmp;
			cin >> tmp;
			Reverse(vdata, 1 << tmp);
			cout << numOfReverse(vdata) << endl;
		}
	}

	return 0;
}
#endif


#if 0
/*O(nlogn)可全过
大概思路就是记录所有2^i上的逆序对，只要记录2^(i-1)和另一半2^(i-1)之间的逆序对，例如2341里面
2^1上有1个
2^2上一共3个，但是有一个在21中算过了，所以就是2个
计算这个值的过程用O(n^2)能过80%，改成merge可以全过
同时，要计算2i下所有可能的组合,即2^(i-1)*2^(i-1),再乘上2^i的个数，即2^(n-i)，得到2^(n+i-2),在merge的过程中同时还要记录等于的情况，因为这些等于的不管是否翻转都不是逆序对，所以对每一个2i还要减去等于的对数。
然后翻转的时候，假如翻转数字的是x，对于每个2^i(x >= i),值都改为上面求出的数 - 原值
逆序对总数就是从1-n求和。*/
#include<stdio.h>
#include<vector>
using namespace std;

long long n, m, total, sum, offset, num;

vector<long long> count;
vector<long long> l;
vector<long long> l_copy;
vector<long long> max_c;
void mergesort(long long index, long long size) {
	if (size == 0) {
		l_copy[index] = l[index];
		return;
	}
	vector<long long> l_copy2(1 << size);
	long long st1 = index, st2 = index + (1 << (size - 1)), ed1 = st2, ed2 = index + (1 << size);
	long long pos = 0, p1 = st1, p2 = st2;
	mergesort(st1, size - 1);
	mergesort(st2, size - 1);
	while (p1 < ed1 && p2 < ed2) {
		if (l_copy[p1] == l_copy[p2]) {
			long long c1 = 1, c2 = 1;
			l_copy2[pos++] = l_copy[p1++];
			l_copy2[pos++] = l_copy[p2++];
			while (p1 < ed1 && l_copy[p1] == l_copy[p1 - 1]) l_copy2[pos++] = l_copy[p1++], ++c1;
			while (p2 < ed2 && l_copy[p2] == l_copy[p2 - 1]) l_copy2[pos++] = l_copy[p2++], ++c2;
			max_c[size] -= c1 * c2;
			count[size] += (ed1 - p1) * c2;
		} else if (l_copy[p1] < l_copy[p2]) {
			l_copy2[pos++] = l_copy[p1++];
		} else {
			count[size] += ed1 - p1;
			l_copy2[pos++] = l_copy[p2++];
		}
	}
	if (p1 == ed1)while (p2 != ed2) l_copy2[pos++] = l_copy[p2++];
	else if (p2 == ed2) while (p1 != ed1) l_copy2[pos++] = l_copy[p1++];
	for (long long i = st1; i < ed2; ++i) l_copy[i] = l_copy2[i - st1];
}

int main() {
	scanf("%lld", &n);
	total = (long long)1 << n;
	count.resize(n + 1);
	max_c.resize(n + 1);
	l.resize(total);
	l_copy.resize(total);
	for (long long i = 0; i < total; ++i) scanf("%lld", &l[i]);
	max_c[0] = 1;
	for (long long i = 1; i <= n; ++i) max_c[i] = (long long)1 << (n + i - 2);//(1 << 2 * (i - 1) ) * ( 1 << (n - i))

	mergesort(0, n);

	scanf("%lld", &m);
	for (long long i = 0; i < m; ++i) {
		scanf("%lld", &num);
		sum = 0;
		for (long long j = 1; j <= n; ++j) {
			if (j <= num) count[j] = max_c[j] - count[j];
			sum += count[j];
		}
		printf("%lld\n", sum);
	}
}
#endif

#if 0
/*通过百分之百，先利用归并排序初始化不同间隔的逆序对和顺序对之和，当反转时交换顺序对和逆序对即可。
每次查询时将不同间隔的逆序对加起来。总复杂度为O(nm + n * 2 ^ n)。*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

typedef long long ll;
const int maxn = (1 << 20) + 50;;
int n, m, q[maxn], a[maxn], v1[maxn], v2[maxn];
ll rev[50], nor[50];

void init(int o, int l, int r, ll rev[], int nums[]) {
	if (r == l) {
		return;
	}
	int mid = (l + r) / 2;
	init(o - 1, l, mid, rev, nums);
	init(o - 1, mid + 1, r, rev, nums);
	ll no = 0, re = 0;
	int i = l, j = mid + 1, k = l;
	for (i = l, j = mid + 1, k = l; i <= mid && j <= r;) {
		if (nums[i] <= nums[j]) {
			a[k++] = nums[i];
			i++;
		} else {
			a[k++] = nums[j];
			re += 1L * mid + 1 - i;
			j++;
		}
	}
	if (i <= mid) {
		while (i <= mid) {
			a[k++] = nums[i++];
		}
	}
	if (j <= r) {
		while (j <= r) {
			a[k++] = nums[j++];
		}
	}
	rev[o] += re;
	for (i = l; i <= r; i++) {
		nums[i] = a[i];
	}
}

ll solve(int o) {
	for (int i = o; i >= 0; i--) {
		swap(nor[i], rev[i]);
	}
	ll ans = 0;
	for (int i = 0; i <= n; i++) {
		ans += rev[i];
	}
	return ans;
}

int main() {
	cin >> n;
	int temp;
	//vector<int> v1,v2;
	for (int i = 0; i < (1 << n); i++) {
		scanf("%d", &temp);
		v1[i] = temp;
		v2[i] = temp;

	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d", &q[i]);
	}
	memset(nor, 0, sizeof(nor));
	memset(rev, 0, sizeof(rev));
	init(n, 0, (1 << n) - 1, rev, v1);
	reverse(v2, v2 + (1 << n));
	init(n, 0, (1 << n) - 1, nor, v2);

	for (int i = 0; i < m; i++) {
		cout << solve(q[i]) << endl;
	}
}
#endif
