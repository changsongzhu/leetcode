/**138[M]. Copy List with Random Pointer
 
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.
**/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head){
        if(head==NULL) return NULL;
        map<RandomListNode*, RandomListNode*> m;
        RandomListNode *newHead= new RandomListNode(head->label);
        RandomListNode *p=head;
        RandomListNode *q=newHead;
        m[p]=q;
        p=p->next;
        while(p)
        {
            RandomListNode *node = new RandomListNode(p->label);
            q->next=node;
            q=q->next;
            m[p]=q;
            p=p->next;
        }

        //Copy the random pointer
        p=head;
        q=newHead;
        while(p)
        {
            if(p->random!=NULL) q->random=m[p->random];
            p=p->next;
            q=q->next;
        }
        return newHead;
    }
};


class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL) return NULL;
        RandomListNode *cur=head;
        while(cur)
        {
            RandomListNode *node= new RandomListNode(cur->val);
            node->next=cur->next;
            cur->next=node;
            cur=cur->next->next;
        }
        cur=head;
        while(cur)
        {
            cur->next->random=(cur->random)?cur->random->next:NULL;
            cur=cur->next->next;
        }
        cur=head;
        RandomListNode dummy(-1);
        RandomListNode *prev=&dummy;
        while(cur)
        {
            prev->next=cur->next;
            prev=cur->next;
            cur->next=prev->next;
            cur=cur->next;
        }
        prev->next=NULL;
        return dummy.next;
        
    }
};

