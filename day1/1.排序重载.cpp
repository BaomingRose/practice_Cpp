//1、写一个排序函数接口，能完成对整数和小数的排序。 

#include<iostream>
using namespace std;

void InsertSort(int *src, int n) {
	int tmp;
	for(int i = 1; i < n; ++i) {
		tmp = src[i];
		int j;
		for(j = i; j > 0 && src[j - 1] > tmp; --j) {
			src[j] = src[j - 1];
		}
		src[j] = tmp;
	}
}

void InsertSort(double *src, int n) {
	double tmp;
	for(int i = 1; i < n; ++i) {
		tmp = src[i];
		int j;
		for(j = i; j > 0 && src[j - 1] > tmp; --j) {
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

void PrintArray(double *src, int n) {
	for(int i = 0; i < n; ++i) {
		cout << *(src + i) << " ";
	}
}

int main() {
	int a[5] = { 5, 3, 2, 4, 1};
	double b[5] = { 3.2, 1.8, 4.9, 5.3, 2.7 };
	InsertSort(a, 5);
	InsertSort(b, 5);
	PrintArray(a, 5);
	cout << endl;
	PrintArray(b, 5);
	
	return 0;
}
