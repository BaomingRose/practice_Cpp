#include<iostream>
#include<algorithm>
using namespace std;

int Find(int* a, int n, int toFind) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (toFind > mid) {
			left = mid + 1;
		} else if (toFind < mid) {
			right = mid - 1;
		} else {
			return mid;
		}
	}
	return -1;
}

int main() {
	int a[10] = { 9, 4, 5, 2, 1, 0, 8, 6, 7, 3 };
	sort(a, a + 10);
	for (int i = 0; i < 10; ++i) {
		cout << a[i] << ' ';
	}
	cout << endl;
	cout << Find(a, 10, 0) << endl;
	
	float f[10];
	for (int i = 0; i < 10; ++i) {
		f[i] = (float)rand();
	}
	for (int i = 0; i < 10; ++i) {
		cout << f[i] << endl;
	}
}
