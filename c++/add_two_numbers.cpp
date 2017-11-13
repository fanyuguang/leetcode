#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = l1;
    int carry = 0;
    while (l1 != NULL && l2 != NULL) {
      int sum = l1->val + l2->val + carry;
      l1->val = sum % 10;
      carry = sum / 10;
      cout << "sum: " << sum  << " l1: " << l1->val << " carry: " << carry << endl;
      if (l1->next == NULL || l2->next == NULL) {
        break;
      }
      l1 = l1->next;
      l2 = l2->next;
    }
    if (l2->next != NULL) {
      l1->next = l2->next;
    }
    while (l1 != NULL) {
      int sum = l1->val + carry;
      l1->val = sum % 10;
      carry = sum / 10;
      if (l1->next == NULL) {
        break;
      }
      l1 = l1->next;
    }
    if (carry > 0) {
      ListNode* tail_node = new ListNode(carry);
      l1->next = tail_node;
    }
    return head;
  }
};

int main() {
  ListNode* node1 = new ListNode(2);
  ListNode* node2 = new ListNode(4);
  ListNode* node3 = new ListNode(3);
  node1->next = node2;
  node2->next = node3;
  ListNode* node4 = new ListNode(5);
  ListNode* node5 = new ListNode(6);
  ListNode* node6 = new ListNode(4);
  node4->next = node5;
  node5->next = node6;
  Solution s;
  ListNode* node = s.addTwoNumbers(node1, node4);
  while (node != NULL) {
    cout << node->val << endl;
    node = node->next;
  }
  delete node1;
  delete node2;
  delete node3;
  delete node4;
  delete node5;
  delete node6;
  return 0;
}
