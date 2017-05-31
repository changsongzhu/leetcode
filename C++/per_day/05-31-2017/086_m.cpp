/**
86[M]. Parition List
 
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
    ListNode* partition(ListNode* head, int x) {
       if(head==NULL||head->next==NULL) return head;
       ListNode dummy_s(-1);
       ListNode dummy_b(-1);
       ListNode *prev_s=&dummy_s;
       ListNode *prev_b=&dummy_b;
       while(head)
       {
          if(head->val<x)
          {
              prev_s->next=head;
              prev_s=head;
          }
          else
          {
              prev_b->next=head;
              prev_b=head;
          }
          head=head->next;
       }
       if(dummy_s.next&&dummy_b.next)
       {
           prev_s->next=dummy_b.next;
           prev_b->next=NULL;
           return dummy_s.next;
       }
       else
       {
           return (dummy_s.next)?dummy_s.next:dummy_b.next;
       }
   }
};
