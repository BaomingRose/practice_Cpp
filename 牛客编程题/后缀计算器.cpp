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
			//如果是数字，就push
			if (s[0] >= '0' && s[0] <= '9') {
				int num = 0;
				num = stoi(s);
				st.push(num);
			}
			else {    //不是数字，则将栈的两个数拿出运算，运算结果要push到栈中
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
		//最后输出栈顶元素
		cout << st.top() << endl;
	}
	return 0;
}
#endif
