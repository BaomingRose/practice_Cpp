#include<iostream>
#include<string>
using namespace std;

int myAtoi(string str) {
    long long res = 0;
    int i = 0;
    int flag = 1;
    while (i < str.size() && str[i] == ' ') {
        ++i;
    }
    if (i == str.size()) return 0;
    if (str[i] == '-') {
        flag = -1;
        ++i;
    } else if (str[i] == '+') {
        ++i;
    }
    while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
		res = res * 10 + str[i++] - '0';
		if (res > INT_MAX) {
				if (flag == 1)
	                return INT_MAX;
				else 
	                return INT_MIN;
  		}
	}
    return res * flag;
}

int main() {
	string s = "    -39";
	string s2 = "2147483648";	
	int res = myAtoi(s);
	int res2 = myAtoi(s2);		//2147483647
	cout << res << endl << res2;
}

