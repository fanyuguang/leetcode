#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        vector<int> set_num;
        set_num.push_back(n);
        while (true)
        {
            int new_num = 0;
            do
            {
                new_num += pow(n % 10, 2);
            } while (n /= 10);
            if (new_num == 1)
            {
                return true;
            }
            if (std::find(set_num.begin(), set_num.end(), new_num) != set_num.end())
            {
                return false;
            }
            n = new_num;
            set_num.push_back(n);
        }
        return false;
    }
};

int main()
{
    int n = 19;
    Solution s;
    if (s.isHappy(n))
    {
        cout << "Happy Number!" << endl;
    }
    else
    {
        cout << "Non-happy Number!" << endl;
    }
    return 0;
}
