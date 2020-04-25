/*================================================
 * description：
 小Q在周末的时候和他的小伙伴来到大城市逛街，一条步行街上有很多高楼，共有n座高楼排成一行。
小Q从第一栋一直走到了最后一栋，小Q从来都没有见到这么多的楼，所以他想知道他在每栋楼的位置处能看到多少栋楼呢？
（当前面的楼的高度大于等于后面的楼时，后面的楼将被挡住）
=================================================*/
#if 1
//单调栈
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

//a表示左边升序的个数，b表示右边升序的个数(从后向前，所以要翻转)
vector<int> a, b;
//st1表示左边的升序栈，st2表示右边的升序栈
stack<int> st1, st2;

int main() {
	int n, x[100001];
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) 
		cin >> x[i];

	for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
		a.push_back(st1.size());
		b.push_back(st2.size());

		//如果栈顶小于下一个，就pop，保持栈是升序
		while (!st1.empty() && st1.top() <= x[i])
			st1.pop();
		while (!st2.empty() && st2.top() <= x[j]) 
			st2.pop();
		st1.push(x[i]);
		st2.push(x[j]);
	}

	reverse(b.begin(), b.end());

	for (int i = 0; i < n; i++) 
		cout << b[i] + a[i] + 1 << " ";

	return 0;
}
#endif