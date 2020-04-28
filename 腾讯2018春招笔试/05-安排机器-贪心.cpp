/*================================================
 * description：
 小Q的公司最近接到m个任务, 第i个任务需要xi的时间去完成, 难度等级为yi。
小Q拥有n台机器, 每台机器最长工作时间zi, 机器等级wi。
对于一个任务,它只能交由一台机器来完成, 如果安排给它的机器的最长工作时间小于任务需要的时间, 则不能完成,如果完成这个任务将获得200 * xi + 3 * yi收益。
对于一台机器,它一天只能完成一个任务, 如果它的机器等级小于安排给它的任务难度等级, 则不能完成。
小Q想在今天尽可能的去完成任务, 即完成的任务数量最大。如果有多种安排方案,小Q还想找到收益最大的那个方案。小Q需要你来帮助他计算一下。

//贪心不能求出最大收益
=================================================*/
#if 0
//我的答案：贪心不正确, 在这个基础上，将second也排一个序就可以, 贪心还是可以的
#include <iostream>
#include <map>
using namespace std;

int main() {
	int n, m;
	while (cin >> n >> m) {
		multimap<int, int> machine;
		multimap<int, int> task;
		for (int i = 0; i < n; ++i) {
			int tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			machine.insert(make_pair(tmp1, tmp2));
		}
		for (int i = 0; i < m; ++i) {
			int tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			task.insert(make_pair(tmp1, tmp2));
		}

		int _count = 0;
		int income = 0;
		auto it = task.begin();
		while (it != task.end()) {
			auto it_ma = machine.begin();
			bool flag = false;
			while (it_ma != machine.end()) {
				if (it->first <= it_ma->first && it->second <= it_ma->second) {
					flag = true;
					_count++;
					income += 200 * it->first + 2 * it->second;
					machine.erase(it_ma);
					break;
				}
			}
			if (flag) {
				it = task.erase(it);
			} else {
				++it;
			}
		}
		cout << _count << " " << income << endl;
	}

	return 0;
}
#endif


#if 0
//给出排序方法
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int x;
	int y;
};

int cmp(node a, node b) {
	if (a.x == b.x)return a.y > b.y;
	return a.x > b.x;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<node> machine(n);
	vector<node> job(m);
	for (int i = 0; i < n; ++i)
		cin >> machine[i].x >> machine[i].y;
	for (int i = 0; i < m; ++i)
		cin >> job[i].x >> job[i].y;

	sort(machine.begin(), machine.end(), cmp);
	sort(job.begin(), job.end(), cmp);

	int num = 0;
	long long profit = 0;
	vector<int> cnt(101, 0);

	for (int i = 0, j = 0; i < m; ++i) {
		while (j < n && machine[j].x >= job[i].x) {
			cnt[machine[j].y]++;
			j++;
		}
		for (int k = job[i].y; k <= 100; ++k) {
			if (cnt[k]) {
				++num;
				cnt[k]--;
				profit += 200 * job[i].x + 3 * job[i].y;
				break;
			}
		}
	}
	cout << num << " " << profit << endl;
	return 0;
}
#endif