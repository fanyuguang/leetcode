#include <iostream>
#include <set>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        int length = s.length();
        multiset<char> s_set;
        for (int i = 0; i < length; i++)
        {
            s_set.insert(s.at(i));
        }
        for (int j = 0; j < length; j++)
        {
            auto iter = s_set.find(t.at(j));
            if (iter != s_set.end())
            {
                s_set.erase(iter);
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string str = "anagram";
    string t = "nagaram";
    Solution s;
    if (s.isAnagram(str, t))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}
