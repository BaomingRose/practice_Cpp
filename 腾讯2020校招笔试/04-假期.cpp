/*================================================
 * description：
 由于业绩优秀，公司给小Q放了 n 天的假，身为工作狂的小Q打算在在假期中工作、锻炼或者休息。
 他有个奇怪的习惯：不会连续两天工作或锻炼。
 只有当公司营业时，小Q才能去工作，只有当健身房营业时，小Q才能去健身，小Q一天只能干一件事。
 给出假期中公司，健身房的营业情况，求小Q最少需要休息几天。
 输入：
第一行一个整数 n(1\leq n\leq 100000)n(1≤n≤100000) 表示放假天数
第二行 n 个数 每个数为0或1,第 i 个数表示公司在第 i 天是否营业
第三行 n 个数 每个数为0或1,第 i 个数表示健身房在第 i 天是否营业
（1为营业 0为不营业）

 动态规划，dp中记录3中状态下有事可做的最多天数，休息（dp[0][i]）、健身（dp[1][i]）、工作（dp[2][i]）。
dp[0][i] = max(dp[0][i - 1], max(dp[1][i - 1], dp[2][i - 1]));休息无事可做，值为前一天3中状态下的最大值。
dp[1][i] = max(dp[2][i - 1], dp[0][i - 1]) + 1;选择健身，值为前一天休息和工作的最大值+1。
dp[2][i] = max(dp[1][i - 1], dp[0][i - 1]) + 1;选择工作，值为前一天休息和健身的最大值+1。
最后输出n减去最后一天三种状态下的最大值。
=================================================*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> work(n), slp(n);
	for (int i = 0; i < n; ++i)
		cin >> work[i];
	for (int i = 0; i < n; ++i)
		cin >> slp[i];

	vector<vector<int>> dp(3, vector<int>(n + 1));
	dp[0][0] = dp[1][0] = dp[2][0] = 0;

	for (int i = 1; i <= n; ++i) {
		dp[0][i] = max(dp[0][i - 1], max(dp[1][i - 1], dp[2][i - 1]));
		if (slp[i - 1]) {
			dp[1][i] = max(dp[2][i - 1], dp[0][i - 1]) + 1;
		}
		if (work[i - 1]) {
			dp[2][i] = max(dp[1][i - 1], dp[0][i - 1]) + 1;
		}
	}

	cout << n - max(dp[0][n], max(dp[1][n], dp[2][n])) << endl;

	return 0;
}