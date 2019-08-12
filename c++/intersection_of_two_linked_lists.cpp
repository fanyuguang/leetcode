#include<iostream>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == NULL || headB == NULL)
    {
      return NULL;
    }

  }
};

int main()
{
  ListNode* node_a_1 = new ListNode(4);
  ListNode* node_a_2 = new ListNode(1);
  ListNode* node_a_3 = new ListNode(8);
  ListNode* node_a_4 = new ListNode(4);
  ListNode* node_a_5 = new ListNode(5);
  ListNode* node_b_1 = new ListNode(5);
  ListNode* node_b_2 = new ListNode(0);
  ListNode* node_b_3 = new ListNode(1);
  node_a_1->next = node_a_2;
  node_a_2->next = node_a_3;
  node_a_3->next = node_a_4;
  node_a_4->next = node_a_5;
  node_b_1->next = node_b_2;
  node_b_2->next = node_b_3;
  node_b_3->next = node_a_3;

  Solution s;
  ListNode* intersection_node = s.getIntersectionNode(node_a_1, node_b_1);
  cout << intersection_node->val << endl;
  return 0;
}
