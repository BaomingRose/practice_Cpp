#include <stack>
#include <iostream>
using namespace std; 

class StackWithMin {
public:
    void push(int value) {
        if (_min_st.empty() || _min_st.top() >= value)
            _min_st.push(value);
        _st.push(value);
    }
    void pop() {
        if (_st.empty())
            return;
        if (_st.top() == _min_st.top())
            _min_st.pop();
        _st.pop();
    }
    int top() {
        return _st.top();
    }
    int min() {
        return _min_st.top();
    }
    
    bool empty() {
    	return _st.empty();
	}
private:
    stack<int> _st;
    stack<int> _min_st;
};

int main() {
	StackWithMin stm;
	stm.push(10);
	stm.push(3);
	stm.push(1000);
	stm.push(5);
	stm.push(1);
	while (!stm.empty()) {
		cout << "stm.min:" << stm.min() << endl;
		cout << "stm.top:" << stm.top() << endl;
		cout << "stm.pop£º" << endl;
		stm.pop();
	}
	
	return 0;
}
