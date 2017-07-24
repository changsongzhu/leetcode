/**
23[H]. Merge K Sorted Lists
 
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        ListNode * head=lists[0];
        for(int i=1;i<lists.size();i++)
            head=mergeTwoLists(head, lists[i]);
        return head;
    }
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2)
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

//Refined Version
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        ListNode * head=lists[0];
        
        for(int i=1;i<lists.size();i++)
            head=mergeTwoLists(head, lists[i]);
        return head;
    }
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2)
    {
       ListNode dummy(-1);
       ListNode *prev=&dummy;
       while(l1||l2)
       {
           prev->next=(l1&&l2)?(l1->val<l2->val?l1:l2):(l1?l1:l2);
           prev=prev->next;
           l1=l1?l1->next:l1;
           l2=l2?l2->next:l2;
       }
       return dummy.next;
    }
};
