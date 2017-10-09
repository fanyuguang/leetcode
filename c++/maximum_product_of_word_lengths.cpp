#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  int maxProduct(vector<string>& words)
  {
    int words_size = words.size();
    vector<int> bit_of_words(words_size, 0);
    for (int i = 0; i < words_size; i++)
    {
      for (int j = 0; j < words.at(i).size(); j++)
      {
        bit_of_words.at(i) |= (1 << (words.at(i).at(j) - 'a'));
      }
    }
    int max = 0;
    for (int i = 0; i < words_size; i++)
    {
      for (int j = i; j < words_size; j++)
      {
        if (!(bit_of_words.at(i) & bit_of_words.at(j)) && (words.at(i).size() * words.at(j).size() > max))
        {
          max = words.at(i).size() * words.at(j).size();
        }
      }
    }
    return max;
  }
};

int main()
{
  vector<string> words;
  words.push_back("qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq");
  words.push_back("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
  words.push_back("gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg");
  words.push_back("tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt");
  words.push_back("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
  words.push_back("llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll");
  Solution S;
  int max_product = S.maxProduct(words);
  cout << max_product << endl;
  return 0;
}
