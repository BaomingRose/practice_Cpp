/*��Ŀ����
����һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ���

����һ���ַ���A�����ĳ���n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���
*/

/*��ջ�ṹʵ�֣�ջ�д�������ţ�������������֮�󣬼��ջ���Ƿ��������ţ���������ջ��
���û�У���˵����ƥ��*/

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
