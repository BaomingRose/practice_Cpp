#include<iostream>
using namespace std;

int i(1);

//外部函数的声明
extern int reset(), next(), last(), other(int);

int main() {
	
	int i = reset();
	for (int j(1); j <= 3; ++j) {
		
		cout << i << ", " << j << ",";
		cout << next() << ",";
		//这几个外部函数使用的i都是其定义的函数文件内的静态全局变量i
		cout << last() << ",";
		cout << other(i + j) << endl;
	}

	return 0;
}