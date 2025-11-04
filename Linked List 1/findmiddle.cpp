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
    ListNode* middleNode(ListNode* head) {
        // Counting total nodes Priyank
        ListNode* current=head;
        int n=0;
        while(current!=NULL)
        {
            current=current->next;
            n++;
        }

        int search=n/2+1;
        current=head;
        n=1;
        while(current!=NULL)
        {
            if(search==n)
            break;
            current=current->next;
            n++;
        }
        return current;
    }
};