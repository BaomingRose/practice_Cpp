/*================================================
 * date: 2021/03/03
 * description：字节2019春招第7题
 一个数组表示台阶高度，起初有能量，如果跳到下一步，如果下一步高度大于能量，则能量减差值，如果低于能量，则能量加差值
 问最初多少能量可以完成

 思想：从后向前推，假设最后结束为0，跳跃后能量为2E-H
=================================================*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	int N;
	int ans = 0;
	cin >> N;
	vector<int> D(N, 0);
	for (int i = 0; i < N; i++)
		cin >> D[i];

	//假设最后结束是0，那么从最后向前推，跳跃后能量为2E-H
	for (int j = N - 1; j >= 0; j--) {
		ans = ceil((D[j] + ans) / 2.0);//注意c++中除法整数/整数为0，ceil向上取整要整数/float类型
	}

	cout << ans << endl;
	return 0;
}