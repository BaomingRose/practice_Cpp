#if 0
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack<int> st;
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			//��������֣���push
			if (s[0] >= '0' && s[0] <= '9') {
				int num = 0;
				num = stoi(s);
				st.push(num);
			}
			else {    //�������֣���ջ���������ó����㣬������Ҫpush��ջ��
				int x = st.top();
				st.pop();
				int y = st.top();
				st.pop();
				if (s == "+")
					st.push(x + y);
				else if (s == "-")
					st.push(y - x);
				else if (s == "*")
					st.push(x * y);
				else if (s == "/")
					st.push(y / x);
			}
		}
		//������ջ��Ԫ��
		cout << st.top() << endl;
	}
	return 0;
}
#endif
