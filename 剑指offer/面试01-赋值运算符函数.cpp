#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring> 
using namespace std;

class MyString {
private:
	char*  s_ptr;
public:
	//构造中的置空很重要 
	MyString(const char* str = "") : s_ptr(NULL) {
		s_ptr = new char[strlen(str) + 1];
		memset(s_ptr, '0', strlen(str) + 1);
		strcpy(s_ptr, str);
	}

	~MyString() {
		if (s_ptr) {
			delete[] s_ptr;
			s_ptr = NULL;
		}
	}

	//构造中的置空很重要 
	MyString(const MyString& str) : s_ptr(NULL) {
		MyString tmpStr(str.s_ptr);
		swap(s_ptr, tmpStr.s_ptr);
	}

	MyString& operator=(const MyString& str) {
		//要判断传入的参数和当前实例是不是同一个实例
		//这种写法可以避免new异常之前原来实例被修改 
		if (this != &str) {
			MyString tmpStr(str);
			swap(s_ptr, tmpStr.s_ptr);
		}

		return *this;
	}

	friend istream& operator>>(istream& is, MyString& str);
	friend ostream& operator<<(ostream& os, MyString& str);
};

istream& operator>>(istream& is, MyString& str) {
	is >> str.s_ptr;
	return is;
}

ostream& operator<<(ostream& os, MyString& str) {
	os << str.s_ptr;
	return os;
}

int main() {
	MyString s1("ouyangcuifen");
	cout << "s1= " << s1 << endl;
	MyString s2(s1);
	cout << "copy(s1) s2 = " << s2 << endl;
	MyString s3 = "Rose";
	cout << "s3 = " << s3 << endl;
	s3 = s2;
	cout << "s3 = s2---s3 = " << s3 << endl;

	MyString s4;
	cout << "输入s4:" << endl;
	cin >> s4;
	cout << "s4 = " << s4 << endl;

	return 0;
}
