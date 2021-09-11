
class Solution {
public:
    int length(ListNode *head)
    {
        int count = 0;
        while (head != NULL)
        {
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0||!head || !head->next)
            return head;
        ListNode* slow=head;
        ListNode* fast=head;
         k=k%length(head);
        while(k--)
        {
            fast=fast->next;
        }
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        fast->next=head;
        head=slow->next;
        slow->next=NULL;
        return head;
    }
};