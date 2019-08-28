/*2.接口中多传入一个缺省参数,如果不指定,就采用A排序方式, 如果指定了,就按他的选择决定排序方式(至少包含三种)*/

#include<iostream>
using namespace std;

bool cmp1(int a, int b) {
	return a < b;
}

bool cmp2(int a, int b) {
	return a > b;
}

void InsertSort(int *src, int n, bool (*cmp)(int, int) = cmp1) {
	int tmp;
	for(int i = 1; i < n; ++i) {
		tmp = src[i];
		int j;
		for(j = i; j > 0 && cmp(tmp, src[j - 1]); --j) {
			src[j] = src[j - 1];
		}
		src[j] = tmp;
	}
}

void PrintArray(int *src, int n) {
	for(int i = 0; i < n; ++i) {
		cout << *(src + i) << " ";
	}
}

int main() {
	int a[5] = { 3, 2, 5, 4, 1 };
	InsertSort(a, 5, cmp2);
	PrintArray(a, 5);
	
	return 0;
}
