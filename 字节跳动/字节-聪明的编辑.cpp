/*================================================
 * date: 2021/03/03
 * description���ֽ�����2019���е�1�� 
 ������Ĺ������ַ�������������޸ģ��������������ַ���ͬ�����Լ����������ַ���ͬ
 ��Ҫ˼·��״̬���л��������ڸ����ܷ�����������״̬���ǽ�
=================================================*/

#include <iostream>
#include <string>
using namespace std;

string deal_str(const string& s) {
    if (s.size() <= 2) {
        return s;
    }
    string res;
    res = s.substr(0, 2);
    //res��������ַ�������״̬��0��ȫ��һ����1��������һ����2��ǰ����һ��
    int state = 0;
    if (res[0] == res[1]) {
        state = 1;
    }
    for (int i = 2; i < s.size(); ++i) {
        //���Ҫpush���ַ���res�����һ�����
        if (s[i] == res[res.size() - 1]) {
            if (state == 0) {
                res.push_back(s[i]);
                state = 1;
            } else if (state == 1) {
                continue;
            } else if (state == 2) {
                
            }
        } else {
            res.push_back(s[i]);
			cout << state << endl;
            if (state == 1) {
                state = 2;
            } else if (state == 2) {
                state = 0;
            } else if (state == 0) {
                continue;
            }
        }
    }
    return res;
}

#if 0
int main() {
    int n;
    while (cin >> n) {
        cin.get();
        for (int i = 0; i < n; ++i) {
            string s;
            getline(cin, s);
            cout << deal_str(s) << endl;
        }
    }
    
    return 0;
}
#endif