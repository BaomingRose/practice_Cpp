/*Fibonacci��������������ģ�
F[0] = 0
F[1] = 1
for each i �� 2: F[i] = F[i-1] + F[i-2]
��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...����Fibonacci�����е������ǳ�ΪFibonacci����
����һ��N�����������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX-1����X+1�����ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����
*/

/*
�������ͨ�����ҵ�����N���������Fibonacci�������������ֱ�ȡ�Ծ���N����������һ��
��L���ұ�һ����R��Ȼ��ͨ��min(N - L, R - N)�ҵ���С����
*/

#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int input;
	cin >> input;
	int f0 = 0, f1 = 1;
	int f2 = f0 + f1;
	
	while (1) {
		if (input == f1) {
			cout << 0 << endl;
			break;
		} else if (f2 > input) {
			if (abs(f2 - input) > abs(input - f1)) {
				cout << abs(input - f1) << endl;
				break;
			} else {
				cout << abs(f2 - input);
				break;
			}
		}
		f0 = f1;
		f1 = f2;
		f2 = f1 + f0;
	}
	
	
	return 0;
} 
