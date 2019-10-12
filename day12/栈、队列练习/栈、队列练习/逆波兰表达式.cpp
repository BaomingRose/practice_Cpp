/*根据逆波兰表示法，求表达式的值。
有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。*/

#include<iostream>
#include<cstdlib>
#include<stack>
#include<vector>
#include<string>
#include<cctype>
using namespace std;

int evalRPN(vector<string> &tokens) {
	stack<int> tmp;
	int a, b;
	for (auto & vsi : tokens) {
		if (isdigit(vsi[0]) || vsi.size() > 1) {
			tmp.push(atoi(vsi.c_str()));
		} else {
			a = tmp.top();
			tmp.pop();
			b = tmp.top();

			switch (vsi[0]) {
			case '+':
				tmp.top() = b + a;
				break;
			case '-':
				tmp.top() = b - a;
				break;
			case '*':
				tmp.top() = b * a;
				break;
			case '/':
				tmp.top() = b / a;
				break;
			}
		}
	}
	return tmp.top();
}

int main() {
	vector<string> vs{ "10", "6", "9", "3", "+", "-11", "*", "/" , "*", "17", "+", "5", "+" };
	cout << evalRPN(vs) << endl;
	return 0;
}