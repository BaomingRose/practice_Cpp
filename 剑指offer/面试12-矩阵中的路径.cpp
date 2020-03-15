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

//����û������������޵ݹ飬�޷��ı�pathLength��ֵ
bool hasPathCore(const char* matrix, int rows, int colums, int row, int col, const char* str, int& pathLength, bool* visited) {
	//�ߵ��������˳��� 
	if (str[pathLength] == '\0')
		return true;

	//�ߵ����λ�ÿ�����Խ���˿����Ǹ����Ͳ�ƥ���ַ�Ҳ�����Ѿ��߹���λ�� 
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

	//���� 
	if (!hasPath) {
		--pathLength;
		visited[row * colums + col] = false;
	}
	return hasPath;
}

int main() {
	const char* str = "abtgcfcsjdeh";

	if (hasPath(str, 3, 4, "bfce"))
		cout << "bfce exit��" << endl;
	else
		cout << "bfce not exit!" << endl;

	if (hasPath(str, 3, 4, "abfb"))
		cout << "abfb exit!" << endl;
	else
		cout << "abfb not exit!" << endl;

	return 0;
}
#endif
