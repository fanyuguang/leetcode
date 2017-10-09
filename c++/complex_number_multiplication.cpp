#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string complexNumberMultiply(string a, string b) {
    int a_index = a.find('+');
    int a_real = stoi(a.substr(0, a_index));
    int a_imaginary = stoi(a.substr(a_index + 1, a.size() - a_index - 2));
    int b_index = b.find('+');
    int b_real = stoi(b.substr(0, b_index));
    int b_imaginary = stoi(b.substr(b_index + 1, b.size() - b_index - 2));
    int multiply_real = a_real * b_real - a_imaginary * b_imaginary;
    int multiply_imaginary = a_real * b_imaginary + a_imaginary * b_real;
    string multiply_result = to_string(multiply_real) + '+' + to_string(multiply_imaginary) + 'i';
    return multiply_result;
  }
};

int main() {
  string a = "1+-1i";
  string b = "1+-1i";
  Solution s;
  string result = s.complexNumberMultiply(a, b);
  cout << result << endl;
  return 0;
}
