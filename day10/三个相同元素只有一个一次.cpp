#if 0
#include<iostream>
#include<vector>
using namespace std;
/*一个数组，都是3个相同的，只有一数个只有一个*/

#if 0
//这个算法很难想
int singleNumber3(vector<int>& nums) {
	int sum = 0, tmp = 0;
	for (auto &i : nums) {
		sum = (sum ^ i) & ~tmp;
		tmp = (tmp ^ i) & ~sum;
	}
	return sum;
}
#endif

//所有数的二进制如果相同位数上的1个数是3的倍数,则那个数那位为0,如果 %3==1,则那个数那位为1
int singleNumber3(vector<int>& nums) {
	int res = 0;
	int i, count = 0;
	for (i = 0; i < 32; ++i) {
		for (auto & j : nums) {
			if (j >> i & 1 == 1)
				++count;
		}
		if (count % 3 != 0)
			res = res | (1 << i);
		count = 0;
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

	cout << singleNumber3(v) << endl;

	return 0;
}
#endif