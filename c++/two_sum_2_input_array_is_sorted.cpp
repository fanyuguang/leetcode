#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> two_index;
    unordered_map<int, int> num_store;
    for (int i = 0; i < numbers.size(); i++) {
      if (num_store.find(target - numbers[i]) != num_store.end()) {
        two_index.push_back(num_store[target - numbers[i]]);
        two_index.push_back(i + 1);
      } else {
        num_store[numbers[i]] = i + 1;
      }
    }
    return two_index;
  }
};

int main() {
  vector<int> numbers = {2, 7, 11, 15};
  Solution s;
  vector<int> result = s.twoSum(numbers, 9);
  for (int num : result) {
    cout << num << endl;
  }
  return 0;
}
