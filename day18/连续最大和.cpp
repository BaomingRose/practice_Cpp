//һ�������� N ��Ԫ�أ�����������������͡� ���磺[-1,2,1]������������������Ϊ[2,1]�����Ϊ 3

/*����sum[i-1]���������е�nums[i-1]Ϊ���һ��Ԫ�ص�һ�����������ͣ�
sum[i]���������е�nums[i]Ϊ���һ��Ԫ�ص�һ�����������ͣ�
��ôsum[i] = max(sum[i-1], 0) + nums[i]�����������������������sum1��ʾsum[i-1]��sum2��ʾ
sum[i]�����������������������򱣴浽result�С����sum[i]����sum2��С��0�ˣ�����Ϊ0����Ϊ��
����������һ�������������������������� */

#include <iostream>
#include<vector>
using namespace std;

int main() {
	int size;
	cin >> size;
	vector<int> nums(size);
	for(size_t i = 0; i < size; ++i)
		cin >> nums[i];
	int result = nums[0];
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < nums.size(); i++) {
		// ���㵽num[i]�������������
		sum2 = sum1 >= 0 ? sum1+nums[i] : nums[i];
		if(sum2 > result)
			result = sum2;
		if(sum2 < 0)
			sum2 = 0;
		sum1 = sum2;
	}
	cout << result <<endl;
	return 0;
}
