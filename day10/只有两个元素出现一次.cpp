#if 0
#include<iostream>
#include<vector>
using namespace std;

/*���������һ�飬���Ϊ�����������Ľ�����ٷ������������ҵ���һ��Ϊ1��λ�ã�
ͨ�����1������ֳ����飬������ֻ�����ض��ڲ�ͬ������ֱ������ȫ�����һ�飬
����Ľ����Ϊ��ֻ������*/
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