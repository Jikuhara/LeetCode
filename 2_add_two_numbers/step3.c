/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	#define BASE_NUM 10;
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode dummy_head = ListNode();
		ListNode *result_tail = &dummy_head;
		int curry = 0;
		while (l1 || l2 || curry)
		{
			int val = curry;
			if (l1)
			{
				val += l1->val;
				l1 = l1->next;
			}
			if (l2)
			{
				val += l2->val;
				l2 = l2->next;
			}
			curry = val / BASE_NUM;
			val = val % BASE_NUM;
			result_tail = new ListNode(val);
			result_tail = result_tail->next;
		}
		return dummy_head.next;
	}
};
