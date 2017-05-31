/**
61[M]. Rotate List
 
Given a list, rotate the list to the right by k places, where k is non-negative.
For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
**/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==0) return head;
        ListNode dummy(-1);
        dummy.next=head;
        ListNode *prev=&dummy;
        ListNode *fast=head;
        int len=0;
        ListNode *cur=head;
        while(cur)
        {
            len++;
            cur=cur->next;
        }
        k=k%len;
        if(k==0) return dummy.next;

        for(int i=0;i<=k;i++)
        {
            prev=fast;
            fast=fast->next;
        }
        ListNode *slow=head;
        while(fast)
        {
           prev=fast;
           fast=fast->next;
           slow=slow->next;
        }
        prev->next=dummy.next;
        dummy.next=slow->next;
        slow->next=NULL;
        return dummy.next;
    }
};

