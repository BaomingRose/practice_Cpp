#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

class Singleton {
public:
	static Singleton& getInstance() {
		if (single_ptr == NULL) {
			_mtx.lock();
			if (single_ptr == NULL)
				single_ptr = new Singleton();
			_mtx.unlock();
		}
		return *single_ptr;
	}

	void print() {
		cout << "i am a Singleton" << endl;
	}

private:
	Singleton() {}

	Singleton(const Singleton& s) {}

	~Singleton() {}

	static Singleton* single_ptr;
	static mutex _mtx;		//»¥³âËø
};

Singleton* Singleton::single_ptr = NULL;
mutex Singleton::_mtx;

void fun(int n) {
	for (int i = 0; i < n; ++i) {
		Singleton::getInstance().print();
	}
}
int main() {
	/*Singleton* ps = Singleton::getInstance();
	Singleton* ps1 = Singleton::getInstance();
	Singleton* ps2 = Singleton::getInstance();
	Singleton* ps3 = Singleton::getInstance();*/

	int n;
	cin >> n;
	thread t1(fun, n);
	thread t2(fun, n);
	thread t3(fun, n);
	thread t4(fun, n);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	/*fun(n);
	fun(n);*/
	return 0;
}

