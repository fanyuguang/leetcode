#include <iostream>
#include <string>
#include <unordered_map>
#include <stdlib.h>

using namespace std;

class Solution {
public:
  Solution() {
    char_sets = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    short2long.clear();
    long2short.clear();
    srand((int)time(NULL));
  }

  string rand_generator() {
    string postfix = "";
    for (int index = 0; index < 6; index++) {
      postfix += char_sets[rand() % 62];
    }
    return postfix;
  }

  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    if (long2short.find(longUrl) != long2short.end()) {
      return long2short[longUrl];
    }
    string shortUrl_prefix = "http://tinyurl.com/";
    string shortUrl_postfix = rand_generator(); 
    while (short2long.find(shortUrl_postfix) != short2long.end()) {
      shortUrl_postfix = rand_generator();
    }
    string shortUrl = shortUrl_prefix + shortUrl_postfix;
    short2long[shortUrl_postfix] = longUrl;
    long2short[longUrl] = shortUrl_postfix;
    return shortUrl;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    string shortUrl_postfix = shortUrl.substr(shortUrl.rfind('/') + 1, 6);
    if (short2long.find(shortUrl_postfix) != short2long.end()) {
      return short2long[shortUrl_postfix];
    } else {
      return shortUrl;
    }
  }

private:
  string char_sets;
  unordered_map<string, string> short2long, long2short;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
int main() {
  string url = "https://leetcode.com/problems/design-tinyurl";
  string tiny_url = "http://tinyurl.com/4e9iAk";
  Solution s;
  string decode_url = s.decode(s.encode(url));
  cout << "decode url : " << decode_url << endl;
  return 0;
}
