//��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing. �����������Ϊ��beijing. like I

/*����˼·1��
�Ƚ������ַ������ù������ٱ����ַ������ҳ�ÿ�����ʣ��Ե������á���������ʹ����stl�㷨�е�
reverse����������ʹ�õ���������string*/

#if 0
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	string s;
	// ע������Ҫʹ��getline��cin>>s�����ո�ͽ��ս�����
	getline(cin, s);
	// ��ת��������
	reverse(s.begin(), s.end());
	// ��ת����
	string::iterator start = s.begin();
	while (start != s.end())
	{
		string::iterator end = start;
		while (end != s.end() && *end != ' ')
			end++;
		reverse(start, end);
		if (end != s.end())
			start = end + 1;
		else
			start = end;
	}
	cout << s << endl;
	return 0;
}
#endif

/*�ڶ�˼·��һ���Ƚ����ɵ�˼·��ֱ������cin>>s�������룬�����ո�ͽ����ˣ���Ȼ�ͷָ��ÿ�����ʣ�
��ν�ÿ�ν��յ��ĵ���ƴ�ӵ�֮ǰ����ǰ������ù�����*/

#include <iostream>
#include <string>
using namespace std;
// cin��ȡstringʱ�Զ��ᱻ�ո�ָ���������һ���ַ����洢�����������
int main() {
	string s1, s2;
	cin >> s2;
	while (cin >> s1)
		s2 = s1 + " " + s2;
	cout << s2 << endl;
	return 0;
}
