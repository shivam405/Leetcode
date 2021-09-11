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
     ListNode* reverse(ListNode *head)
    {
        if(head->next==NULL|| head==NULL)
        return head;
        ListNode *prev = NULL;
        ListNode *Curr = head;
        ListNode *Nxt;
        while (Curr != NULL)
        {
            //save the next node
            Nxt = Curr->next;
            //make the curr node point to prev
            Curr->next = prev;
    
            //update prev and curr take them 1 step
            prev = Curr;
            Curr = Nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL|| head==NULL)
        return true;
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);
        slow=slow->next;
        fast=head;
        while(slow!=NULL)
        {
            if(fast->val!=slow->val)
            return false;
            fast=fast->next;
            slow=slow->next;
        }
        return true;
    }
};