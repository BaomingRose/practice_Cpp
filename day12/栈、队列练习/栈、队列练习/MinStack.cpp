#if 0
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

class MinStack {
	stack<int> m_data;
	stack<int> m_min;
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		m_data.push(x);

		if (m_min.empty() || m_min.top() >= x) {
			m_min.push(x);
		}
	}

	void pop() {
		if (m_data.top() == m_min.top()) {
			m_min.pop();
		}

		m_data.pop();
	}

	int top() {
		return m_data.top();
	}

	int getMin() {
		return m_min.top();
	}
};


int main() {
	MinStack minstack;
	minstack.push(10);
	minstack.push(10);
	minstack.push(10);
//	minstack.push(11);
//	minstack.push(-9);

	cout << minstack.getMin() << endl;
	minstack.pop();
	cout << minstack.getMin() << endl;
	minstack.pop();
	cout << minstack.getMin() << endl;
	/*
	minstack.pop();
	cout << minstack.getMin() << endl;
	minstack.pop();
	cout << minstack.getMin() << endl;*/

	return 0;
}
#endif