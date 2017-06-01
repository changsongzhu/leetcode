/**
147[M]. Insertion Sort List
Sort a linked list using insertion sort.
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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode dummy(-1);
        ListNode *cur=&dummy;
        while(head)
        {
            cur=&dummy;
            while(cur->next&&cur->next<head->val)
                cur=cur->next;
            ListNode *tmp=cur->next;
            cur->next=head;
            head=head->next;
            cur->next->next=tmp;
        }
        return dummy.next;
   }
};

