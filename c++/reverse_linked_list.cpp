#include <iostream>

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
    ListNode* reverseList(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* pre_iter_node = head;
        ListNode* iter_node = head->next;
        ListNode* next_iter_node = iter_node->next;
        pre_iter_node->next = NULL;
        iter_node->next = pre_iter_node;
        while (next_iter_node != NULL)
        {
            pre_iter_node = iter_node;
            iter_node = next_iter_node;
            next_iter_node = next_iter_node->next;
            iter_node->next = pre_iter_node;
        }
        return iter_node;
    }
};

int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    Solution s;
    ListNode* new_list = s.reverseList(node1);
    ListNode* iter_node = new_list;
    while (iter_node != NULL)
    {
        cout << iter_node->val << endl;
        iter_node = iter_node->next;
    }
    return 0;
}
