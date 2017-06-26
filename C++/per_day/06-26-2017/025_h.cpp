/**
25[M]. Reverse Nodes in k-Group
 
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.
For example,
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL&&k<=1) return head;
        int cnt=0;
        ListNode dummy(-1);
        ListNode *prev= &dummy;
        prev->next=head;
        ListNode *start=head;
        ListNode *cur=head;
        while(cur){
            cnt++;
            if(cnt==k){
                ListNode *tmp=cur->next;
                cur->next=NULL;
                ListNode *node=reverseList(start);
                prev->next=node;prev=start;
                start->next=tmp;start=start->next;
                cur=tmp;
                cnt=0;
                
            }
            else{
                cur=cur->next;
            }
        }
        return dummy.next;
    }
    ListNode *reverseList(ListNode *head)
    {
        if(head==NULL) return head;
        ListNode *prev=NULL;
        ListNode *cur=head;
        while(cur){
            ListNode *tmp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=tmp;
        }
        return prev;
    }
};

