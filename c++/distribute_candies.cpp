#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int distributeCandies(vector<int>& candies) {
    int size_sister = candies.size() / 2;
    unordered_map<int, int> sister_candies;
    int count_candies = 0;
    for (int candy : candies) {
      if (sister_candies.find(candy) == sister_candies.end()) {
        sister_candies[candy] = 1;
        count_candies++;
      }
      if (count_candies >= size_sister) {
        return size_sister;
      }
    }
    return count_candies;
  }
};

int main() {
  vector<int> candies = {1, 1, 2, 2, 3, 3};
  // vector<int> candies = {100000, 0, 100000, 0, 100000, 0, 100000, 0, 100000, 0, 100000, 0};
  Solution s;
  int result = s.distributeCandies(candies);
  cout << result << endl;
  return 0;
}
