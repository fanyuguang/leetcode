#include <iosteam>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
  vector<vector<string>> findDuplicate(vector<string>& paths) {
    vector<string> record_duplicate;
    map<string, string> content_filename;
    for (string path : paths) {
      
  }

private:
  vector<string> split(string& str, string& token) {
    vector<string> segment_str;
    pos = str.find(token);
    while (pos != string::npos) {
      segment_str.
};

int main() {
  vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"}
  Solution s;
  vector<vector<string> > result = s.findDuplicate(paths);
  for (vector<string> duplicate_group : result) {
    for (string filename : result) {
      cout << filename << " ";
    }
    cout << endl;
  }
  return 0;
}
