/**
83[E]. Remove Duplicates from Sorted List
 
Given a sorted linked list, delete all duplicates such that each element appear only once.
For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

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
        ListNode dummy(-1);
        ListNode *cur = &dummy;
        int prev_val=0;
        bool flag=false;
        while(head)
        {
            if(flag==false)
            {
                cur->next=head;
                cur=head;
                head=head->next;
                cur->next=NULL;
                prev_val=cur->val;
                flag=true;
            }
            else
            {
                if(head->val==prev_val)
                {
                    head=head->next;
                }
                else
                {
                    cur->next=head;
                    cur=head;
                    head=head->next;
                    cur->next=NULL;
                    prev_val=cur->val;
                }
            }
        }
        return dummy.next;
    }
};


//Refined Version
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(-1);
        ListNode *prev_node=&dummy;
        ListNode *cur=head;
        while(cur)
        {
            if(prev_node==&dummy||prev_node->val!=cur->val)
            {
                prev_node->next=cur;
                prev_node=cur;
                cur=cur->next;
            }
            else if(prev_node->val==cur->val)
            {
                cur=cur->next;
            }
        }
        prev_node->next=NULL;
        return dummy.next;
    }
};
