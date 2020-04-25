/*================================================
 * description：
 小Q在进行一场竞技游戏,这场游戏的胜负关键就在于能否能争夺一条长度为L的河道,即可以看作是[0,L]的一条数轴。
这款竞技游戏当中有n个可以提供视野的道具−真视守卫,第i个真视守卫能够覆盖区间[xi,yi]。
现在小Q想知道至少用几个真视守卫就可以覆盖整段河道。
	解析：一段一段最少几段拼全整段

//贪心选择
=================================================*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, L; 
	cin >> n >> L;
	vector<pair<int, int>> vec(n);
	for (int i = 0; i < n; ++i) 
		cin >> vec[i].first >> vec[i].second;
	sort(vec.begin(), vec.end());

	if (vec[0].first > 0) { 
		cout << -1; 
		return 0; 
	}

	int right = 0;
	int res = 0;
	int i = 0;

	while (i < n) {
		//当前右值
		int r = right;
		//从当前位置开始往后找一个尾巴最长的更新右值
		for (; i < n && vec[i].first <= r; ++i) {
			right = max(right, vec[i].second);
		}
		++res;

		if (right >= L) { 
			cout << res; 
			return 0;
		}
		if (i >= n || vec[i].first > right) { 
			cout << -1; 
			return 0;
		}
	}
	
	return 0;
}