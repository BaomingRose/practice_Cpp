//1.ʹ�÷�Χfor��ͨ������Ϊһ�����鸳ֵ 
//C++11

#include<iostream>
using namespace std;

int main() {
	int a[10];
	for(auto &i : a) {
		cin >> i;
	}
	
	for(auto &i : a) {
		cout << i << ' ';
	}
	
	return 0;
}


