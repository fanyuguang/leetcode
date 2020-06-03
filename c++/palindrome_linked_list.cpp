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
  bool isPalindrome(ListNode* head)
  {
    if (head == NULL || head->next == NULL)
    {
      return true;
    }

    ListNode* fast = head;
    ListNode* slow = head;
    while(fast != NULL && fast->next != NULL)
    {
      fast = fast->next->next;
      slow = slow->next;
    }

    if (fast != NULL)
    {
      slow = slow->next;
    }

    ListNode* pre= NULL;
    ListNode* next = NULL;
    while (slow != NULL)
    {
      next = slow->next;
      slow->next = pre;
      pre = slow;
      slow = next;
    }
    
    fast = pre;
    slow = head;
    while(fast != NULL && slow != NULL)
    {
      if (fast->val != slow->val)
      {
        return false;
      }
      fast = fast->next;
      slow = slow->next;
    }
    return true;
  }
};

int main()
{
  ListNode* node1 = new ListNode(0);
  ListNode* node2 = new ListNode(0);
  // ListNode* node3 = new ListNode(2);
  // ListNode* node4 = new ListNode(1);
  node1->next = node2;
  // node2->next = node3;
  // node3->next = node4;

  Solution s;
  bool result = s.isPalindrome(node1);
  if (result)
  {
    cout << "true" << endl;
  }
  else
  {
    cout << "false" << endl;
  }

  delete node1;
  delete node2;
  // delete node3;
  // delete node4;
  return 0;
}
