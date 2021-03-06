/*================================================
 * date: 2021/03/03
 * description：字节跳动2019春招第2题
 一个数组，任意选三个，其中任意两个的最大长度不能超过D
 思路：使用滑动窗口和组合，窗口中首部必选，然后其他任意选两个 
=================================================*/
#include <iostream>
#include <vector>
using namespace std;

//求组合值C(n, 2)
long long int C_n_2(long long int n) {
    return n * (n - 1) / 2;
}

int count_scheme(const vector<int>& v, int D) {
    int left = 0;
    long long int res = 0;
    int right = 0;
    while (left < v.size()) {
        //先正常移动右指针
        while (right < v.size() && v[right] - v[left] <= D) {
            ++right;
        }
        //右指针停下来
        if (right - left >= 2)
            res = (res + C_n_2(right - left - 1)) % 99997867;
        //左指针动
        ++left;
    }
    return res;
}

#if 0
int main() {
    int n, D;
    while (cin >> n >> D) {
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        
        cout << count_scheme(v, D) << endl;
    }
    
    return 0;
}
#endif