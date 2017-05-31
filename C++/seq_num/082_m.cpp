/**
82[M]. Remove Duplicates from Sorted List II
 
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode dummy(-1);
        ListNode *prev = &dummy;
        ListNode *cur = head;
        while(cur)
        {
            if(cur->next!=NULL&&cur->val==cur->next->val)
            {
                int val=cur->val;
                while(cur&&cur->val==val)
                    cur=cur->next;
            }
            else
            {
               prev->next=cur;
               prev=cur;
               cur=cur->next;
            }
        }
        prev->next=NULL;
        return dummy.next;
   }
};

