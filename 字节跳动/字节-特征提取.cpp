/*=========================================
 * date: 2021/03/03
 * description: �ֽ�����2019���е�����
=========================================*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
 * ���ԣ�pair�ǿ��Խ��бȽϵģ��Ƚϵ�first
 */
void test_pair() {
	pair<int, int> p{ 0, 1 };
	pair<int, int> p2{ 10, 0 };

	cout << (p < p2) << endl;
}

#if 0
int main() {
    int n, m;
    cin >> n;

    int len;
    pair<int, int> xy;

    while (n--) {
        cin >> m;

        int maxCnt = 0;
        map<pair<int, int>, int> preFeaTimes;
        map<pair<int, int>, int> feaTimes;
        while (m--) {
            cin >> len;
            for (int i = 0; i < len; i++) {
                cin >> xy.first >> xy.second;
                
                if (preFeaTimes.count(xy))
                    feaTimes[xy] = preFeaTimes[xy] + 1;
                else
                    feaTimes[xy] = 1;

                if (feaTimes[xy] > maxCnt)
                    maxCnt = feaTimes[xy];
            }
            preFeaTimes.clear();
            preFeaTimes.swap(feaTimes);
        }
        cout << maxCnt << endl;
    }

    return 0;
}
#endif