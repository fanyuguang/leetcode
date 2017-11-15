#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {
	}

	/** Push element x onto stack. */
	void push(int x) {
		q.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
    for (int i = 0; i < q.size() - 1; i++) {
      int element = q.front();
      q.pop();
      q.push(element);
    }
    int element = q.front();
    q.pop();
    return element;
	}

	/** Get the top element. */
	int top() {
    int element = q.front();
    for (int i = 0; i < q.size(); i++) {
      element = q.front();
      q.pop();
      q.push(element);
    }
		return element;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		if (q.empty()) {
      return true;
    } else {
      return false;
    }
	}

private:
  queue<int> q;
};

int main() {
  MyStack obj;
  obj.push(1);
  obj.push(2);
  // int param_2 = obj.pop();
  // cout << param_2 << endl;
  int param_3 = obj.top();
  cout << param_3 << endl;
  bool param_4 = obj.empty();
  if (param_4) {
    cout << "empty" << endl;
  } else {
    cout << "not empty" << endl;
  }
  return 0;
}
