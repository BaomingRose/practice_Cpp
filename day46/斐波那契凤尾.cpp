#if 0
// write your code here cpp
#include <iostream>
#include <cstdio>
using namespace std;

unsigned int fab[100001];

void fillFab() {
	fab[0] = 0;
	fab[1] = 1;
	fab[2] = 2;
	for (int i = 3; i <= 100000; ++i) {
		fab[i] = fab[i - 1] + fab[i - 2];
		//因为每个都保留6位数不影响后面的加法
		fab[i] %= 1000000;
	}
}


int main() {
	fillFab();
	int n;
	while (cin >> n) {
		unsigned int result = fab[n];
		cout << result << endl;
	}

	return 0;
}
#endif