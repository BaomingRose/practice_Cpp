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
	cout << "�����뽫Ҫ��������鳤��len" << endl;
	cin >> len;
	cout << "������len��Ԫ��" << endl;
	for (int i = 0; i < len; ++i) {
		cin >> num;
		v.push_back(num);
	}
	cout << "��������к�Ϊ��" << " ";
	cout << maxLenSum(v) << endl;
	return 0;
}
#endif