#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class LetterDecoding
{
public:
  int get_num_of_decoding(string nums)
  {
    return get_num_of_decoding(nums, 0);
  }

  int get_num_of_decoding(string nums, int start)
  {
    if (start >= nums.length() - 1)
    {
      return 1;
    }

    if (decoding_mapping.find(start) != decoding_mapping.end())
    {
      return decoding_mapping[start];
    }

    int num_of_decoding = 0;
    int binary_num = stoi(nums.substr(start, 2));
    if (binary_num != 10 && binary_num != 20)
    {
      num_of_decoding += get_num_of_decoding(nums, start + 1);
    }
    if (binary_num >= 1 && binary_num <= 26)
    {
      num_of_decoding += get_num_of_decoding(nums, start + 2);
    }

    decoding_mapping[start] = num_of_decoding;
    return num_of_decoding;
  }

private:
  unordered_map<int, int> decoding_mapping;
};

int main()
{
  string nums = "161";
  LetterDecoding decoder;

  int num_of_decoding = decoder.get_num_of_decoding(nums);
  cout << num_of_decoding << endl;

  return 0;
}

