//�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�

/* 
��һ�������ÿһ��λ�ñ�ʾ��Ӧ��λ�á���Ӧ���ַ�λ�ô���ַ����ֵĴ�����ͳ����֮�󣬱���������
����������һ��ֻ����һ�ε��ַ���ֹͣ
*/

#include <string>
#include <iostream>
using namespace std;

int main() {
	string s;
	while(cin>>s) {
		int hashtable[256] = {0};
		for(auto& e : s) {
			hashtable[e]++;
		} 
		int i;
		for(i = 0; i < s.size(); i++) {
			if(hashtable[s[i]] == 1) {
				cout<<s[i]<<endl;
				break;
			}
		} 
		if(i >= s.size())
		cout<<-1<<endl;
	} 
	return 0;
}
