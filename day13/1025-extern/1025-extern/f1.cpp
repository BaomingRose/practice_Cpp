#include<iostream>
using namespace std;

int i(1);

//�ⲿ����������
extern int reset(), next(), last(), other(int);

int main() {
	
	int i = reset();
	for (int j(1); j <= 3; ++j) {
		
		cout << i << ", " << j << ",";
		cout << next() << ",";
		//�⼸���ⲿ����ʹ�õ�i�����䶨��ĺ����ļ��ڵľ�̬ȫ�ֱ���i
		cout << last() << ",";
		cout << other(i + j) << endl;
	}

	return 0;
}