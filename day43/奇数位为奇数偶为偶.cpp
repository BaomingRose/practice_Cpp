/*
����һ�����Ȳ�С��2������arr�� 
дһ����������arr��ʹarr��Ҫô���е�ż��λ�϶���ż����Ҫô���е�����λ�϶��������ϡ� 
Ҫ��������鳤��ΪN��ʱ�临�Ӷ���ﵽO(N)������ռ临�Ӷ���ﵽO(1),�±�0,2,4,6...����ż��λ,�±�1,3,5,7...��������λ��
����[1,2,3,4]����Ϊ[2,1,4,3]���ɡ� 
*/

//��ż��λ��Ѱ�ҷ�ż����������λ��Ѱ�ҷ��������������ֽ���λ�û�������

#include <iostream>
#include <vector>
using namespace std;

void oddInOddEvenInEven(vector<int>& arr, int len) {
	long i = 0, j = 1;
	while(i < len && j < len) {
		if((arr[i] % 2) == 0) { //ż��λ��Ѱ�ҷ�ż��
			i += 2; 
			continue; 
		}
		if((arr[j] % 2) != 0) { //����λ��Ѱ�ҷ�����
			j += 2; 
			continue; 
		}
		swap(arr[i], arr[j]);
	}
}

int main() {
	int a[] = { 1, 2, 3, 4 };
	vector<int> v;
	for (int i = 0; i < 4; ++i) {
		v.push_back(a[i]);
	}
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
	oddInOddEvenInEven(v, v.size());
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
	
	return 0;
}
