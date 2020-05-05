#if 0
#include<iostream>
#include<string>
using namespace std;

bool five(string v[]) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (v[i][j] == '.')		//非棋子跳过
				continue;
			int right = 1, down = 1, right_down = 1, left_down = 1;
			for (int t = 1; t < 5; t++) {  //四个方向往后走四个
				if (j < 16 && v[i][j] == v[i][j + t])
					right++;
				if (i < 16 && v[i][j] == v[i + t][j])
					down++;
				if (j < 16 && i < 16 && v[i][j] == v[i + t][j + t])
					right_down++;
				if (j > 3 && i < 16 && v[i][j] == v[i + t][j - t])
					left_down++;
			}
			if (right == 5 || down == 5 || right_down == 5 || left_down == 5)
				return true;
		}
	}
	return false;
}

int main() {
	string s[20];
	while (cin >> s[0]) {
		for (int i = 1; i < 20; i++)
			cin >> s[i];
		cout << (five(s) ? "Yes" : "No") << endl;
	}
	return 0;
#endif
}