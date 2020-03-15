#include <iostream>
#include <stack>
using namespace std;

template<class T>
class Queue {
public:
	void push(const T& data) {
		s_storage.push(data);
	}
	
	bool empty() {
		return s_storage.empty();
	}
	
	void pop() {
		while (!s_storage.empty()) {
			T tmp = s_storage.top();
			s_tmp.push(tmp);
			s_storage.pop();
		}
		s_tmp.pop();
		while (!s_tmp.empty()) {
			T tmp = s_tmp.top();
			s_storage.push(tmp);
			s_tmp.pop();
		}
	}
	
	T front() {
		while (s_storage.size() > 1) {
			T tmp = s_storage.top();
			s_tmp.push(tmp);
			s_storage.pop();			
		}
		T res = s_storage.top();
		while (!s_tmp.empty()) {
			T tmp = s_tmp.top();
			s_storage.push(tmp);
			s_tmp.pop();
		}
		return res;
	}
private:
	stack<T> s_storage;
	stack<T> s_tmp;
};

int main() {
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
	return 0;
}
