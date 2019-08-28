/*2.�ӿ��жഫ��һ��ȱʡ����,�����ָ��,�Ͳ���A����ʽ, ���ָ����,�Ͱ�����ѡ���������ʽ(���ٰ�������)*/

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
