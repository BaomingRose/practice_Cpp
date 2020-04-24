/*================================================
���ӣ�https://www.nowcoder.com/questionTerminal/5017fd2fc5c84f78bbaed4777996213a
 * description����һ�䳤���εķ��ӣ��������˺�ɫ����ɫ������ɫ�������δ�ש��
		 ��վ������һ���ɫ�Ĵ�ש�ϣ�ֻ�������ڵģ����������ĸ����򣩺�ɫ��ש�ƶ���
		 ��дһ�����򣬼������ܹ��ܹ�������ٿ��ɫ�Ĵ�ש��

 [��Ŀ����]
	1. �����m��n���Ǵ���������������뼸�м����ַ�
	2. �ڶ��п�ʼ��������ַ��������ǵġ����߾��󡱣����С�.��->��ɫ�Ĵ�ש, ��#��->��ɫ�Ĵ�ש,
		��@��->��ɫ�Ĵ�ש��������վ������ש��
	3. �����ĺ��������ǣ�����վ��λ�ÿ�ʼ�����ܱ�����λ���ߣ�����ֱ���߹��ĺ�ɫ��ש�������Ƕ���
	�ص���ǿ�������λ���ߣ���������ĸ����ˣ�ÿ������ֱ�ͳ�Ƹ�����Ȼ��Ƚ��ˣ��������Ѳ���Ҫ̫����
=================================================*/
#if 1	//����
#include<iostream>
#include<string.h>
using namespace std;
int a[20][20] = { 0 }, res = 0, m, n;//ע����ȫ�ֱ�������������ʱҪ������ʼ��
void dfs(int x, int y) {
	if (a[x][y] == 1 || x < 0 || x >= m || y < 0 || y >= n)//�ݹ�ı߽�����
		return;
	res++;    //�������1
	a[x][y] = 1;//��1�����Ѿ��߹�
	dfs(x - 1, y);//�ֱ��Ӧ��
	dfs(x + 1, y);//��
	dfs(x, y - 1);//��
	dfs(x, y + 1);//�����ڸ���
}

int main() {
	while (~scanf("%d %d", &m, &n)) {
		getchar();//ΪʲôҪgetchar()?��Ϊ��һ��9 6���滹��һ�����з�
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
			getchar();//ͬ���ģ��Ե�ÿ�����һ�����з�
		}
		dfs(x, y);
		printf("%d\n", res);
		res = 0;
		memset(a, 0, sizeof(a));//ȫ�ֱ�����ʼ��
	}

	return 0;
}
#endif


#if 0	//����
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