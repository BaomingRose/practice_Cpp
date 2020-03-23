#include <iostream>
#include <vector>
using namespace std;

const int maxValue = 0x7fffffff;

bool isOk(const vector<int>& v) {
	for (const auto& e : v) {
		if (e != 0)
			return false;
	}
	return true;
}

void dfs(vector<int>& a, int& minstep, int& tmp, int i) {
	if (i > a.size() - 1)
		return;
	if (isOk(a) && tmp < minstep)
		minstep = tmp;

	if (a[i] == 0) {
		dfs(a, minstep, tmp, i + 1);
	}

	else {
		if (i + 4 < 10 && a[i] > 0 && a[i + 1] > 0 && a[i + 2] > 0 && a[i + 3] > 0 && a[i + 4] > 0) {
			++tmp;
			a[i] -= 1;
			a[i + 1] -= 1;
			a[i + 2] -= 1;
			a[i + 3] -= 1;
			a[i + 4] -= 1;
			if (a[i] == 0)
				dfs(a, minstep, tmp, i + 1);
			else if (a[i] > 0)
				dfs(a, minstep, tmp, i);
			--tmp;
			a[i] += 1;
			a[i + 1] += 1;
			a[i + 2] += 1;
			a[i + 3] += 1;
			a[i + 4] += 1;
		}
		//以i为头连出3对 
		if (i + 2 < 10 && a[i] > 1 && a[i + 1] > 1 && a[i + 2] > 1) {
			++tmp;
			a[i] -= 2;
			a[i + 1] -= 2;
			a[i + 2] -= 2;
			if (a[i] == 0)
				dfs(a, minstep, tmp, i + 1);
			else if (a[i] > 0)
				dfs(a, minstep, tmp, i);
			--tmp;
			a[i] += 2;
			a[i + 1] += 2;
			a[i + 2] += 2;
		}
		//出两张i 
		if (minstep == maxValue && a[i] > 1) {
			++tmp;
			a[i] -= 2;
			if (a[i] == 0)
				dfs(a, minstep, tmp, i + 1);
			if (a[i] > 0)
				dfs(a, minstep, tmp, i);
			--tmp;
			a[i] += 2;
		}
		//出一张i 
		if (minstep == maxValue && a[i] > 0) {
			++tmp;
			a[i] -= 1;
			if (a[i] == 0)
				dfs(a, minstep, tmp, i + 1);
			if (a[i] > 0)
				dfs(a, minstep, tmp, i);
			--tmp;
			a[i] += 1;
		}
	}
}

int main() {
	int minstep = maxValue;
	int tmp = 0;
	vector<int> v(10);
	for (int i = 0; i < v.size(); ++i) {
		cin >> v[i];
	}
	dfs(v, minstep, tmp, 0);

	cout << minstep << endl;

	return 0;
}