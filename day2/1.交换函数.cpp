//1���ֱ�ʹ�����úͺ���ɽ���������ʹ�������������������ͬ 

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
