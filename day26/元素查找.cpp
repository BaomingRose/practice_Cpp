/*��һ���Ź�������飬����n����������������������������һ�����ȵ���λ,���磬ԭ����Ϊ[1,2,3,4,5,6]��
������λ5��λ�ü������[6,1,2,3,4,5],���ڶ�����λ�������,Ҫ����ĳ��Ԫ�ص�λ��.�����һ�����Ӷ�Ϊlog������㷨����������
����һ��int����A��Ϊ��λ������飬ͬʱ���������Сn����Ҫ���ҵ�Ԫ�ص�ֵx���뷵��x��λ��(λ�ô��㿪ʼ)����֤������Ԫ�ػ��졣
*/

/*����Ŀʵ���Ƕ��ֲ��ҵı��Σ��ڶ��ֲ��ҵĻ����ϣ������ı伴�ɣ����巽�����£�
�ڽⱾ��ǰһ��Ҫץס�������Ǿ�����λ�ģ���ô�м�Ԫ�ص�����϶���һ��������ġ�
�ҵ�����A�м�λ��mid��ȷ��Ŀ���� x �ڸ�������һ�ߡ� 1. ���x == A[mid]ʱ�� �ҵ��˷���mid 2. 
��x����A[mid]ʱ������������� ������鿪ͷ��A[left]����A[mid]��˵���Ұ����������Ϊ��λ֮��
�϶��Ὣ���Ԫ���Ƶ��� �ߣ���ʱ�����x > A[right]ʱ��˵��x��mid������ ����xλ�������Ұ�� 3. 
��xС��mid������������� ������鿪ͷԪ��A[left] < A[mid], ˵�����������ģ���ʱ���x < A[left], 
˵��x��������Ұ�� ����xλ����������*/

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
		//Ѱ�ҵ�������
		//ǰ�벿�ֵ��� 
		if (A[left] <= A[mid]) {
			if (A[left] <= tofind && tofind < A[mid]) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		} else {	//��벿�ֵ��� 
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
