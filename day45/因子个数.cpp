/*一个正整数可以分解成一个或多个数组的积。
例如36=2*2*3*3，即包含2和3两个因子。
NowCoder最近在研究因子个数的分布规律，现在给出一系列正整数，他希望你开发一个程序输出每个正整数的因子个数。*/

#include <iostream>
#include<cmath>
using namespace std;
int main() {	
	int n, k, i;
	while(cin >> n) {
		k=0;
		for(i = 2; i <= sqrt(n); i++) {
			if ((n % i) == 0) {
				while((n % i) == 0) {
					n = n / i;
				} 
				k++;
			}
		} 
		if(n != 1)
			k++;
		cout << k << endl;
	} 
	return 0;
}
