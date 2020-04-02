/*输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。*/

//按照给定排序方式字符串排序（排序是重点，方式更是重点），给字符串排序即可（重要） 
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
	//在oj里这是一个类里，作为成员函数会自动传入this，所以要声明未静态函数 
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
