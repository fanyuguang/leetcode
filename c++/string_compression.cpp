#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  int compress(vector<char>& chars)
  {
    int chars_size = chars.size();
    if (chars_size == 0)
    {
      return 0;
    }
    char c = chars[0];
    int first_index = 0;
    int count = 0;
    for (int i = 0; i <= chars_size; i++)
    {
      if (i == chars_size || chars[i] != c)
      {
        chars[first_index++] = c;
        if (count > 1)
        {
          string count_str = std::to_string(count);
          for (char count_c : count_str)
          {
            chars[first_index++] = count_c;
          }
        }
        if (i != chars_size)
        {
          c = chars[i];
        }
        count = 1;
      }
      else
      {
        count++;
      }
    }
    return first_index;
  }
};

int main()
{
  vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
  Solution s;
  int result = s.compress(chars);
  cout << result << endl;
  for (int i = 0; i < result; i++)
  {
    cout << chars[i] << " ";
  }
  cout << endl;
  return 0;
}
