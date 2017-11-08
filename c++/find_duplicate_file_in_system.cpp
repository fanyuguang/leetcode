#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
  vector<vector<string>> findDuplicate(vector<string>& paths) {
    unordered_map<string, vector<string>> content_filenames;
    for (string path : paths) {
      iterPath(path, content_filenames);
    }
    vector<vector<string>> duplicate_paths;
    for (pair<string, vector<string>> iter : content_filenames) {
      vector<string> filenames = iter.second;
      if (filenames.size() > 1) {
        duplicate_paths.push_back(filenames);
      }
    }
    return duplicate_paths;
  }

private:
  void iterPath(string& str, unordered_map<string, vector<string>>& content_filenames) {
    istringstream stream_str(str);
    string sub_str;
    string path;
    while (getline(stream_str, sub_str, ' ')) {
      if (path.empty()) {
        path = sub_str + "/";
        continue;
      }
      sub_str = sub_str.substr(0, sub_str.size() - 1);
      size_t split_index = sub_str.rfind("(");
      string filename = path + sub_str.substr(0, split_index);
      string content = sub_str.substr(split_index + 1, sub_str.size());
      if (content_filenames.find(content) == content_filenames.end()) {
        content_filenames[content] = vector<string>();
      }
      content_filenames[content].push_back(filename);
    }
  }
};

int main() {
  vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
  Solution s;
  vector<vector<string>> result = s.findDuplicate(paths);
  for (vector<string> filenames : result) {
    for (string filename : filenames) {
      cout << filename << " ";
    }
    cout << endl;
  }
  return 0;
}
