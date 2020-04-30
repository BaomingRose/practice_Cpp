/*================================================
 * description��
ţţ������������һ��ֽ����Ϸ�������Ϸһ����n��ֽ��, ��i��ֽ����д������ai��
ţţ��������������, ţţ�ȳ�, ÿ�γ������ǿ��Դ�ֽ�ƶ�������ѡ��һ�ų��, ֱ��ֽ�Ʊ����ꡣ
���ǵĵ÷ֵ������ǳ鵽��ֽ�������ܺ͡�
���ڼ���ţţ�����򶼲������Ų���, ����������Ϸ������ţţ�÷ּ�ȥ����÷ֵ��ڶ��١�
=================================================*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		multiset<int, greater<int>> s;
		int tmp;
		for (int i = 0; i < n; ++i) {
			cin >> tmp;
			s.insert(tmp);
		}
		int sum_niu = 0;
		int sum_yang = 0;
		bool flag = true;
		for (const auto& e : s) {
			if (flag == true) {
				sum_niu += e;
			}
			else {
				sum_yang += e;
			}
			flag = !flag;
		}
		cout << sum_niu - sum_yang << endl;
	}

	return 0;
}