//1、分别使用引用和宏完成交换方法（使用内联），体会两者异同 

#include<iostream>
using namespace std;

inline void swap(int &a, int &b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int a = 10, b = 20;
	swap(a, b);
	cout << a << " " << b << endl;
}
