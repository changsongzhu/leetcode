/**

2[M]. Add Two Numbers
 
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       int carry=0;
       ListNode dummy(-1);
       ListNode *prev=&dummy;
       while(l1||l2)
       {
           int val=0;
           if(l1&&l2)
           {
               val=l1->val+l2->val+carry;
               l1=l1->next;
               l2=l2->next;
           }
           else if(l1)
           {
               val=l1->val+carry;
               l1=l1->next;
           }
           else
           {
               val=l2->val+carry;
               l2=l2->next;
           }
           carry=val/10;
           val=val%10;
           ListNode *node=new ListNode(val);
           prev->next=node;
           prev=node;
       }
       if(carry)
       {
           ListNode *node = new ListNode(carry);
           prev->next=node;
       }
       return dummy.next;
    }
};

//Refined Version
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode dummy(-1);
        ListNode *prev=&dummy;
        while(l1||l2)
        {
            int val=(l1?l1->val:0)+(l2?l2->val:0)+carry;
            prev->next=new ListNode(val%10);
            prev=prev->next;
            carry=val/10;
            l1=(l1?l1->next:l1);
            l2=(l2?l2->next:l2);
        }
        if(carry) prev->next=new ListNode(carry);
        return dummy.next;
    }
};

