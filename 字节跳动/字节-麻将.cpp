/*================================================
 * date: 2021/03/03
 * description���ֽ�����2019���е�3�� 
 ����13���ƣ�Ȼ��1��9����Ҫ��Щ�ſ��Ժ�
 ���ƹ�����4��˳�ӻ��߱��ӣ�һ��ͷ��
=================================================*/
#include <iostream>
#include <vector>
using namespace std;

//���������Ϊ��1��9������һ������Ԥ�ȴ�����һ��������
//���뿪ʼ������Ϊ��һ��͵�ģ�������Ҫ��hashead��ʶ��total��ʶ������
bool canHu(vector<int>& arr, int total, bool hasHead) {
	//���û���ˣ���ɹ�����
    if (total == 0) 
		return true;
	//ѡ��ͷ��
    if (!hasHead) {
        for (int i = 1; i <= 9; i++) {
            if (arr[i] >= 2) {
                arr[i] -= 2;
                if (canHu(arr, total - 2, true)) 
					return true;
                arr[i] += 2;
            }
        }
        return false;
    } else {
        for (int i = 1; i <= 9; i++) {
            if (arr[i] > 0) {
                if (arr[i] >= 3) {
                    arr[i] -= 3;
                    if (canHu(arr, total - 3, true)) 
						return true;
                    arr[i] += 3;
                }
                if (i + 2 <= 9 && arr[i + 1] > 0 && arr[i + 2] > 0) {
                    arr[i]--;
                    arr[i + 1]--;
                    arr[i + 2]--;
                    if (canHu(arr, total - 3, true)) 
						return true;
                    arr[i]++;
                    arr[i + 1]++;
                    arr[i + 2]++;
                }
            }
        }
    }
    return false;
}

int main() {
    while (1) {
        vector<int> v(10, 0);
        for (int i = 0; i < 13; ++i) {
            int tmp;
            cin >> tmp;
            v[tmp]++;
        }
        vector<int> res;
        for (int i = 1; i <= 9; ++i) {
            vector<int> cur = v;
            cur[i]++;
            if (canHu(cur, 14, false)) {
                res.push_back(i);
            }
        }
		if (res.size() == 0) {
			cout << 0 << endl;
		} else {
			for (const auto& e : res) {
				cout << e << " ";
			}
			cout << endl;
		}
    }
    
    return 0;
}