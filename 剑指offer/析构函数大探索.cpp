#if 0
//�ܽ�һ����ʹ����������������麯��������������������ʱ�����Ҳ����ø�������
//��Ҫע����Ǹ������������һ������ã���Ҫ��ɶ����ͷ�
//��Ҫ����������������ʾ���ø�����������
class Base {
public:
	virtual void draw() = 0;

	virtual ~Base() {
		cout << "Base::~Base����" << endl;
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
 * description�����������������麯�������������������ж��壬��Ȼ�������������ʱ���Ҳ����������������Ӵ���(���Ǳ������)
 
=================================================*/
#include <iostream>
using namespace std;

class Base {
public:
	virtual void draw() = 0;

	//�������ⶨ�崿�麯�����������������ʱ����Ҳ����ú�����
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
 * description�������������������麯�������������������ʱ�򲻻�����������������
 
=================================================*/
#include <iostream>
using namespace std;

class Base {
public:
	virtual void draw() = 0;

	 ~Base() {
		cout << "Base::~Base����" << endl;
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
 * description��������������Ϊ�麯�������಻��д��������, һ������ø������������
 
=================================================*/
#include <iostream>
using namespace std;

class Base {
public:
	virtual void draw() = 0;

	 virtual ~Base() {
		cout << "Base::~Base����" << endl;
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
 * description����������������ø����������������������ε��ø������������
 
=================================================*/

#include <iostream>
using namespace std;

class Base {
public:
	virtual void draw() = 0;

	 virtual ~Base() {
		cout << "Base::~Base����" << endl;
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
 * description������������������Ϊ���麯�������༴ʹ����д����Ҳ���ǳ����࣬����ʵ����
 
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
