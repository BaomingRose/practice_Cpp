/*输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring> 
using namespace std;
void PermutaCore(char* pstr, char* pBegin, vector<string>& vs);
#include <algorithm>
//这套代码很灵活的应用了algorithm，使用了sort、unique、swap 

vector<string> Permutation(string str) {
    vector<string> res;
    if (str.empty())
        return res;
    char* pstr = new char[str.length() + 1];
    memset(pstr, 0, str.length() + 1);
    strcpy(pstr, str.c_str());
    PermutaCore(pstr, pstr, res);
    
    //接下来这两个代码很重要，uniqueunique函数是一个去重函数，去除相邻中的重复元素（只留一个）。
	//其中，最关键的是：并不是删除并不是把重复的元素删除，而是全部放倒数组的后面。 
	//unique()函数将重复的元素放到vector的尾部 然后返回指向第一个重复元素的迭代器 
	//再用erase函数擦除从这个元素到最后元素的所有的元素
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    
    return res;
}

//这个递归也是关键， 使用了回溯，每次将后面的字符与第一个字符交换 
void PermutaCore(char* pstr, char* pBegin, vector<string>& vs) {
    if (*pBegin == '\0')
        vs.push_back(pstr);
    else
        for (char* pch = pBegin; *pch != '\0'; ++pch) {
            swap(*pch, *pBegin);
            PermutaCore(pstr, pBegin + 1, vs);
            swap(*pch, *pBegin);
        }
}

int main() {
	string str;
	while (cin >> str) {
		vector<string> vs = Permutation(str);
		for (int i = 0; i < vs.size(); ++i) {
			cout << vs[i] << endl;
		}
	}
	
	return 0;
}

