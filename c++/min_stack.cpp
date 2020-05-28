#include <iostream>
#include <vector>

using namespace std;

class MinStack
{
public:
  MinStack()
  {
  }

  void push (int x)
  {
    stack.push_back(x);
    if (min.empty() || x <= min[min.size() - 1])
    {
      min.push_back(x);
    }
  }

  void pop()
  {
    int x = stack[stack.size() - 1];
    stack.pop_back();
    if (x == min[min.size() - 1])
    {
      min.pop_back();
    }
  }

  int top()
  {
    return stack[stack.size() - 1];
  }

  int getMin()
  {
    return min[min.size() - 1];
  }

private:
  vector<int> stack;
  vector<int> min;
};

int main()
{
  MinStack min_stack;
  min_stack.push(-2);
  min_stack.push(0);
  min_stack.push(-3);
  cout << min_stack.getMin() << endl;
  min_stack.pop();
  cout << min_stack.top() << endl;
  cout << min_stack.getMin() << endl;

  return 0;
}
