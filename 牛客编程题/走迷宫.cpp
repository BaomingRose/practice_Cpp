// write your code here cpp
/*================================================
每组数据包含一个10*10，由"#"和"."组成的迷宫。其中"#"代表墙，"."代表通路。入口在一行二列，出口在10行9列。计算最快多少步。
 * description：深搜太复杂，实例都过了，但是时间超限，所以要多试试广搜了
=================================================*/
#if 0
#include <iostream>
using namespace std;

int map[10][10];
int min_step = 0x7fffffff;

void dfs(int i, int j, int& tmp) {
	if (i == 9 && j == 8 && tmp < min_step)
		min_step = tmp;
	if (tmp > min_step)
		return;
	if (i + 1 <= 9 && map[i + 1][j] == 0) {
		++tmp;
		map[i + 1][j] = 1;
		dfs(i + 1, j, tmp);
		map[i + 1][j] = 0;
		--tmp;
	}
	if (j + 1 <= 9 && map[i][j + 1] == 0) {
		++tmp;
		map[i][j + 1] = 1;
		dfs(i, j + 1, tmp);
		map[i][j + 1] = 0;
		--tmp;
	}
	if (i - 1 >= 0 && map[i - 1][j] == 0) {
		++tmp;
		map[i - 1][j] = 1;
		dfs(i - 1, j, tmp);
		map[i - 1][j] = 0;
		--tmp;
	}
	if (j - 1 >= 0 && map[i][j - 1] == 0) {
		++tmp;
		map[i][j - 1] = 1;
		dfs(i, j - 1, tmp);
		map[i][j - 1] = 0;
		--tmp;
	}
}

int main() {
	while (1) {
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				char c;
				cin >> c;
				if (c == '#')
					map[i][j] = 1;
				else
					map[i][j] = 0;
			}
		}
		int tmp = 0;
		dfs(0, 1, tmp);
		cout << min_step << endl;
		min_step = 0x7fffffff;
	}

	return 0;
}
#endif

/*================================================
 * description：
 【解题思路】
1. 采用一个二维数组，不断的接受迷宫地图(因为有多个地图)，获取到迷宫地图后，采用广度优先方式走迷宫，
	找到的第一条路径一定是最短的路径，但是深度优先则不一定。
2. 结构设定：
	pos：x，y表示当前所在位置，level所经过步数
	dir: 表示当前位置的上、下、左、右四个方向
	queue: 广度优先遍历，需要用到队列，保存所经路径
	visit：对走过的路径进行标记
	start和end表示入口和出口
3. 采用广度优先方式走迷宫：将start入队列，对该位置进行标记，只要队列不为空，继续以下步骤，直到到达出口：
	1.从队列中取出当前位置cur，计算该位置的上、下、坐、右四个方向，计算要走的下一步
	2.如果next在出口的位置，已经找到返回所走步数level
	3.否则：如果该位置有效(坐标在地图中)不是墙(该位置字符为'.')，并且没有走过(visit标记为false)时，
			将该位置入队列，再继续其他几个方向
=================================================*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct pos { int x, y, level; };

int bfs(vector<vector<char> > & map) {
	const int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

	queue<pos> que;

	int m = map.size(), n = map[0].size();
	vector<vector<bool> > visit(m, vector<bool>(n, false));

	pos start{ 0,1,0 }, end{ 9,8,0 };
	que.push(start);
	visit[start.x][start.y] = true;
	while (!que.empty()) {
		pos cur = que.front(), next; //定义cur和next
		que.pop();
		for (int i = 0; i < 4; ++i) { //BFS,优先四个方向进行搜索
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			next.level = cur.level + 1;

			//如果到了终点
			if (next.x == end.x && next.y == end.y)
				return next.level;

			//如果周围的结点满足则入队列
			if (next.x >= 0 && next.x < m && next.y >= 0 && next.y < n && \
				!visit[next.x][next.y] && map[next.x][next.y] == '.') {
				que.push(next);
				visit[next.x][next.y] = true;
			}
		}
	} 

	return 0;
} 

int main() {
	vector<vector<char> > map(10, vector<char>(10));
	while (cin >> map[0][0]) { //由多个测试用例，需要全部读取
		for (int i = 0; i < 10; ++i)
			for (int j = 0; j < 10; ++j) {
				if (i == 0 && j == 0) 
					continue;
				cin >> map[i][j];
			}
		cout << bfs(map) << endl;
	} 
	return 0;
}
