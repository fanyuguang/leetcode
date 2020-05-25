#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> greatest_number_of_candies;
    int max_candies = 0;
    for (int candy_num : candies)
    {
      if (candy_num > max_candies)
      {
        max_candies = candy_num;
      }
    }
    for (int candy_num : candies)
    {
      if (candy_num + extraCandies >=  max_candies)
      {
        greatest_number_of_candies.push_back(true);
      }
      else
      {
        greatest_number_of_candies.push_back(false);
      }
    }
    return greatest_number_of_candies;
  }
};

int main()
{
  Solution s;
  vector<int> candies = {2, 3, 5, 1, 3};
  vector<bool> result = s.kidsWithCandies(candies, 3);
  for (bool item : result)
  {
    if (item)
    {
      cout << "true ";
    }
    else
    {
      cout << "false ";
    }
  }
  cout << endl;
  return 0;
}
