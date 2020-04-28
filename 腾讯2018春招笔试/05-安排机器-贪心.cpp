/*================================================
 * description��
 СQ�Ĺ�˾����ӵ�m������, ��i��������Ҫxi��ʱ��ȥ���, �Ѷȵȼ�Ϊyi��
СQӵ��n̨����, ÿ̨���������ʱ��zi, �����ȼ�wi��
����һ������,��ֻ�ܽ���һ̨���������, ������Ÿ����Ļ����������ʱ��С��������Ҫ��ʱ��, �������,������������񽫻��200 * xi + 3 * yi���档
����һ̨����,��һ��ֻ�����һ������, ������Ļ����ȼ�С�ڰ��Ÿ����������Ѷȵȼ�, ������ɡ�
СQ���ڽ��쾡���ܵ�ȥ�������, ����ɵ����������������ж��ְ��ŷ���,СQ�����ҵ����������Ǹ�������СQ��Ҫ��������������һ�¡�

//̰�Ĳ�������������
=================================================*/
#if 0
//�ҵĴ𰸣�̰�Ĳ���ȷ, ����������ϣ���secondҲ��һ����Ϳ���, ̰�Ļ��ǿ��Ե�
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
//�������򷽷�
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