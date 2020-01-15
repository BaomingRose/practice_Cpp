//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

#if 0
根据题图解析可以得出有一阶的时候 f(1) = 1 ； 有两阶的时候可以有 f(2) = 1+f(1)=2； 
有三阶的时候可以有 f(3) = 1+f(2)+f(1)=4;
...
总跳法为: f(n) = 1+f(n-1) + f(n-2)+....+f(1) （第一个1是跳n阶只有一种方法）
依次类推，得到类推公式有n阶时：f(n)=2^(n-1)。
#endif

#include <iostream>
using namespace std;

int jumpFloorII(int number) {
	//2^(n-1) == 1 << (n-1)
	return 1 << (number - 1);
}

int main() {
	int n;
	while (cin >> n) {
		cout << jumpFloorII(n) << endl;
	}
}
