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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode* head=NULL;
        ListNode* tail=NULL;



        while(head1!=NULL && head2!=NULL)
        {
            ListNode* temp;
            if(head1->val>head2->val)
            {
                temp=head2;
                if(head==NULL)
                {
                    head=temp;
                    tail=temp;
                    
                    head2=head2->next;
                }
                else{
                    tail->next=head2;
                    tail=tail->next;
                    head2=head2->next;
                }

            }
            else
            {
                temp=head1;
                if(head==NULL)
                {
                    head=temp;
                    tail=temp;
                    
                    head1=head1->next;
                }
                else{
                    tail->next=head1;
                    tail=tail->next;
                    
                    head1=head1->next;
                }
            }
        }
                if (tail != NULL) {
            if (head1 != NULL) tail->next = head1;
            else if (head2 != NULL) tail->next = head2;
        } else {
            head = (head1 != NULL) ? head1 : head2;
        }
        return head;       
    }
};
