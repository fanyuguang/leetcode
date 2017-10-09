#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        set<int> nums_count;
        for(auto iter : nums)
        {
            if (nums_count.find(iter) == nums_count.end())
            {
                nums_count.insert(iter);
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    Solution s;
    if (s.containsDuplicate(nums))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}
