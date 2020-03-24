#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string longestCommonString(string s1, string s2) {
    if (s1.size() > s2.size()) 
        swap(s1, s2);
    int len1 = s1.size();
    int len2 = s2.size();
    int max = 0;
    int start = 0;
    vector<vector<int> > vv(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (s1[i - 1] == s2[j - 1])
                vv[i][j] = vv[i - 1][j - 1] + 1;
             //cout << v[i][j];
            if (vv[i][j] > max) {
                max = vv[i][j];
                //记录前面相同的开始位置 
                start = i - max;
            }
        }
        //cout << endl;
    }
    string res = s1.substr(start, max);
    return res;
}

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        cout << longestCommonString(s1, s2) << endl;
    }
    
    return 0;
}
