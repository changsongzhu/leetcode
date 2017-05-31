/**
92[M]. Reverse Linked List II
 
Reverse a linked list from position m to n. Do it in-place and in one-pass.
For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.
Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n) return head;
        ListNode dummy(-1);
        ListNode *prev=&dummy;
        ListNode *cur=head;
        for(int i=0;i<m-1;i++)
        {
            prev->next=cur;
            prev=cur;
            cur=cur->next;
        }
        ListNode *last=cur;
        ListNode *last_prev=prev;
        
	prev=NULL;
        for(int i=0;i<=n-m;i++)
        {
           ListNode *tmp=cur->next;
           cur->next=prev;
           prev=cur;
           cur=tmp;
        }
        last->next=cur;
        last_prev->next=prev;
        return dummy.next;
    }
};

