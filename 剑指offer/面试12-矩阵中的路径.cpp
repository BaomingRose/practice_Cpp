#if 1
#include <iostream>
#include <cstring>
using namespace std;

bool hasPathCore(const char* matrix, int rows, int colums, int row, int col, const char* str, int& pathLength, bool* visited);

bool hasPath(const char* matrix, int rows, int colums, const char* str) {
	if (matrix == NULL || rows < 1 || colums < 1 || str == NULL)
		return false;

	bool* visited = new bool[rows * colums];
	memset(visited, 0, rows * colums);

	int pathLength = 0;
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < colums; ++col) {
			if (hasPathCore(matrix, rows, colums, row, col, str, pathLength, visited))
				return true;
		}
	}
	delete[] visited;

	return false;
}

//长度没加引用造成无限递归，无法改变pathLength的值
bool hasPathCore(const char* matrix, int rows, int colums, int row, int col, const char* str, int& pathLength, bool* visited) {
	//走到最后可以退出了 
	if (str[pathLength] == '\0')
		return true;

	//走到这个位置可能是越界了可能是根本就不匹配字符也可能已经走过的位置 
	if (row < 0 || col < 0 || row >= rows || col >= colums || matrix[row * colums + col] != str[pathLength]
		|| visited[row * colums + col])
		return false;

	bool hasPath = false;
	
	++pathLength;
	visited[row * colums + col] = true;

	hasPath = hasPathCore(matrix, rows, colums, row, col - 1, str, pathLength, visited)
		|| hasPathCore(matrix, rows, colums, row - 1, col, str, pathLength, visited)
		|| hasPathCore(matrix, rows, colums, row, col + 1, str, pathLength, visited)
		|| hasPathCore(matrix, rows, colums, row + 1, col, str, pathLength, visited);

	//回溯 
	if (!hasPath) {
		--pathLength;
		visited[row * colums + col] = false;
	}
	return hasPath;
}

int main() {
	const char* str = "abtgcfcsjdeh";

	if (hasPath(str, 3, 4, "bfce"))
		cout << "bfce exit！" << endl;
	else
		cout << "bfce not exit!" << endl;

	if (hasPath(str, 3, 4, "abfb"))
		cout << "abfb exit!" << endl;
	else
		cout << "abfb not exit!" << endl;

	return 0;
}
#endif
