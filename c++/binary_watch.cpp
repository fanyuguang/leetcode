#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  Solution() {
    for (int i = 0; i < 12; i++) {
      int one_bits = count_one_bits(i);
      if (hours.find(one_bits) == hours.end()) {
        vector<string> num_str = {to_string(i)};
        hours[one_bits] = num_str;
      } else {
        hours[one_bits].push_back(to_string(i));
      }
    }
    for (int i = 0; i < 60; i++) {
      int one_bits = count_one_bits(i);
      string num_str = to_string(i);
      if (i < 10) {
        num_str = "0" + num_str;
      }
      if (minutes.find(one_bits) == minutes.end()) {
        vector<string> nums_str = {num_str};
        minutes[one_bits] = nums_str;
      } else {
        minutes[one_bits].push_back(num_str);
      }
    }
  }

  vector<string> readBinaryWatch(int num) {
    vector<string> binary_watch;
    for (int hour = 0; hour <= num; hour++) {
      int minute = num - hour;
      if (hour > 4 || minute > 6) {
        continue;
      }
      for (string hour_str : hours[hour]) {
        for (string minute_str : minutes[minute]) {
          binary_watch.push_back(hour_str + ":" + minute_str);
        }
      }
    }
    return binary_watch;
  }

private:
  int count_one_bits(int num) {
    int count = 0;
    while (num > 0) {
      if (num & 1) {
        count++;
      }
      num = num >> 1;
    }
    return count;
  }

  unordered_map<int, vector<string>> hours;
  unordered_map<int, vector<string>> minutes;
};

int main() {
  Solution s;
  vector<string> result = s.readBinaryWatch(1);
  for (string str : result) {
    cout << str << endl;
  }
  return 0;
}
