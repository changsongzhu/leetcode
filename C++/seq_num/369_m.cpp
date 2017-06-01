/**
369[M]. Plus One Lined List
Given a non-negative number represented as a singly linked list of digits, plus one to the number.
The digits are stored such that the most significant digit is at the head of the list.
Example:
Input: 1->2->3 
Output: 1->2->4
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
    ListNode* plusOne(ListNode* head) {
       int carry=helper(head);
       if(carry)
       {
           ListNode *node = new ListNode(carry);
           node->next=head;
           return node;
       }
       else
       {
           return head;
       }

    }
    int helper(ListNode*head)
    {
       if(head==NULL) return 1;
       int carry=helper(head->next);
       int val=head->val+carry;
       head->val=val%10;
       carry=val/10;
       return carry;
    }
};

