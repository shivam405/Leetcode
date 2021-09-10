/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode* head)
    {
        if(head==NULL)
        {
            return 0;
        }
        int count=0;
        while(head!=NULL)
        {
            head=head->next;
            count++;
        }
        return count;
    }

    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=length(headA);
        int len2=length(headB);
        int d=0;
        ListNode* itr1;
        ListNode* itr2;

        if(len1>len2)
        {
            itr1=headA;
            itr2=headB;
            d=len1-len2;
        }
        else
        {
            itr1=headB;
            itr2=headA;
            d=len2-len1;
        }

        while(d)
        {
            itr1=itr1->next;
            if(itr1==NULL)
            return NULL;
            d--;
        }

        while(itr1!=NULL && itr2!=NULL)
        {
            if(itr1==itr2)
            return itr1;
            itr1=itr1->next;
            itr2=itr2->next;
        }

        return NULL;
        
    }
};