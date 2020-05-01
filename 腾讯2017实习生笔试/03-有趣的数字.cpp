/*================================================
 * description��
СQ�������ϲ���ʱ�뵽��������⣺��n������������ɶ�Ԫ�飬�����С���ж��ٶ��أ��������أ�
=================================================*/
//��sort����һ�£�������ظ��ģ���ô��С�϶����ظ��ģ����ж����顣
//���϶������ֵ�ĸ���*��Сֵ�ĸ���
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int *a = new int[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		sort(a, a + n);

		int min = a[n - 1] - a[0];
		int max = a[n - 1] - a[0];
		int min_count = 0;
		int max_count = 0;

		//�ҵ���С��ֵ
		for (int i = 1; i < n; i++)
			if (min > a[i] - a[i - 1])
				min = a[i] - a[i - 1];

		//�������ȫ�����
		if (a[0] == a[n - 1]) {
			max_count = n * (n - 1) / 2;
		} else {
			int first = 0;
			int last = 0;
			//ͳ�����ֵ����Сֵ�ĸ���
			for (int i = 0; i < n; i++) {
				if (a[i] == a[0])
					first++;
				if (a[i] == a[n - 1])
					last++;
			}
			max_count = first * last;
		}

		//�����СֵΪ0������ȵ�ֵ����
		if (min == 0) {
			//�������Ҳ�����ֵ��ȵģ���ôû���뵽��һֱ��ʹ����Ϲ�ʽ�ˣ���������
			for (int i = 0; i < n; i++) {
				int j = i + 1;
				while (j < n) {
					if (a[i] == a[j])
						min_count++;
					j++;
				}
			}
		} else {
			for (int i = 1; i < n; i++)
				if (min == a[i] - a[i - 1])
					min_count++;
		}

		cout << min_count << " " << max_count << endl;

	}
}