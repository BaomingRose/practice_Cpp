#include<iostream>
#include<vector>
using namespace std;

void printVector(const vector<int> &v, int n) {
	int i;
	for (i = 0; i < n; ++i) {
		cout << v[i] << '\t';
	}
	cout << endl;
}

//���԰棺�ռ临�Ӷȵ�(һά����)
void generate(int numRows) {
	vector<int> v(numRows, 0);
	v[0] = 1;
	for (int i = 1; i <= numRows; ++i) {
		for (int j = i - 1; j > 0; --j) {
			v[j] += v[j - 1];
		}
		printVector(v, i);
	}
}

//��ά�����
vector<vector<int>> generate1(int numRows) {
	vector<vector<int>> data(numRows);
	if (numRows == 0) {
		return data;
	}
	int i, j;
	data[0].push_back(1);

	for (i = 1; i < numRows; i++) {
		data[i] = data[i - 1];
		for (j = i - 1; j > 0; j--)
			data[i][j] += data[i][j - 1];

		data[i].push_back(1);
	}
	return data;
}

int main() {
	generate(15);
	cout << endl;

	vector<vector<int>> v = generate1(15);
	for (auto i : v) {
		for (auto j : i) {
			cout << j << '\t';
		}
		cout << endl;
	}
	
	return 0;
}