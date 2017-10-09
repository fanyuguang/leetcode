#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        int limit = nums.size() / 2;
        map<int, int> nums_count;
        for (auto iter : nums)
        {
            auto map_iter = nums_count.find(iter); 
            if (map_iter == nums_count.end())
            {
                nums_count.insert(pair<int, int>(iter, 1));
            }
            else
            {
                map_iter->second++;
                if (map_iter->second > limit)
                {
                    return map_iter->first;
                }
            }
        }
    }
};

int main()
{
    vector<int> nums = {1};
    Solution s;
    cout << s.majorityElement(nums) << endl;
    return 0;
}
