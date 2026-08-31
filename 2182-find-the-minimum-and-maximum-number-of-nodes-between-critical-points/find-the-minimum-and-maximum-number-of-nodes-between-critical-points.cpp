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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1, next = -1, idx = 0;
        int mini = INT_MAX, maxi = INT_MIN;
        ListNode* prev = NULL, *temp = head;
        while (temp->next){
            if (prev){
                if ((prev->val > temp->val && temp->next->val > temp->val) || (prev->val < temp->val && temp->next->val < temp->val)) {
                    if (first == -1) {first = idx; next = idx;}
                    else {
                        mini = min(mini, idx-next);
                        next = idx;
                    }
                }
            }
            idx++;
            prev = temp;
            temp = temp->next;
        }
        if (first == -1 || first == next) return {-1, -1};
        maxi = next - first;
        return {mini, maxi};
    }
};