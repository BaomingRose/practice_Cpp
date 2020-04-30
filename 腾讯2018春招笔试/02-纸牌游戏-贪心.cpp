/*================================================
 * description：
牛牛和羊羊正在玩一个纸牌游戏。这个游戏一共有n张纸牌, 第i张纸牌上写着数字ai。
牛牛和羊羊轮流抽牌, 牛牛先抽, 每次抽牌他们可以从纸牌堆中任意选择一张抽出, 直到纸牌被抽完。
他们的得分等于他们抽到的纸牌数字总和。
现在假设牛牛和羊羊都采用最优策略, 请你计算出游戏结束后牛牛得分减去羊羊得分等于多少。
=================================================*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		multiset<int, greater<int>> s;
		int tmp;
		for (int i = 0; i < n; ++i) {
			cin >> tmp;
			s.insert(tmp);
		}
		int sum_niu = 0;
		int sum_yang = 0;
		bool flag = true;
		for (const auto& e : s) {
			if (flag == true) {
				sum_niu += e;
			}
			else {
				sum_yang += e;
			}
			flag = !flag;
		}
		cout << sum_niu - sum_yang << endl;
	}

	return 0;
}