#if 0
//总结一：即使父类的析构函数是虚函数，最后子类对象析构的时候最后也会调用父类析构
//需要注意的是父类的析构函数一定会调用，不要造成二次释放
//不要在子类析构函数显示调用父类析构函数
class Base {
public:
	virtual void draw() = 0;

	virtual ~Base() {
		cout << "Base::~Base（）" << endl;
	}
};

class Derived : public Base {
public:
	virtual void draw() {
		cout << "Derived::draw()" << endl;
	}

	virtual ~Derived() {
		cout << "Derved::~Derived()" << endl;
	}
};

int main() {
	Base* b = new Derived();
	b->draw();
	delete b;

	return 0;
}
#endif

#if 0
/*================================================
 * description：析构函数尽量别纯虚函数，否则必须在类外进行定义，不然子类对象析构的时候找不到父类析构，连接错误(不是编译错误)
 
=================================================*/
#include <iostream>
using namespace std;

class Base {
public:
	virtual void draw() = 0;

	//必须类外定义纯虚函数，子类对象析构的时候就找不到该函数了
	virtual ~Base() = 0;
};

class Derived : public Base {
public:
	virtual void draw() {
		cout << "Derived::draw()" << endl;
	}

	virtual ~Derived() {
		cout << "Derved::~Derived()" << endl;
	}
};

Base::~Base() {
	cout << "Base::~Base()" << endl;
}

int main() {
	Base* b = new Derived();
	b->draw();
	delete b;

	return 0;
}
#endif

#if 0
/*================================================
 * description：如果父类的析构不是虚函数，则子类对象析构的时候不会调用子类的析构函数
 
=================================================*/
#include <iostream>
using namespace std;

class Base {
public:
	virtual void draw() = 0;

	 ~Base() {
		cout << "Base::~Base（）" << endl;
	}
};

class Derived : public Base {
	virtual void draw() {

	}

	~Derived() {
		cout << "Derived::~Derived()" << endl;
	}
};

int main() {
	Base* b = new Derived();
	delete b;

	return 0;
}
#endif

#if 0
/*================================================
 * description：父类析构函数为虚函数，子类不重写析构函数, 一定会调用父类的析构函数
 
=================================================*/
#include <iostream>
using namespace std;

class Base {
public:
	virtual void draw() = 0;

	 virtual ~Base() {
		cout << "Base::~Base（）" << endl;
	}
};

class Derived : public Base {
	virtual void draw() {

	}
};


int main() {
	Base* b = new Derived();
	delete b;

	return 0;
}
#endif

#if 0
/*================================================
 * description：如果子类析构调用父类的析构函数，会造成两次调用父类的析构函数
 
=================================================*/

#include <iostream>
using namespace std;

class Base {
public:
	virtual void draw() = 0;

	 virtual ~Base() {
		cout << "Base::~Base（）" << endl;
	}
};

class Derived : public Base {
	virtual void draw() {

	}

	virtual ~Derived() {
		cout << "Derived::~Derived()" << endl;
		Base::~Base();
	}
};

int main() {
	Base* b = new Derived();
	delete b;

	return 0;
}
#endif

#if 0
/*================================================
 * description：如果父类的析构声明为纯虚函数，子类即使不重写析构也不是抽象类，可以实例化
 
=================================================*/

#include <iostream>
using namespace std;

class Base {
public:
	virtual void draw() = 0;

	virtual ~Base() = 0;
};

Base::~Base() {
	cout << "Base::~Base()" << endl;
}

class Derived : public Base {
public:
	virtual void draw() {
		cout << "Derived::draw()" << endl;
	}
};

int main() {
	Base* b = new Derived();
	delete b;

	return 0;
}
#endif
