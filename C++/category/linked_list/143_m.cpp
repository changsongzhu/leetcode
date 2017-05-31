/**
143[M]. Reorder Linked List
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
You must do this in-place without altering the nodes' values.
For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL) return;
        ListNode *middle=findMiddle(head);
        ListNode *right=reverseList(middle->next);
        middle->next=NULL;
        mergeList(head, right);

    }
    ListNode *findMiddle(ListNode* head){
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast&&fast->next){
            fast=fast->next->next;slow=slow->next;
        }
        return slow;
    }
    ListNode *reverseList(ListNode* head){
        ListNode *prev=NULL;
        ListNode *cur=head;
        while(cur){
            ListNode *tmp=cur->next;cur->next=prev;prev=cur;cur=tmp;
        }
        return prev;
    }
    ListNode *mergeList(ListNode *l1, ListNode* l2){
        ListNode dummy(-1);
        ListNode *prev=&dummy;
        while(l1||l2){
            if(l1&&l2){
                prev->next=l1;l1=l1->next;prev->next->next=l2;prev=l2;l2=l2->next;
            }
            else if(l1){
                prev->next=l1;prev=l1;l1=l1->next;
            }
            else{
                prev->next=l2;prev=l2;l2=l2->next;
            }
        }
        return dummy.next;
    }
};

