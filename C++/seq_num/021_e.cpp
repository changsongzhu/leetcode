/**
21[E]. Merge Two Sorted Lists
 
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Priority_queue solution
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*> > > pq;
        if(l1) pq.push({l1->val, l1});
        if(l2) pq.push({l2->val, l2});
        ListNode dummy(-1);
        ListNode *prev=&dummy;
        while(!pq.empty())
        {
            auto p=pq.top();pq.pop();
            prev->next=p.second;
            prev=prev->next;
            if(p.second->next!=NULL) pq.push({p.second->next->val, p.second->next});
        }
        return dummy.next;
        
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode *cur  = &dummy;
        while(l1!=NULL||l2!=NULL)
        {
           if(l1!=NULL&&l2!=NULL)
           {
               if(l1->val>l2->val)
               {
                   cur->next=l1;
                   cur=l1;
                   l1=l1->next;
               }
               else
               {
                   cur->next=l2;
                   cur=l2;
                   l2=l2->next;
               }
           }
           else if(l1!=NULL)
           {
               cur->next=l1;
               cur=l1;
               l1=l1->next;
           }
           else
           {
               cur->next=l2;
               cur=l2;
               l2=l2->next;
           }
        }
        return dummy.next
    }
};

//Refined Version
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode *prev=&dummy;
        while(l1||l2)
        {
            ListNode *tmp=((l1&&l2)?(l1->val>l2->val?l2:l1):(l1?l1:l2));
            prev->next=tmp;
            prev=prev->next;
            l1=(tmp==l1?l1->next:l1);
            l2=(tmp==l2?l2->next:l2);           
        }
        return dummy.next;
        
    }
};
