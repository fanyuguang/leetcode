#include <iostream>
#include <stack>

using namespace std;

class Queue {
public:
  // Push element x to the back of queue.
  void push(int x) {
    s.push(x);
  }
  // Removes the element from in front of queue.
  void pop(void) {
    if (s_peek.empty()) {
      while (!s.empty()) {
        s_peek.push(s.top());
        s.pop();
      }
    }
    s_peek.pop();
  }
  // Get the front element.
  int peek(void) {
    if (s_peek.empty()) {
      while (!s.empty()) {
        s_peek.push(s.top());
        s.pop();
      }
    }
    return s_peek.top();
  }
  // Return whether the queue is empty.
  bool empty(void) {
    if (s_peek.empty() && s.empty()) {
      return true;
    } else {
      return false;
    }
  }

private:
  stack<int> s;
  stack<int> s_peek;
};

int main() {
  Queue q;
  q.push(1);
  q.push(2);
  q.push(3);
  while (!q.empty()) {
    cout << q.peek() << endl;
    q.pop();
  }
  return 0;
}
