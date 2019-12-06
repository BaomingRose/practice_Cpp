/*有一个排过序的数组，包含n个整数，但是这个数组向左进行了一定长度的移位,例如，原数组为[1,2,3,4,5,6]，
向左移位5个位置即变成了[6,1,2,3,4,5],现在对于移位后的数组,要查找某个元素的位置.请设计一个复杂度为log级别的算法完成这个任务。
给定一个int数组A，为移位后的数组，同时给定数组大小n和需要查找的元素的值x，请返回x的位置(位置从零开始)。保证数组中元素互异。
*/

/*该题目实际是二分查找的变形，在二分查找的基础上，稍作改变即可，具体方法如下：
在解本次前一定要抓住：数组是经过移位的，那么中间元素的两侧肯定有一边是升序的。
找到数组A中间位置mid，确定目标数 x 在该数的哪一边。 1. 如果x == A[mid]时， 找到了返回mid 2. 
当x大于A[mid]时，分两种情况： 如果数组开头数A[left]大于A[mid]，说明右半边是升序，因为移位之后，
肯定会将大的元素移到左 边，此时，如果x > A[right]时，说明x在mid的左半侧 否则：x位于区间右半侧 3. 
当x小于mid，分两种情况： 如果数组开头元素A[left] < A[mid], 说明左边是有序的，此时如果x < A[left], 
说明x在区间的右半侧 否则：x位于区间左半侧*/

#include <iostream>
#include <vector>
using namespace std;

int findElem(vector<int> A, int n, int tofind) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (A[mid] == tofind) {
			return mid;
		} 
		//寻找单调区间
		//前半部分单调 
		if (A[left] <= A[mid]) {
			if (A[left] <= tofind && tofind < A[mid]) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		} else {	//后半部分单调 
			if (A[mid] < tofind && tofind <= A[right]) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
	}
} 

int main() {
	int a[] = { 6, 1, 2, 3, 4, 5 };
	vector<int> v(a, a + 6);
	
	cout << findElem(v, 6, 1) << endl;
		
	return 0;
}
