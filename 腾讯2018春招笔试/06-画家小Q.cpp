/*================================================
 * description：
画家小Q又开始他的艺术创作。小Q拿出了一块有NxM像素格的画板, 画板初始状态是空白的,用'X'表示。
小Q有他独特的绘画技巧,每次小Q会选择一条斜线, 如果斜线的方向形如'/',即斜率为1,小Q会选择这条斜线中的一段格子,都涂画为蓝色,用'B'表示;如果对角线的方向形如'\',即斜率为-1,小Q会选择这条斜线中的一段格子,都涂画为黄色,用'Y'表示。
如果一个格子既被蓝色涂画过又被黄色涂画过,那么这个格子就会变成绿色,用'G'表示。
小Q已经有想画出的作品的样子, 请你帮他计算一下他最少需要多少次操作完成这幅画。

每画一步追求最大连笔，同时将已经画了某种颜色的格子元素设置为下一步需要画的颜色，如原Y画了Y下一步不需要再画设置为X.
=================================================*/
//未作答
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