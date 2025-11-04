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
      ListNode* current=head;
      ListNode* prev=NULL;
      while(current!=NULL)
      {
        if(prev!=NULL && current->val==prev->val)
        {
            prev->next=current->next;
            current=current->next;
        }
        else{
            prev=current;
            current=current->next;
        }
      }  
      return head;
    }
};
