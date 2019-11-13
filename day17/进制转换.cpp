//给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数

/*本题思路很简单，首先想清楚原理：N进制数，每个进制位的值分别是X0*N^0，X1*N^1, X2*N^2.....，X0，
X1，X2就是这些进制位的值，就是就是进行取模余数就是当前低进制的位的值是多少，通过除掉进制数，进
入下一个进制位的计算*/

#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string s, table="0123456789ABCDEF";
	int m,n;
	cin>>m>>n;
	bool flag = false;
	// 如果是负数，则转成正数，并标记一下
	if(m < 0) {
		m = 0 - m;
		flag = true;
	}
	// 按进制换算成对应的字符添加到s
	while(m) {
		s += table[m%n];
		m /= n;
	}
	if(flag)
		s += '-';
	reverse(s.begin(), s.end());
	cout<<s<<endl;
	return 0;
}
