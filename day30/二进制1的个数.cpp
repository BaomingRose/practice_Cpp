//计算整数二进制中1的个数

//不能忽略负数 

#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int count = 0;
        while (n) {
            if (n & 1 == 1) {
                ++count;
            }
            n >>= 1;
        }
        cout << count << endl;
    }
}
