/**
148[M]. Sort List
Sort a linked list in O(n log n) time using constant space complexity.
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
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode *mid=findMiddle(head);
        ListNode *right=sortList(mid->next);
        mid->next=NULL;
        ListNode *left=sortList(head);
        return mergeList(left, right);
   }
   ListNode *findMiddle(ListNode *head)
   {
       if(head==NULL||head->next==NULL) return head;
       ListNode *fast=head->next;
       ListNode *slow=head;
       while(fast&&fast->next)
       {
           fast=fast->next->next;
           slow=slow->next;
       }
       return slow;
   }
   ListNode* mergeList(ListNode *l1, ListNode *l2)
   {
       ListNode dummy(-1);
       ListNode *prev=&dummy;
       while(l1||l2)
       {
           if(l1&&l2)
           {
              if(l1->val>l2->val)
              {
                 prev->next=l2;
                 l2=l2->next;
              }
              else
              {
                 prev->next=l1;
                 l1=l1->next;
              }
           }
           else if(l1)
           {
              prev->next=l1;
              l1=l1->next;
           }
           else
           {
              prev->next=l2;
              l2=l2->next;
           }
           prev=prev->next;
       }
       return dummy.next;
   }
};

