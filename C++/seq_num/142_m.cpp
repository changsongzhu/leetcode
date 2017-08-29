/**
142[M]. Linked List Cycle 2
 
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Note: Do not modify the linked list.
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
    ListNode *detectCycle(ListNode *head) {
       if(head==NULL||head->next==NULL) return NULL;
       ListNode *fast=head->next->next;
       ListNode *slow=head->next;
       while(fast&&fast->next)
       {
           fast=fast->next->next;
           slow=slow->next;
           if(fast==slow) break;
       }
       if(fast!=slow) return NULL; //no cylce
       fast=head;
       while(fast!=slow)
       {
           fast=fast->next;
           slow=slow->next;
       }
       return fast;
   }
};

