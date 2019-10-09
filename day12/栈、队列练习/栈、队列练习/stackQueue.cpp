#if 0
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

//栈实现队列
class stackQueue {
	stack<int> _stack;
public:
	/** Initialize your data structure here. */
	stackQueue() {
		
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		_stack.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int tmp = _stack.top();
		if (_stack.size() == 1) {
			tmp = _stack.top();
			_stack.pop();
			return tmp;
		}
		stack<int> newStack;
		while (_stack.size() > 1) {
			newStack.push(_stack.top());
			_stack.pop();
		}
		tmp = _stack.top();
		_stack.pop();
		while (newStack.size()) {
			_stack.push(newStack.top());
			newStack.pop();
		}
		return tmp;
	}

	/** Get the front element. */
	int peek() {
		if (_stack.size() == 1) {
			return _stack.top();
		}
		stack<int> newStack;
		while (_stack.size() > 1) {
			newStack.push(_stack.top());
			_stack.pop();
		}
		int tmp = _stack.top();
		while (newStack.size()) {
			_stack.push(newStack.top());
			newStack.pop();
		}
		return tmp;
	}
		

	/** Returns whether the queue is empty. */
	bool empty() {
		return _stack.empty();
	}


};

int main() {
	stackQueue que;
	que.push(10);
	que.push(100);
	que.push(1000);
	cout << que.peek() << endl;
	que.pop();
	cout << que.peek() << endl;
	que.pop();
	cout << que.peek() << endl;

	return 0;
}
#endif