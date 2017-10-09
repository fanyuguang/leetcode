#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& A) {
    int length = A.size();
    if (length < 3) {
      return 0;
    }
    int slices_count = 0;
    int start = 0;
    int end = 1;
    int difference = A[end] - A[start];
    while (++end < length) {
      if (A[end] - A[end - 1] != difference) {
        int slices_length = end - start;
        if (slices_length >= 3) {
          slices_count += (slices_length * slices_length - 3 * slices_length) / 2 + 1;
        }
        start = end - 1;
        difference = A[end] - A[end - 1];
      }
    }
    int slices_length = end - start;
    if (slices_length >= 3) {
      slices_count += (slices_length * slices_length - 3 * slices_length) / 2 + 1;
    }
    return slices_count;
  }
};

int main() {
  vector<int> A = {1, 2, 3, 4};
  Solution s;
  int result = s.numberOfArithmeticSlices(A);
  cout << result << endl;
  return 0;
}
