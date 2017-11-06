#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TrieNode {
  TrieNode *next_char[26];
  TrieNode() {
    for (int i = 0; i < 26; i++) {
      next_char[i] = NULL;
    }
  }
};

class MagicDictionary {
public:
  MagicDictionary() {
    root_node = new TrieNode();
  }

  void clearSubDict(TrieNode* node) {
    for (int i = 0; i < 26; i++) {
      if (node->next_char[i] != NULL) {
        clearSubDict(node->next_char[i]);
      }
    }
    delete node;
  }

  void clearDict() {
    for (int i = 0; i < 26; i++) {
      if (root_node_->next_char[i] != NULL) {
        clearSubDict(root_node_->next_char[i]);
      }
    }
  }

  void buildDict(vector<string> dict) {
    clearDict();
    for (string str : dict) {
      TrieNode* node = root_node_;
      for (char c : str) {
        int char_index = c - 'a';
        if (node->next_char[char_index] == NULL) {
          TrieNode* c_node = new TrieNode();
          node->next_char[char_index] = c_node;
        }
        node = node->next_char[char_index];
      }
    }
  }

  bool search(string word) {
    TrieNode* node = root_node_;
    for (char c : word) {
      int char_index = c - 'a';
      if (node->next_char[char_index] == NULL) {
        return false;
      }
    }
    for (int i = 0; i < 26; i++) {
      if (node->next_char[i] != NULL) {
        return false;
      }
    }
    return true;
  }

private:
  TreeNode* root_node_;
};

int main() {
  vector<string> dict = {"hello", "leetcode"};
  string word = "hhllo";
  
  MagicDictionary magic_dict = new MagicDictionary();
  magic_dict.buildDict(dict);
  bool result = magic_dict.search(word);
  if (result) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
  return 0;
}
