/*================================================
 * date: 2021/03/03
 * description：字节跳动2019春招第1题 
 这题给的规则，是字符串进行冗余的修改，不让连着三个字符相同，‘以及连续两对字符相同
 主要思路是状态的切换，得益于高性能服务器开发中状态机那节
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
    //res最后三个字符的三种状态：0、全不一样；1、后两个一样；2、前两个一样
    int state = 0;
    if (res[0] == res[1]) {
        state = 1;
    }
    for (int i = 2; i < s.size(); ++i) {
        //如果要push的字符和res的最后一个相等
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