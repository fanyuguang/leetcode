#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TrieNode {
  bool is_leaf;
  TrieNode *next_char[26];
  TrieNode() {
    for (int i = 0; i < 26; i++) {
      is_leaf = false;
      next_char[i] = NULL;
    }
  }
};

class MagicDictionary {
public:
  MagicDictionary() {
    root_node_ = new TrieNode();
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
      root_node_->next_char[i] = NULL;
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
      node->is_leaf = true;
    }
  }

  bool search(string word) {
    TrieNode* node = root_node_;
    if (word.length() == 0) {
      return false;
    }
    return RecursionSearch(node, word, 0);
  }

  bool RecursionSearch(TrieNode* node, string sub_word, int diff_count) {
    char char_index = sub_word[0] - 'a';
    for (int i = 0; i < 26; i++) {
      if (node->next_char[i] != NULL) {
        if (sub_word.length() > 1) {
          RecursionSearch(node->next_char[i], sub_word.substr(1), diff_count)
        }
      }
    }
  }

private:
  TrieNode* root_node_;
};

int main() {
  vector<string> dict = {"hello", "leetcode"};
  string word = "hhllo";
  
  MagicDictionary magic_dict;
  magic_dict.buildDict(dict);
  bool result = magic_dict.search(word);
  if (result) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
  return 0;
}
