class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head||!head->next)
            return;
       ListNode* slow=head;
       ListNode* fast=head;
       while(fast!=NULL && fast->next!=NULL) 
       {
           slow=slow->next;
           fast=fast->next->next;
       }
        
        ListNode* Prev=NULL;
        ListNode* Curr=slow;
        ListNode* Nxt;
        
        while(Curr!=NULL)
        {
            Nxt=Curr->next;
            Curr->next=Prev;
            Prev=Curr;
            Curr=Nxt;
        }
        
        ListNode* l1=head;
        ListNode* l2=Prev;
        while(l2->next!=NULL)
        {
            ListNode* temp=l1->next;
            l1->next=l2;
            l1=temp;
            
            temp=l2->next;
            l2->next=l1;
            l2=temp;
        }
    }
};