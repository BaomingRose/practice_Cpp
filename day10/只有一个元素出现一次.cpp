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
	cout << "������v�е�Ԫ�ظ�����" << endl;
	cin >> n;
	cout << "������n��Ԫ��" << endl;
	while (n--) {
		cin >> num;
		v.push_back(num);
	}

	cout << singleNumber(v) << endl;

	return 0;
}
#endif