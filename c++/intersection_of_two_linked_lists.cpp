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

    ListNode* a = headA;
    ListNode* b = headB;
    int a_length = 1;
    int b_length = 1;
    while (a->next != NULL)
    {
      a = a->next;
      a_length++;
    }
    while (b->next != NULL)
    {
      b = b->next;
      b_length++;
    }
    if (a != b)
    {
      return NULL;
    }

    a = headA;
    b = headB;
    if (a_length > b_length)
    {
      for (int i = 0; i < a_length - b_length; i++)
      {
        a = a->next;
      }
    }
    else
    {
      for (int i = 0; i < b_length - a_length; i++)
      {
        b = b->next;
      }
    }
    while (a != b)
    {
      a = a->next;
      b = b->next;
    }
    return a;
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

  delete node_a_1;
  delete node_a_2;
  delete node_a_3;
  delete node_a_4;
  delete node_a_5;
  delete node_b_1;
  delete node_b_2;
  delete node_b_3;
  return 0;
}
