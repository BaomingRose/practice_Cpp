/*================================================
 * description：百度面试因为while循环的括号位置不正确错失机会 
=================================================*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int err = 0;

vector<string> split(const string& str) {
	vector<string> res;
	int pos = 0;
	int beg = 0;
	//错误：while ((pos = str.find(".", pos) != string::npos)) {
	while ((pos = str.find(".", pos)) != string::npos) {
		//cout << beg << " " << pos << endl;
		string tmp = str.substr(beg, pos - beg);

		//cout << tmp << endl;
		res.push_back(tmp);

		//pos要向下走一个
		pos += 1;
		beg = pos;
}

	res.push_back(str.substr(beg, str.size() - beg));

	for (const auto& e : res) {
		cout << e << endl;
	}

	return res;
}

size_t ipv4ToInt(const string& str) {
	vector<string> v = split(str);

	if (v.size() != 4) {
		err = -1;
	}
	size_t res = 0;
	res |= (stoi(v[0]) << 24);
	res |= ((stoi(v[1])) << 16);
	res |= ((stoi(v[2])) << 8);
	res |= (stoi(v[3]));

	return res;
}

int main() {
	//int a;
	//cin >> a;

	string str = "192.168.170.32";
	string str2 = "0.0.0.0";
	string str3 = "0.0";

	vector<string> v = split(str);
	for (const auto& e : v) {
		cout << e << endl;
	}

	size_t res = ipv4ToInt(str);

	cout << res << endl;

	//cout << "Hello World!" << endl;
}