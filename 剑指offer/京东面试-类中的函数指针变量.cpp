/*================================================
 * description�����еĺ���ָ�����������Ȼ��һ�����������۵��û��Ǹ�ֵ������Ҫͨ��������ʹ��
				���Ե�ʱ����˿ӣ��ش��A::fun();	 A::void(*fun)();��ȫ����
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
