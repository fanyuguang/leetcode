#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
		if (nums.empty())
			return 0;

		int length = 1;
        vector<int>::iterator first_iter = nums.begin();
		vector<int>::iterator second_iter = nums.begin();
        
		while (++second_iter != nums.end())
        {
            if (*first_iter != *second_iter)
            {
				first_iter++;
                *first_iter = *second_iter;
				length++;
            }
        }

		return length;
    }
};

int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
    int update_length = s.removeDuplicates(nums);
	for (int i = 0; i < update_length; i++)
	{
		cout << nums.at(i) << endl;
	}
	cout << update_length << endl;
	return 0;
}
