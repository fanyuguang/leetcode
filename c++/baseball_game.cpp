#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
  int calPoints(vector<string>& ops) {
    stack<int> scores;
    for (string op : ops) {
      if (op == "+") {
        int first = scores.top();
        scores.pop();
        int second = scores.top();
        scores.push(first);
        scores.push(first + second);
      } else if (op == "D") {
        scores.push(scores.top() * 2);
      } else if (op == "C") {
        scores.pop();
      } else {
        scores.push(stoi(op));
      }
    }
    int score_sum = 0;
    while (!scores.empty()) {
      score_sum += scores.top();
      scores.pop();
    }
    return score_sum;
  }
};

int main() {
  vector<string> ops{"5", "2", "C", "D", "+"};
  Solution s;
  int result = s.calPoints(ops);
  cout << result << endl;
  return 0;
}
