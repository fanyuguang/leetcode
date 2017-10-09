#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
		node->val = node->next->val;
		ListNode* copy_node = node->next;
		node->next = node->next->next;
		free(copy_node);
    }
};

int main()
{

	ListNode* list_node1 = new ListNode(1);
	ListNode* list_node2 = new ListNode(2);
	ListNode* list_node3 = new ListNode(3);
	ListNode* list_node4 = new ListNode(4);
	list_node1->next = list_node2;
	list_node2->next = list_node3;
	list_node3->next = list_node4;

	Solution s;
	s.deleteNode(list_node3);

	for (ListNode* temp_node = list_node1; temp_node != NULL; temp_node = temp_node->next)
	{
		cout << temp_node->val << endl;
	}

	return 0;
}
