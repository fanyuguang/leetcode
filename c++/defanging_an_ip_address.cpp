#include <iostream>
#include <regex>

using namespace std;

class Solution
{
public: 
  string defangIPaddr(string address)
  {
    regex pattern("[.]");
    return regex_replace(address, pattern, "[.]");
  }
};

int main() 
{
  Solution s;
  string address = "255.100.50.0";
  string result = s.defangIPaddr(address);
  cout << result << endl;
  return 0;  
}
