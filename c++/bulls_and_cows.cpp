#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  string getHint(string secret, string guess)
  {
    vector<int> digits(10, 0);    
    int bulls = 0;
    int cows = 0;
    for (int i = 0; i < secret.length(); i++)
    {
      if (secret[i] == guess[i])
      {
        bulls++;
        continue;
      }
      digits[secret[i] - '0']++;
    }
    for (int i = 0; i < guess.length(); i++)
    {
      if (secret[i] != guess[i] && digits[guess[i] - '0'] > 0)
      {
        cows++;
        digits[guess[i] - '0']--;
      }
    }
    return to_string(bulls) + "A" + to_string(cows) + "B";
  }
};

int main()
{
  // string secret = "1123";
  // string guess = "0111";
  string secret = "11";
  string guess = "10";
  Solution s;
  string result = s.getHint(secret, guess);
  cout << result << endl;
  return 0;
}
