/*2.
д���������ú������صķ�ʽ��д����ͳ�Ƴ�һ���������ṹΪ��׼�Ľṹ�������У� 
1������ΪX�ĳ����˶��ٴ� 
2������ΪX�ĳ����˶��ٴ� 
3���༶ΪX�ĳ����˶��ٴ� 
4���Ա��X�ĳ����˶��ٴ� 

���磺����ΪX�Ŀ����������������� 
int countName(student * src, int n, char * name); 
tip:���Կ�����ȱʡ�����ķ�ʽ�����߻ص������ķ�ʽʵ�֡�
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
	return !(a.sex ^ b.sex);	//���� 
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
