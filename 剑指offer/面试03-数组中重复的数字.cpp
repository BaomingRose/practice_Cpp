#if 0 
#include <iostream>
using namespace std;

bool duplicate(int* numbers, int length, int* duplication) {
	if (numbers == NULL || length <= 0) {
		return false;
	}
	
	for (int i = 0; i < length; ++i) {
		if (numbers[i] < 0 || numbers[i] > length - 1) 
			return false;
	}
	
	for (int i = 0; i < length; ++i) {
		while (numbers[i] != i) {
			//占了别人的坑，如果自己应该的坑位还是自己就是重复的 
			if (numbers[i] == numbers[numbers[i]]) {
				*duplication = numbers[i];
				//找到一个就返回了 
				return true;
			}
			
			//如果不等，就回到自己的坑位 
			swap(numbers[i], numbers[numbers[i]]);
		}
	}
	
	return false; 
}

int main() {
	int arr[6] = { 1, 2, 4, 3, 2, 5 };
	int res = 0;
	if (duplicate(arr, 6, &res)) {
		cout << res << endl;
	}
	
	return 0;
}
#endif

#include <iostream>
using namespace std;

int countRange(const int* numbers, int length, int start, int end) {
	if (numbers == NULL) 
		return 0;
		
	int count = 0;
	for (int i = 0; i < length; ++i)
		if (numbers[i] >= start && numbers[i] <= end)
			++count;
		return count;
}

int getDuplication(const int* numbers, int length) {
	if (numbers == NULL || length <= 0) 
		return -1;
	
	int start = 1;
	int end = length - 1;
	while (end >= start) {
		int middle = ((end - start) >> 1) + start;
		int count = countRange(numbers, length, start, middle);
		if (end == start) {
			if (count > 1) 
				return start;
			else 
				break;
		}
		
		if (count > (middle - start + 1))
			end = middle;
		else
			start = middle + 1;
	} 
	return -1;
}

int main() {
	int arr[6] = { 1, 2, 4, 3, 2, 5 };
	int res = getDuplication(arr, 6);
	
	cout << res << endl;
	
	return 0;
}
