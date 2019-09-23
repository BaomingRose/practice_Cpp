#if 0
#include<iostream>
#include<vector>
using namespace std;

int maxLenSum(vector<int> nums) {
	int tmpSum = 0;
	int maxSum = 0;
	for (auto i : nums) {
		tmpSum += i;
		if (tmpSum > maxSum) {
			maxSum = tmpSum;
		}
		if (tmpSum < 0) {
			tmpSum = 0;
		}
	}
	if (maxSum <= 0) {
		maxSum = nums[0];
		for (auto i : nums) {
			if (i > maxSum) {
				maxSum = i;
			}
		}
	}
	return maxSum;
}

int main() {
	vector<int> v;
	int len;
	int num;
	cout << "请输入将要输入的数组长度len" << endl;
	cin >> len;
	cout << "请输入len个元素" << endl;
	for (int i = 0; i < len; ++i) {
		cin >> num;
		v.push_back(num);
	}
	cout << "最大子序列和为：" << " ";
	cout << maxLenSum(v) << endl;
	return 0;
}
#endif