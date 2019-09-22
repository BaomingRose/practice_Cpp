#if 0
#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums) {
	int res = 0;
	for (auto i : nums) {
		res ^= i;
	}
	return res;
}

int main() {
	vector<int> v;
	int n, num;
	cout << "请输入v中的元素个数：" << endl;
	cin >> n;
	cout << "请输入n个元素" << endl;
	while (n--) {
		cin >> num;
		v.push_back(num);
	}

	cout << singleNumber(v) << endl;

	return 0;
}
#endif