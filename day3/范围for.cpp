//1.使用范围for，通过输入为一个数组赋值 
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


