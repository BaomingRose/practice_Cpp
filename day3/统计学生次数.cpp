/*2.
写出函数，用函数重载的方式编写程序，统计出一个以上述结构为基准的结构体数组中： 
1、名字为X的出现了多少次 
2、年龄为X的出现了多少次 
3、班级为X的出现了多少次 
4、性别的X的出现了多少次 

例如：名字为X的可以是这样的声明： 
int countName(student * src, int n, char * name); 
tip:可以考虑用缺省参数的方式，或者回调函数的方式实现。
*/
#include<iostream>
#include<cstring>
using namespace std;

struct student {
	char name[32];
	int age;
	int classid;
	bool sex;
};

bool cmp1(student a, student b) {
	return strcmp(a.name, b.name) ? false : true;
}

bool cmp2(student a, student b) {
	return a.age == b.age;
}

bool cmp3(student a, student b) {
	return a.classid == b.classid;
}

bool cmp4(student a, student b) {
	return !(a.sex ^ b.sex);	//精辟 
}

int countS(student * src, int n, student same, bool (*cmp)(student, student) = cmp1) {
	int count = 0;
	for(int i = 0; i < n; ++i) {
		if(cmp(src[i], same)) {
			++count;
		}
	}
	return count;
}

int main() {
	student a[10] = {{"paul", 33, 2, true}, 
					 {"paul", 33, 2, true},
					 {"rose", 30, 1, true},
					 {"curry", 31, 3, true},
					 {"james", 34, 1, true},
					 {"george", 29, 1, true},
					 {"rose", 30, 1, true},
					 {"wade", 35, 2, true},
					 {"bill", 29, 3, true},
					 {"qiaobiluo", 58, 4, false}};
	student value = {"rose", 30, 1, true};
	cout << countS(a, 10, value) << endl;
	
}
