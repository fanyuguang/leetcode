#include <iostream>

using namespace std;

class Solution
{
public:
    int titleToNumber(string s)
    {
        int length = s.length();
        int column_number = 0;
        int count = 1;
        for (int i = length - 1; i >= 0; i--)
        {
            column_number += (s.at(i) - '@' ) * count;
            count *= 26;
        }
        return column_number;
    }
};

int main()
{
    string str = "AB";
    Solution s;
    cout << s.titleToNumber(str) << endl;
    return 0;
}
