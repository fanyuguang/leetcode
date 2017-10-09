#include <iostream>
#include <string>

using namespace std;

struct TrieNode {
  TrieNode *next_char[26];
  int val;
  bool is_str;
  TrieNode(int x, bool str_flag) {
    val = x;
    is_str = str_flag;
    for (int i = 0; i < 26; i++) {
      next_char[i] = NULL;
    }
  }
};

class MapSum {
public:
  MapSum() {
    head = new TrieNode(0, false);
  }

  void insert(string key, int val) {
    TrieNode* iter = head;
    for (char c : key) {
      int char_index = (int)(c - 'a');
      if (iter->next_char[char_index] == NULL) {
        TrieNode *node = new TrieNode(0, false);
        iter->next_char[char_index] = node;
      }
      iter = iter->next_char[char_index];
    }
    iter->val = val;
    iter->is_str = true;
  }

  int sum(string prefix) {
    TrieNode* iter = head;
    for (char c : prefix) {
      int char_index = (int)(c - 'a');
      if (iter->next_char[char_index] == NULL) {
        return 0;
      }
      iter = iter->next_char[char_index];
    }
    return deep_sum(iter);
  }

  int deep_sum(TrieNode* node) {
    int val_sum = node->val;
    for (int i = 0; i < 26; i++) {
      if (node->next_char[i] != NULL) {
        val_sum += deep_sum(node->next_char[i]);
      }
    }
    return val_sum;
  }

private:
  TrieNode* head;
};

int main() {
  MapSum obj;
  obj.insert("a", 3);
  int param_2 = obj.sum("ap");
  obj.insert("b", 2);
  int param_3 = obj.sum("a");
  cout << param_2 << endl;
  cout << param_3 << endl;
  return 0;
}
