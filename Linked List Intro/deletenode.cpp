/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* current) {
        ListNode* temp=current->next;
        current->val=temp->val;
        current->next=temp->next;
        delete temp;
    }
};
