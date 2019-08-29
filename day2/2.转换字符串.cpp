/* a、将一个字符串转换为数字，返回值用来校验转换是否成功 
bool strtoi(const char *, int &); 
b、将一个数字通过指定进制按位逆序（直接覆盖原数） 
void sysReverse(int &, int); */

#include<iostream>
using namespace std;

bool strtoi(const char *src, int &res) {
	if (!src) {
		return false;
	}
	while (*src <= ' ') {
		src++;
	}
	int flag = 1;
	if (*src == '-') {
		flag = -1;
		src++;
	}
	if (*src > '9' || *src < '0') {
		return false;
	}
	int sum = 0, tmp;
	int i;
	for (i = 0; src[i] <= '9' && src[i] >= '0'; i++) {
		tmp = src[i] - '0';
		sum = sum * 10 + tmp;
	}
	res = sum * flag;
	return true;
}

void sysReverse(int &n, int hex) {
	int sum = 0;
	int tmp;
	for(int i = n; i; i /= hex) {
		tmp = i % hex;
		sum = sum * hex + tmp; 
	} 
	n = sum;
}

int main() {
	
	int res;
	if(strtoi("      \t\n24336", res));
	printf("%d\n", res);
	
	int i = 10;	
	sysReverse(i, 2);
	printf("%d\n", i);
	
}
