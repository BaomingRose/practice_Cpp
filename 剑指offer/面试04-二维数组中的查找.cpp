#include <iostream>
using namespace std;

//从右上角开始找 
bool Find(int* arr, int rows, int colums, int tofind) {
	int i = 0, j = colums - 1;
	while (i < rows && j >= 0) {
		if (arr[i * colums + j] == tofind)
			return true;
		else if (arr[i * colums + j] < tofind)
			++i;
		else
			--j;
	}
	return false;
}

int main() {
	int arr[4][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	int* ptr = (int*)arr;
	if (Find(ptr, 4, 4, 15)) {
		cout << "Find success!" << endl;
	}
	else {
		cout << "Not Find!" << endl;
	}
}
