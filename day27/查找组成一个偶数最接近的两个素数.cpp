/*任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，
本题目要求输出组成指定偶数的两个素数差值最小的素数对*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
//判断素数
bool isPrime(int num) {
	int tmp = sqrt(num);
	for (int i = 2; i <= tmp; i++) {
		if (num %i == 0)
		return false;
	} 
	return true;
}

int main() {
	int num;
	int half;
	int i;
	while (cin >> num) {
		half = num / 2;
		//从中间向两边找
		for (i = half; i > 0; i--) {
			if (isPrime(i) && isPrime(num - i))
				break;
		} 
		cout << i << endl << num - i << endl;
	}
	return 0;
}
