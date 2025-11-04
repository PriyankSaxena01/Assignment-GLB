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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head==NULL || head->next==NULL)
        return head;
        int rotate=1;

        // Calculating no of nodes;
        int totalterms=0;
        ListNode* temp = head;
        while (temp != NULL) 
        {
            temp = temp->next;
            totalterms++;
        }

        // SWAP AFTER REMOVING REPETITION
        // if(k>totalterms){
            k=k%totalterms;
        // }

        while(rotate<=k)
        {
         int n = 0;
        ListNode* current = head;
        while (current != NULL) 
        {
            current = current->next;
            n++;
        }
        current=head;
        for(int i=1;i<n-1;i++)
        {
            current=current->next;
        }
        ListNode* fut=current->next;
        current->next=NULL;
        current=fut;
        current->next=head;
        head=current;
        rotate++;
        }
        return head;
    }
};