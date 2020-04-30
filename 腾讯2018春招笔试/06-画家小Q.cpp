/*================================================
 * description��
����СQ�ֿ�ʼ��������������СQ�ó���һ����NxM���ظ�Ļ���, �����ʼ״̬�ǿհ׵�,��'X'��ʾ��
СQ�������صĻ滭����,ÿ��СQ��ѡ��һ��б��, ���б�ߵķ�������'/',��б��Ϊ1,СQ��ѡ������б���е�һ�θ���,��Ϳ��Ϊ��ɫ,��'B'��ʾ;����Խ��ߵķ�������'\',��б��Ϊ-1,СQ��ѡ������б���е�һ�θ���,��Ϳ��Ϊ��ɫ,��'Y'��ʾ��
���һ�����Ӽȱ���ɫͿ�����ֱ���ɫͿ����,��ô������Ӿͻ�����ɫ,��'G'��ʾ��
СQ�Ѿ����뻭������Ʒ������, �����������һ����������Ҫ���ٴβ�������������

ÿ��һ��׷��������ʣ�ͬʱ���Ѿ�����ĳ����ɫ�ĸ���Ԫ������Ϊ��һ����Ҫ������ɫ����ԭY����Y��һ������Ҫ�ٻ�����ΪX.
=================================================*/
//δ����
#include <iostream>
#include <vector>
using namespace std;

void painterQ(vector<vector<char>>& painter, int& x, int& y, char mode) {
	int N = painter.size();
	int M = painter[0].size();

	if (mode == 'B') {
		for (int i = x, j = y; i >= 0 && j < M; i--, j++) {
			if (painter[i][j] == 'B') {
				painter[i][j] = 'X';
			} else if (painter[i][j] == 'G') {
				painter[i][j] = 'Y';
			} else {
				break;
			}
		}

		for (int i = x + 1, j = y - 1; i < N && j >= 0; i++, j--) {
			if (painter[i][j] == 'B') {
				painter[i][j] = 'X';
			} else if (painter[i][j] == 'G') {
				painter[i][j] = 'Y';
			} else {
				break;
			}
		}
	} else {
		for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
			if (painter[i][j] == 'Y') {
				painter[i][j] = 'X';
			} else if (painter[i][j] == 'G') {
				painter[i][j] = 'B';
			} else {
				break;
			}
		}

		for (int i = x + 1, j = y + 1; i < N && j < M; i++, j++) {
			if (painter[i][j] == 'Y') {
				painter[i][j] = 'X';
			} else if (painter[i][j] == 'G') {
				painter[i][j] = 'B';
			} else {
				break;
			}
		}
	}

}

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<char>> painter(N, vector<char>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> painter[i][j];
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (painter[i][j] == 'X') {
				continue;
			} else if (painter[i][j] == 'B') {
				result++;
				painterQ(painter, i, j, 'B');
			} else if (painter[i][j] == 'Y') {
				result++;
				painterQ(painter, i, j, 'Y');
			} else {
				result++;
				painterQ(painter, i, j, 'B');
				result++;
				painterQ(painter, i, j, 'Y');
			}
		}
	}
	cout << result << endl;
}