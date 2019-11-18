/*Fibonacci数列是这样定义的：
F[0] = 0
F[1] = 1
for each i ≥ 2: F[i] = F[i-1] + F[i-2]
因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。
给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。
*/

/*
本题可以通过先找到距离N最近的两个Fibonacci数，这两个数分别取自距离N的最近的左边一个
数L和右边一个数R，然后通过min(N - L, R - N)找到最小步数
*/

#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int input;
	cin >> input;
	int f0 = 0, f1 = 1;
	int f2 = f0 + f1;
	
	while (1) {
		if (input == f1) {
			cout << 0 << endl;
			break;
		} else if (f2 > input) {
			if (abs(f2 - input) > abs(input - f1)) {
				cout << abs(input - f1) << endl;
				break;
			} else {
				cout << abs(f2 - input);
				break;
			}
		}
		f0 = f1;
		f1 = f2;
		f2 = f1 + f0;
	}
	
	
	return 0;
} 
