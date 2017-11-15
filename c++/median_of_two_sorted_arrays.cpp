#include <iostream>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	}

private:
  double findKth(vector<int>& nums1, vector<int>& nums2, int k) {
  }
};

int main() {
	vector<int> nums1 = {1, 3};
	vector<int> nums2 = {2};
	Solution s;
  double result = s.findMedianSortedArrays(nums1, nums2);
	cout << result << endl;
	return 0;
}
