/**

234[E]. Palindrome List
Given a singly linked list, determine if it is a palindrome.

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
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL) return true;

        //find the mid
        ListNode *fast=head, *slow=head;
        while(fast->next&&fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *last=slow->next, *pre=head;
        while(last->next)
        {
            ListNode *tmp=last->next;
            last->next=tmp->next;
            tmp->next=slow->next;
            slow->next=tmp;
        }
        ListNode *mid=slow->next;
        while(mid)
        {
            if(pre->val!=mid->val) return false;
            pre=pre->next;
            mid=mid->next;
        }
	last=slow->next;
        while(last->next)
        {
            ListNode *tmp=last->next;
            last->next=tmp->next;
            tmp->next=slow->next;
            slow->next=tmp;
        }        
        return true;
    }
};
