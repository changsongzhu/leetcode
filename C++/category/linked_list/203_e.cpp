/**
203[E]. Remove Linked List Element
 
Remove all elements from a linked list of integers that have value val.
Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(-1);
        ListNode *prev=&dummy;
        ListNode *cur=head;
        while(cur)
        {
            if(cur->val==val)
            {
                cur=cur->next;
            }
            else
            {
                prev->next=cur;
                prev=cur;
                cur=cur->next;
                prev->next=NULL;
            }
        }
        return dummy.next;
    }
};
