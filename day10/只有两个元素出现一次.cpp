#if 0
#include<iostream>
#include<vector>
using namespace std;

/*所有数异或一遍，结果为两个单身狗异或的结果，再分析这个结果，找到第一个为1的位置，
通过这个1将数组分成两组，则这两只单身狗必定在不同的组里，分别对两组全部异或一遍，
两组的结果即为两只单身狗。*/
vector<int> singleNumber(vector<int>& nums) {
	vector<int> res;
	int sum = 0;
	for (auto i : nums) {
		sum ^= i;
	}
	int pos;
	for (int i = 0; i < 32; ++i) {
		if (sum & 1 << i) {
			pos = i;
			break;
		}
	}
	int num1 = 0, num2 = 0;
	for (auto i : nums) {
		if (i & 1 << pos)
			num1 ^= i;
		else
			num2 ^= i;
	}
	res.push_back(num1);
	res.push_back(num2);
	return res;	
}

int main() {
	int a[] = { 1, 2, 3, 4, 3, 2, 1, 5 };
	vector<int> nums(a, a + 8);
	vector<int> res = singleNumber(nums);
	for (auto i : res) {
		cout << i << " ";
	}


	return 0;
}
#endif