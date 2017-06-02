/**
24[M]. Swap Nodes in Pair
 
Given a linked list, swap every two adjacent nodes and return its head.
For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.
Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
       ListNode dummy(-1);
       dummy.next=head;
       ListNode *prev=&dummy;
       ListNode *cur=head;
       while(cur&&cur->next)
       {
          ListNode *tmp=cur->next->next;
          prev->next=cur->next;
          cur->next->next=cur;
          prev=cur;
          cur->next=tmp;
          cur=tmp;
       }
       return dummy.next;
    }
};

