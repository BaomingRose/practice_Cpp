/*================================================
 * description��
 СQ������һ�����г�Ϊ��ת����:
��������n��m, ����n�ܱ�2m����������һ������������������1, 2, 3, 4..., ÿ��m�����ŷ�תһ��, �������Ϊ'-';��
����n = 8, m = 2, ���о���: -1, -2, +3, +4, -5, -6, +7, +8.
��n = 4, m = 1, ���о���: -1, +2, -3, + 4.
СQ����ϣ�����ܰ�������ǰn���Ϊ���١�
=================================================*/
#if 0
//�ҵķ������Ѿ���ȷ������û�й�ʽ������
#include <iostream>
using namespace std;

int main() {
	int n, m;
	while (cin >> n >> m) {
		long long sum = 0;
		long long tmp = 0;
		int flag = -1;
		for (int i = 1; i <= n; ++i) {
			sum += (flag * i);
			++tmp;
			if (tmp == m) {
				tmp = 0;
				flag *= -1;
			}
		}
		cout << sum << endl;
	}

	return 0;
}
#endif

#if 0
//��ʽ��
/*���ȹ۲����У����ǿ��Խ�һ�鸺���������֣��� - 1�� - 2, 3, 4������һ�飬��n����һ����n / (2m)�飬��ÿһ����ͽ��Ϊm*m��
���ǵõ�ǰn��͹�ʽΪSn = n * m*m / 2m = m * n / 2*/
#include<iostream>
using namespace std;
typedef long long LL;

int main() {
	LL n, m;
	cin >> n >> m;
	cout << n * m / 2 << endl;
}
#endif