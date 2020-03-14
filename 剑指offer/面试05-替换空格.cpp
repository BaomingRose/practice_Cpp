#include <iostream>
#include <cstring>
using namespace std;

void replaceSpace(char* str, int length) {
	char* ptr = str;
	int space_num = 0;
	//调式时发现指针没有解引用 
	while (*ptr != '\0') {
		if (*ptr == ' ') 
			++space_num;
		++ptr;
	}
	int newLength = strlen(str) + space_num * 2;
	//调式时逻辑错误 '<'导致错误 
	if (newLength > length) {
		return;
	}
	char* ptr_last = str + newLength;
	
	while (ptr != ptr_last) {
		if (*ptr == ' ') {
			*ptr_last-- = '0';
			*ptr_last-- = '2';
			*ptr_last-- = '%';
			ptr--;
		}
		else  
			*ptr_last-- = *ptr--;
	}
}

int main() {
	char str[100] = "We are happy.";
	cout << str << endl;
	replaceSpace(str, 100);
	cout << str << endl;
	
	return 0;
}
