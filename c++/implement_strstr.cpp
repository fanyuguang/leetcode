#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    int haystack_length = haystack.length();
    int needle_length = needle.length();
    if (needle_length == 0)
    {
      return 0;
    }
    if (haystack_length == 0)
    {
      return -1;
    }

    vector<int> next = gen_next(needle);

    int i = 0;
    int j = 0;
    while (i < haystack_length && j < needle_length)
    {
      if (j == -1 || haystack[i] == needle[j])
      {
        i++;
        j++;
      }
      else
      {
        j = next[j];
      }
    }

    if (j == needle_length)
    {
      return i - j;
    }
    else
    {
      return -1;
    }
  }

private:
  vector<int> gen_next(string needle)
  {
    vector<int> next(needle.length(), 0);
    next[0] = -1;
    int i = 0;
    int j = -1;
    while (i < needle.length() - 1)
    {
      if (j == -1 || needle[i] == needle[j])
      {
        i++;
        j++;
        next[i] = j;
      }
      else
      {
        j = next[j];
      }
    }

    return next;
  }
};

int main()
{
  Solution s;
  string haystack = "hello";
  string needle = "ll";
  int result = s.strStr(haystack, needle);
  cout << result << endl;
}
