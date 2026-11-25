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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head, *prev = new ListNode(0);
        prev->next = head; ListNode* ans = prev;
        while (cur) {
            if (cur->next && cur->val == cur->next->val) {
                int val = cur->val;
                while (cur && cur->val == val) cur = cur->next;
                prev->next = cur;
            }
            else {
                prev = prev->next;
                cur = cur->next;
            }
        }
        return ans->next;
    }
};