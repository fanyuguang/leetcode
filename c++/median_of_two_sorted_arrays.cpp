#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int k = nums1.size() + nums2.size();
    if (k % 2 == 1) {
      return findKth(nums1, nums2, k / 2 + 1);
    } else {
      cout << findKth(nums1, nums2, k / 2) << endl;
      cout << findKth(nums1, nums2, k / 2 + 1) << endl;
      return (findKth(nums1, nums2, k / 2) + findKth(nums1, nums2, k / 2 + 1)) / 2;
    }
	}

private:
  double findKth(vector<int>& nums1, vector<int>& nums2, int k) {
    int nums1_size = nums1.size();
    int nums2_size = nums2.size();
    int nums1_start = 0;
    int nums2_start = 0;
    while (nums1_start < nums1_size && nums2_start < nums2_size) {
      if (k == 1) {
        return nums1[nums1_start] < nums2[nums2_start] ? nums1[nums1_start] : nums2[nums2_start];
      }
      int k1_size = k / 2;
      int k2_size = k - k1_size;
      if ((nums1_size - nums1_start) < k1_size) {
        k1_size = (nums1_size - nums1_start);
        k2_size = k - k1_size;
      } else if ((nums2_size - nums2_start) < k2_size) {
        k2_size = (nums2_size - nums2_start);
        k1_size = k - k2_size;
      }
      if (nums1[nums1_start + k1_size - 1] < nums2[nums2_start + k2_size - 1]) {
        nums1_start += k1_size;
        k = k - k1_size;
      } else if (nums1[nums1_start + k1_size - 1] > nums2[nums2_start + k2_size - 1]) {
        nums2_start += k2_size;
        k = k - k2_size;
      } else {
        return nums1[nums1_start + k1_size - 1];
      }
    }
    if (nums1_start < nums1_size) {
      return nums1[nums1_start + k - 1];
    }
    if (nums2_start < nums2_size) {
      return nums2[nums2_start + k - 1];
    }
    return nums1[nums1_size - 1];
  }
};

int main() {
	vector<int> nums1 = {2, 3, 4};
	vector<int> nums2 = {1};
	Solution s;
  double result = s.findMedianSortedArrays(nums1, nums2);
	cout << result << endl;
	return 0;
}
