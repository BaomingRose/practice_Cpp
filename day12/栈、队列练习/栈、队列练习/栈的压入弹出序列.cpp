#if 0
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
����ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
��4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�*/

bool IsPopOrder(const vector<int> &pushV, const vector<int> &popV) {
	//��ջ�ͳ�ջ��Ԫ�ظ���������ͬ
	if (pushV.size() != popV.size())
		return false;

	stack<int> st;
	int i = 0;

	//����pushV
	for (int iv = 0; iv < pushV.size(); ++iv) {
		st.push(pushV[iv]);
		//!st.empty()�ı�Ҫ�� ������
		while (!st.empty() && st.top() == popV[i]) {
			st.pop();
			++i;
		}
	}
	return st.empty();
}

int main() {
	int a[] = { 1, 2, 3, 4, 5 };
	int b[] = { 4, 3, 5, 1, 2 };
	vector<int> pushV(a, a + 5);
	vector<int> popV(b, b + 5);
	cout << IsPopOrder(pushV, popV) << endl;
	return 0;
}
#endif