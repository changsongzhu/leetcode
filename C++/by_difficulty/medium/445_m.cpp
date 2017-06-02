/***
445[M]. Add Two Numbers II
 
You are given two linked lists representing two non-negative numbers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
Example:
Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
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
       l1=reverseList(l1);
       l2=reverseList(l2);
       ListNode dummy(-1);
       ListNode *prev=&dummy;
       int carry=0;
       while(l1||l2){
           int val=0;
           if(l1&&l2){
             val=l1->val+l2->val+carry;l1=l1->next;l2=l2->next;
           }
           else if(l1){
             val=l1->val+carry;l1=l1->next;
           }
           else{
             val=l2->val+carry;l2=l2->next;
           }
           carry=val/10;
           val=val%10;
           ListNode *node=new ListNode(val);
           prev->next=node;
           prev=node;
 
       }
       if(carry){
           ListNode *node=new ListNode(carry);
           prev->next=node;
       } 
       return reverseList(dummy.next);
    }
    ListNode * reverseList(ListNode* head)
    {
        if(head==NULL||head->next==NULL) return head;
        ListNode* prev=NULL;
        while(head){
            ListNode *tmp=head->next;
            head->next=prev;prev=head;head=tmp;
        }
        return prev;
    }
};

