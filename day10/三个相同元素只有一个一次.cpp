#if 0
#include<iostream>
#include<vector>
using namespace std;
/*һ�����飬����3����ͬ�ģ�ֻ��һ����ֻ��һ��*/

#if 0
//����㷨������
int singleNumber3(vector<int>& nums) {
	int sum = 0, tmp = 0;
	for (auto &i : nums) {
		sum = (sum ^ i) & ~tmp;
		tmp = (tmp ^ i) & ~sum;
	}
	return sum;
}
#endif

//�������Ķ����������ͬλ���ϵ�1������3�ı���,���Ǹ�����λΪ0,��� %3==1,���Ǹ�����λΪ1
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
	cout << "������v�е�Ԫ�ظ�����" << endl;
	cin >> n;
	cout << "������n��Ԫ��" << endl;
	while (n--) {
		cin >> num;
		v.push_back(num);
	}

	cout << singleNumber3(v) << endl;

	return 0;
}
#endif