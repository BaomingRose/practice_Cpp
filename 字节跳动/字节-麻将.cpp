/*================================================
 * date: 2021/03/03
 * description：字节跳动2019春招第3题 
 是有13张牌，然后1～9还需要哪些张可以胡
 胡牌规则是4个顺子或者豹子，一对头牌
=================================================*/
#include <iostream>
#include <vector>
using namespace std;

//这个深搜因为从1～9都是下一步，是预先处理下一步的深搜
//进入开始步，因为有一对偷拍，所以需要用hashead标识，total标识总牌数
bool canHu(vector<int>& arr, int total, bool hasHead) {
	//如果没有了，则成功胡牌
    if (total == 0) 
		return true;
	//选个头牌
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