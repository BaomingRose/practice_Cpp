/*================================================
 * date: 2021/03/03
 * description���ֽ�����2019���е�2��
 һ�����飬����ѡ����������������������󳤶Ȳ��ܳ���D
 ˼·��ʹ�û������ں���ϣ��������ײ���ѡ��Ȼ����������ѡ���� 
=================================================*/
#include <iostream>
#include <vector>
using namespace std;

//�����ֵC(n, 2)
long long int C_n_2(long long int n) {
    return n * (n - 1) / 2;
}

int count_scheme(const vector<int>& v, int D) {
    int left = 0;
    long long int res = 0;
    int right = 0;
    while (left < v.size()) {
        //�������ƶ���ָ��
        while (right < v.size() && v[right] - v[left] <= D) {
            ++right;
        }
        //��ָ��ͣ����
        if (right - left >= 2)
            res = (res + C_n_2(right - left - 1)) % 99997867;
        //��ָ�붯
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