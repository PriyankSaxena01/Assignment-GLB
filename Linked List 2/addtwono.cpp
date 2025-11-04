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
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        ListNode* current1=head1;
        ListNode* current2=head2;
        int ans;
        int node1=0;
        while(current1!=NULL)
        {
            node1++;
            current1=current1->next;
        }
        int node2=0;
        while(current2!=NULL)
        {
            node2++;
            current2=current2->next;
        }

        current1=head1;
        current2=head2;
        ListNode* Last;
        int extra=0;
        while(current1!=NULL || current2!=NULL)
        {
            if(node2>node1)
            {
                if(current1!=NULL)
                ans=current2->val+current1->val+extra;
                else
                ans=current2->val+extra;
                if(ans>9)
                {
                    current2->val=ans%10;
                    extra=1;
                }
                else
                {
                    current2->val=ans;
                    extra=0;
                }
                if(current1!=NULL)
                current1=current1->next;
                if(current2->next==NULL)
                Last=current2;
                current2=current2->next;
                
            }
            else
            {   
                
                if(current2!=NULL)
                ans=current2->val+current1->val+extra;
                else
                ans=current1->val+extra;


                if(ans>9)
                {
                    current1->val=ans%10;
                    extra=1;
                }
                else
                {
                    current1->val=ans;
                    extra=0;
                }
                if(current1->next==NULL)
                Last=current1;
                current1=current1->next;
                if(current2!=NULL)
                current2=current2->next;
            }

        }

        if(extra==1)
       Last->next=new ListNode(1);
        
        
        if(node2>node1) return head2; 
        else return head1; 
        
    }
};