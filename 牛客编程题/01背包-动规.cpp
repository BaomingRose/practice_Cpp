/*================================================
 * description：
 有 n 个物品和一个大小为 m 的背包. 给定数组 A 表示每个物品的大小和数组 V 表示每个物品的价值.
问最多能装入背包的总价值是多大?
核心动规公式：
		int newValue = result[j - A[i]] + V[i];
		result[j] = max(newValue, result[j]);
=================================================*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* 参数：
 * m : 背包大小
 * A : 商品大小
 * V : 商品价值
*/

#if 0
int backPackII(int m, vector<int> A, vector<int> V) {
	if (A.empty() || V.empty() || m < 1) {
		return 0;
	}

	//多加一行一列，用于设置初始条件
	const int N = A.size() + 1;
	const int M = m + 1;
	vector<vector<int> > result(N, vector<int>(M, 0));

	for (int i = 1; i < N; ++i) {
		for (int j = 1; j != M; ++j) {
			//第i个商品在A中对应的索引为i-1: i从1开始
			//如果第i个商品大于j,说明放不下， 所以(i,j)的最大价值和(i-1,j)相同
			if (A[i - 1] > j) {
				result[i][j] = result[i - 1][j];
			}
			//如果可以装下，分两种情况，装或者不装
			//如果不装，则即为(i-1, j)
			//如果装，需要腾出放第i个物品大小的空间： j - A[i-1],装入之后的最大价值即为(i - 1,j - A[i - 1]) + 第i个商品的价值V[i - 1]
				//最后在装与不装中选出最大的价值
			else {
				int newValue = result[i - 1][j - A[i - 1]] + V[i - 1];
				result[i][j] = max(newValue, result[i - 1][j]);
			}
		}
	}
	//返回装入前N个商品，物品大小为m的最大价值
	return result[N - 1][m];
}
#endif

//优化
int backPackII(int m, vector<int> A, vector<int> V) {
	if (A.empty() || V.empty() || m < 1) {
		return 0;
	}

	const int N = A.size();
	//多加一列，用于设置初始条件，因为第一件商品要用到前面的初始值
	const int M = m + 1;
	vector<int> result(M, 0);

	//这里商品的索引位置不需要偏移，要和未优化的方法区分开
	//这里的i-1理解为上一行，或者未更新的一维数组值
	for (int i = 0; i != N; ++i) {
		for (int j = M - 1; j > 0; --j) {
			//如果第i个商品大于j,说明放不下， 所以(i,j)的最大价值和(i-1,j)相同

			//如果可以装下，分两种情况，装或者不装
			//如果不装，则即为(i-1, j)
			//如果装，需要腾出放第i个物品大小的空间： j - A[i],装入之后的最大价值即为(i - 1, j - A[i - 1]) + 第i个商品的价值V[i]
			//最后在装与不装中选出最大的价值
			if (A[i] <= j) {
				int newValue = result[j - A[i]] + V[i];
				result[j] = max(newValue, result[j]);
			}
		}
	}
	//返回装入前N个商品，物品大小为m的最大价值
	return result[m];
}

int main() {
	int m = 10;
	vector<int> A{ 2, 3, 5, 7 };
	vector<int> V{ 1, 5, 2, 4 };

	cout << backPackII(m, A, V) << endl;

	return 0;
}