/*题目描述
对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。

给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。
*/

/*用栈结构实现，栈中存放左括号，当遇到右括号之后，检查栈中是否有左括号，如果有则出栈，
如果没有，则说明不匹配*/

bool chkParenthesis(string A, int n) {
	// write code here
	stack<char> sc;
	for (auto ele : A) {
		switch (ele) {
		case '(':
			sc.push(ele);
			break;
		case ')': {
			if (sc.empty() || sc.top() != '(')
				return false;
			else
				sc.pop();
			}
		break;
		default:
			return false;
		}
	} 
	return true;
}
