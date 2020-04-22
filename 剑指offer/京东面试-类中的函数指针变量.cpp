/*================================================
 * description：类中的函数指针变量，它仍然是一个变量，无论调用还是赋值都是需要通过对象来使用
				面试的时候踩了坑，回答成A::fun();	 A::void(*fun)();完全错误
=================================================*/
#include <iostream>
using namespace std;

void fun1() {
	cout << "fun1" << endl;
}

void fun2() {
	cout << "fun2" << endl;
}

class A {
public:
	void(*fun)();
	
	A() {
		fun = fun1;
		fun();
	}
};

int main() {
	A a;
	a.fun();
	a.fun = fun2;
	a.fun();

	return 0;
}
