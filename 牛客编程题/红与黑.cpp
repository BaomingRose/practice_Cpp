/*================================================
连接：https://www.nowcoder.com/questionTerminal/5017fd2fc5c84f78bbaed4777996213a
 * description：有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。
		 你站在其中一块黑色的瓷砖上，只能向相邻的（上下左右四个方向）黑色瓷砖移动。
		 请写一个程序，计算你总共能够到达多少块黑色的瓷砖。

 [题目解析]
	1. 输入的m和n就是代表输入后续会输入几行几列字符
	2. 第二行开始，输入的字符就是我们的“行走矩阵”，其中“.”->黑色的瓷砖, “#”->白色的瓷砖,
		“@”->黑色的瓷砖，并且你站在这块瓷砖上
	3. 这道题的核心问题是，从你站的位置开始，向周边任意位置走，你能直接走过的黑色瓷砖的总数是多少
	重点就是可以任意位置走，所以我想的复杂了，每个方向分别统计个数，然后比较了，所以深搜不需要太复杂
=================================================*/
#if 1	//深搜
#include<iostream>
#include<string.h>
using namespace std;
int a[20][20] = { 0 }, res = 0, m, n;//注意是全局变量，多组数据时要在最后初始化
void dfs(int x, int y) {
	if (a[x][y] == 1 || x < 0 || x >= m || y < 0 || y >= n)//递归的边界条件
		return;
	res++;    //结果增加1
	a[x][y] = 1;//置1代表已经走过
	dfs(x - 1, y);//分别对应上
	dfs(x + 1, y);//下
	dfs(x, y - 1);//左
	dfs(x, y + 1);//右相邻格子
}

int main() {
	while (~scanf("%d %d", &m, &n)) {
		getchar();//为什么要getchar()?因为第一行9 6后面还有一个换行符
		int x, y;
		char c;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%c", &c);
				if (c == '@') {
					x = i;
					y = j;
				} else {
					if (c == '#')
						a[i][j] = 1;
				}
			}
			getchar();//同样的，吃掉每行最后一个换行符
		}
		dfs(x, y);
		printf("%d\n", res);
		res = 0;
		memset(a, 0, sizeof(a));//全局变量初始化
	}

	return 0;
}
#endif


#if 0	//广搜
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct pos { int x, y; };

int bfs(vector<vector<char>>& map, vector<vector<bool>>& visit, pos& start) {
	const int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	queue<pos> que;
	int count = 0;
	int m = map.size(), n = map[0].size();
	que.push(start);
	visit[start.x][start.y] = true; ++count;
	while (!que.empty()) {
		pos cur = que.front(), next;
		que.pop();
		for (int i = 0; i < 4; ++i) {
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			if (next.x >= 0 && next.x < m && next.y >= 0 && next.y < n && \
				!visit[next.x][next.y] && map[next.x][next.y] == '.') {
				que.push(next);
				visit[next.x][next.y] = true;
				++count;
			}
		}
	} 
	return count;
} 

int main() {
	int m, n;
	while (cin >> m >> n && (m*n)) {
		pos start;
		vector<vector<char> > map(m, vector<char>(n));
		vector<vector<bool> > visit(m, vector<bool>(n));
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j) {
				visit[i][j] = false;
				cin >> map[i][j];
				if (map[i][j] == '@')
					start.x = i, start.y = j;
			}
		cout << bfs(map, visit, start) << endl;
	}	
	return 0;
}
#endif