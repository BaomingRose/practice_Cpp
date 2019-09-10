#include"SeqList.h"

int main() {
	SeqList<int> s1;

/*	s1.push_back(0);
	s1.push_back(1);
	s1.push_back(2);
	cout << s1.size() << endl;
	s1.pop_back();
	cout << s1.size() << endl;
*/

	for (int i = 0; i < 9; ++i) {
		s1.push_back(2 * i);
	}

	for (int i = 0; i < s1.size(); ++i) {
		cout << s1[i] << " ";
	}
	cout << endl << s1.size() << endl;
	return 0;
}