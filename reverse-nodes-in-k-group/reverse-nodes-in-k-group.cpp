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
    int length(ListNode* head)
    {
       int count = 0;
        while (head != NULL)
        {
            count++;
            head = head->next;
        }
        return count;
    } 
    ListNode* reverseKGroup(ListNode* head, int k,int N) {
        if(N-k<0)
            return head;
        ListNode* Prev=NULL;
        ListNode* Curr=head;
        ListNode* Nxt;
        int count=0;
        while(Curr!=NULL && count<k)
        {
            Nxt=Curr->next;
            Curr->next=Prev;
            
            Prev=Curr;
            Curr=Nxt;
            count++;
        }
        
        if(Nxt!=NULL)
        {
                head->next=reverseKGroup(Nxt,k,N-k);  
        }
        
        return Prev;
        
        
    }
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int N=length(head);
        if(k==1 || N==1)
            return head;
        return reverseKGroup(head,k,N);
        
    }
};