/*����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��*/

//���ո�������ʽ�ַ��������������ص㣬��ʽ�����ص㣩�����ַ������򼴿ɣ���Ҫ�� 
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
	//��oj������һ�������Ϊ��Ա�������Զ�����this������Ҫ����δ��̬���� 
    static bool cmp(const string& s1, const string& s2) {
        auto s1_it = s1.begin();
        auto s2_it = s2.begin();
        
        while (s1_it != s1.end() && s2_it != s2.end()) {
            if (*s1_it > *s2_it)
                return false;
            else if (*s1_it < *s2_it)
                return true;
            else {
                s1_it++;
                s2_it++;
            }
        }
        if (s1_it == s1.end() && s2_it == s1.end())
            return true;
        if (s1_it == s1.end())
            return (*s2_it > (*s2_it - 1));
        else 
            return (*s1_it > (*s1_it - 1));
    }
    
    string PrintMinNumber(vector<int> numbers) {
        vector<string> sv(numbers.size());
        for (size_t i = 0; i < numbers.size(); ++i) {
            string tmp = to_string(numbers[i]);
            sv[i] = tmp;
        }
        sort(sv.begin(), sv.end(), cmp);
        string res;
        for (const auto& str : sv) {
            res += str;
        }
        return res;
    }
};

int main() {
	Solution s;
	int arr[] = { 3, 32, 321 };
	vector<int> v(arr);
	string str = s.PrintMinNumber(v);  
	cout << str << endl;	
	return 0;
} 
