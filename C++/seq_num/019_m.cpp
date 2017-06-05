/**19[M]. Remove Nth Node from the end of the list
 
Given a linked list, remove the nth node from the end of list and return its head.
For example,
Given linked list: 1->2->3->4->5, and n = 2. 	
After removing the second node from the end, the linked list becomes
1->2->3->5.
Note:
Given n will always be valid. Try to do this in one pass.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
        ListNode dummy(-1);
        dummy.next=head;
        ListNode *prev=&dummy;
        ListNode *fast=head;
        for(int i=0;i<n;i++)
            fast=fast->next;
        ListNode *slow=head;
        while(fast)
        {
            fast=fast->next;
            prev=slow;
            slow=slow->next;
        }
        prev->next=slow->next;
        return dummy.next;
    }
};
