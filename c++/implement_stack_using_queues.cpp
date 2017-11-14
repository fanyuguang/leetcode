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
		queue.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		if (queue2.empty) {
      TransferData();
    }
    int element = queue2.front();
    return element;
	}

	/** Get the top element. */
	int top() {
		return queue2.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		if (queue1.empty() && queue2.empty()) {
      return true;
    } else {
      return false;
    }
	}

private:
  queue<int> queue;
};

int main() {
  MyStack obj = new MyStack();
  obj.push(1);
  int param_2 = obj.pop();
  int param_3 = obj.top();
  bool param_4 = obj.empty();
  return 0;
}
