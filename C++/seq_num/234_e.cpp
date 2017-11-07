/**

234[E]. Palindrome List
Given a singly linked list, determine if it is a palindrome.

**/


//Space Complexity (O(n)) Solution
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
        ListNode *cur=head;
        vector<int> res;
        while(cur)
        {
            res.push_back(cur->val);
            cur=cur->next;
        }
        int left=0, right=res.size()-1;
        while(left<right)
        {
            if(res[left++]!=res[right--]) return false;
        }
        return true;
        
    }
};


class Solution {
public:
    bool isPalindrome(ListNode *head){
        if(head==NULL||head->next==NULL) return true;

        ListNode *mid=findMiddle(head);
        ListNode *right=reverseList(mid->next);
        mid->next=NULL;
        ListNode *p=head;
        ListNode *q=right;
        while(p&&q)
        {
            if(p->val!=q->val) return false;
            p=p->next;
            q=q->next;
        }
        ListNode *node=reverseList(right);
        mid->next=node;
        return true;
    }
    ListNode *findMiddle(ListNode *head){
        ListNode *fast=head->next;//let the fast move one more step
        ListNode *slow=head;
        while(fast&&fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode *reverseList(ListNode *head){
        ListNode *prev=NULL;
        ListNode *cur=head;
        while(cur)
        {
            ListNode *tmp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=tmp;
        }
        return prev;
    }
};


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
