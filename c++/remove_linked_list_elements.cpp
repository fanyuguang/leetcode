#include <iostream>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(NULL) {}
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode* removeElements(ListNode* head, int val)
  {
    ListNode *pre_head = new ListNode();
    pre_head->next = head;

    ListNode *pre = pre_head;
    ListNode *node = head;
    while (node != NULL)
    {
      if (node->val == val)
      {
        ListNode *temp = node;
        node = node->next;
        pre->next = node;
        delete temp;
      }
      else
      {
        pre = pre->next;
        node = node->next;
      }
    }
    node = pre_head->next;
    delete pre_head;
    return node;
  }
};

int main()
{
  ListNode *node1 = new ListNode(1);
  ListNode *node2 = new ListNode(2);
  ListNode *node3 = new ListNode(6);
  ListNode *node4 = new ListNode(3);
  ListNode *node5 = new ListNode(4);
  ListNode *node6 = new ListNode(5);
  ListNode *node7 = new ListNode(6);

  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;
  node5->next = node6;
  node6->next = node7;

  Solution s;
  ListNode* node = s.removeElements(node1, 6);
  while (node != NULL && node->next != NULL)
  {
    cout << node->val << " -> ";
    node = node->next;
  }
  cout << node->val << endl;

  delete node1;
  delete node2;
  delete node3;
  delete node4;
  delete node5;
  delete node6;
  delete node7;

  return 0;
}
