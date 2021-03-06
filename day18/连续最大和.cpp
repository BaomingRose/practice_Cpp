//一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1,2,1]，和最大的连续子数组为[2,1]，其和为 3

/*假设sum[i-1]是以数组中第nums[i-1]为最后一个元素的一段子数组最大和，
sum[i]是以数组中第nums[i]为最后一个元素的一段子数组最大和，
那么sum[i] = max(sum[i-1], 0) + nums[i]，理解了这个，下面代码中用sum1表示sum[i-1]，sum2表示
sum[i]，如果计算出更大的子数组和则保存到result中。如果sum[i]，及sum2都小于0了，则置为0，因为他
加上数组下一个数，不会计算出更大的子数组和 */

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
		// 计算到num[i]的子数组的最大和
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
