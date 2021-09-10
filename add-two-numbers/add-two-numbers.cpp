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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum,Carry=0;
        ListNode *Pseudohead=new ListNode();
        ListNode *copy=Pseudohead;
        while(l1!=NULL || l2!=NULL || Carry)
        {
            if(l1==NULL && l2==NULL)
            {
               sum=(Carry); 
            }
                
            else if(l2==NULL)
            {
                sum=(l1->val+Carry);
                l1=l1->next;
            }
                
            else if(l1==NULL) 
            {
                sum=(l2->val+Carry);
                l2=l2->next;
                
            }
            else
            {
                sum=(l1->val+l2->val+Carry);
                l1=l1->next;
                l2=l2->next;
            }
            Carry=sum/10;
            ListNode *temp=new ListNode(sum%10);
            copy->next=temp;
            copy=copy->next;
        }
       return Pseudohead->next; 
    }
};