/*================================================
 * description��
 СQ����ĩ��ʱ�������С�����������й�֣�һ�����н����кܶ��¥������n����¥�ų�һ�С�
СQ�ӵ�һ��һֱ�ߵ������һ����СQ������û�м�����ô���¥����������֪������ÿ��¥��λ�ô��ܿ������ٶ�¥�أ�
����ǰ���¥�ĸ߶ȴ��ڵ��ں����¥ʱ�������¥������ס��
=================================================*/
#if 1
//����ջ
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

//a��ʾ�������ĸ�����b��ʾ�ұ�����ĸ���(�Ӻ���ǰ������Ҫ��ת)
vector<int> a, b;
//st1��ʾ��ߵ�����ջ��st2��ʾ�ұߵ�����ջ
stack<int> st1, st2;

int main() {
	int n, x[100001];
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) 
		cin >> x[i];

	for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
		a.push_back(st1.size());
		b.push_back(st2.size());

		//���ջ��С����һ������pop������ջ������
		while (!st1.empty() && st1.top() <= x[i])
			st1.pop();
		while (!st2.empty() && st2.top() <= x[j]) 
			st2.pop();
		st1.push(x[i]);
		st2.push(x[j]);
	}

	reverse(b.begin(), b.end());

	for (int i = 0; i < n; i++) 
		cout << b[i] + a[i] + 1 << " ";

	return 0;
}
#endif