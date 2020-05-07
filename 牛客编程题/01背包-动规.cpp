/*================================================
 * description��
 �� n ����Ʒ��һ����СΪ m �ı���. �������� A ��ʾÿ����Ʒ�Ĵ�С������ V ��ʾÿ����Ʒ�ļ�ֵ.
�������װ�뱳�����ܼ�ֵ�Ƕ��?
���Ķ��湫ʽ��
		int newValue = result[j - A[i]] + V[i];
		result[j] = max(newValue, result[j]);
=================================================*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/* ������
 * m : ������С
 * A : ��Ʒ��С
 * V : ��Ʒ��ֵ
*/

#if 0
int backPackII(int m, vector<int> A, vector<int> V) {
	if (A.empty() || V.empty() || m < 1) {
		return 0;
	}

	//���һ��һ�У��������ó�ʼ����
	const int N = A.size() + 1;
	const int M = m + 1;
	vector<vector<int> > result(N, vector<int>(M, 0));

	for (int i = 1; i < N; ++i) {
		for (int j = 1; j != M; ++j) {
			//��i����Ʒ��A�ж�Ӧ������Ϊi-1: i��1��ʼ
			//�����i����Ʒ����j,˵���Ų��£� ����(i,j)������ֵ��(i-1,j)��ͬ
			if (A[i - 1] > j) {
				result[i][j] = result[i - 1][j];
			}
			//�������װ�£������������װ���߲�װ
			//�����װ����Ϊ(i-1, j)
			//���װ����Ҫ�ڳ��ŵ�i����Ʒ��С�Ŀռ䣺 j - A[i-1],װ��֮�������ֵ��Ϊ(i - 1,j - A[i - 1]) + ��i����Ʒ�ļ�ֵV[i - 1]
				//�����װ�벻װ��ѡ�����ļ�ֵ
			else {
				int newValue = result[i - 1][j - A[i - 1]] + V[i - 1];
				result[i][j] = max(newValue, result[i - 1][j]);
			}
		}
	}
	//����װ��ǰN����Ʒ����Ʒ��СΪm������ֵ
	return result[N - 1][m];
}
#endif

//�Ż�
int backPackII(int m, vector<int> A, vector<int> V) {
	if (A.empty() || V.empty() || m < 1) {
		return 0;
	}

	const int N = A.size();
	//���һ�У��������ó�ʼ��������Ϊ��һ����ƷҪ�õ�ǰ��ĳ�ʼֵ
	const int M = m + 1;
	vector<int> result(M, 0);

	//������Ʒ������λ�ò���Ҫƫ�ƣ�Ҫ��δ�Ż��ķ������ֿ�
	//�����i-1���Ϊ��һ�У�����δ���µ�һά����ֵ
	for (int i = 0; i != N; ++i) {
		for (int j = M - 1; j > 0; --j) {
			//�����i����Ʒ����j,˵���Ų��£� ����(i,j)������ֵ��(i-1,j)��ͬ

			//�������װ�£������������װ���߲�װ
			//�����װ����Ϊ(i-1, j)
			//���װ����Ҫ�ڳ��ŵ�i����Ʒ��С�Ŀռ䣺 j - A[i],װ��֮�������ֵ��Ϊ(i - 1, j - A[i - 1]) + ��i����Ʒ�ļ�ֵV[i]
			//�����װ�벻װ��ѡ�����ļ�ֵ
			if (A[i] <= j) {
				int newValue = result[j - A[i]] + V[i];
				result[j] = max(newValue, result[j]);
			}
		}
	}
	//����װ��ǰN����Ʒ����Ʒ��СΪm������ֵ
	return result[m];
}

int main() {
	int m = 10;
	vector<int> A{ 2, 3, 5, 7 };
	vector<int> V{ 1, 5, 2, 4 };

	cout << backPackII(m, A, V) << endl;

	return 0;
}