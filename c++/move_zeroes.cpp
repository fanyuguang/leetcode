#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        int i = 0;
        int j;
        while (i < nums.size() - 1)
        {
            while (i < nums.size() - 1 && nums.at(i) != 0)
            {
                i++;
            }
            j = i + 1;
            while ( j < nums.size() && nums.at(j) == 0)
            {
                j++;
            }
            if (i < nums.size() - 1 && j < nums.size())
            {
                nums.at(i) = nums.at(j);
                nums.at(j) = 0;
                i++;
            }
            else
            {
                break;
            }
        }
    }
};

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    Solution s;
    s.moveZeroes(nums);
    for (auto iter = nums.begin(); iter != nums.end(); iter++)
    {
        cout << *iter << endl;
    }
    return 0;
}
