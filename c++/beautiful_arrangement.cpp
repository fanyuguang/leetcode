#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int countArrangement(int N) {
    this->N = N;
    vector<bool> visited(N + 1, false);
    place_num(1, visited);
    return count;
  }

private:
  void place_num(int pos, vector<bool>& visited) {
    if (pos > N) {
      count++;
    }
    for (int i = 1; i <= N; i++) {
      if (!visited[i] && (pos % i == 0 || i % pos == 0)) {
        visited[i] = true;
        place_num(pos + 1, visited);
        visited[i] = false;
      }
    }
  }
  int N;
  int count;
};

int main() {
  int N = 2;
  Solution s;
  int result = s.countArrangement(N);
  cout << result << endl;
  return 0;
}
