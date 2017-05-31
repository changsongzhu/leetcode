/**
109[M]. Convert Sorted Linked List to Binary Search Tree
 
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
**/

 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        int len=0;
        ListNode *cur=head;
        while(cur)
        {
           len++;
           cur=cur->next;
        }
        return helper(head, 0, len-1);
    }
    TreeNode* helper(ListNode* &head, int start, int end)
    {
        if(end<start) return NULL;
        int mid=start + (end-start)/2;
        TreeNode *left=helper(head, start, mid-1);
        TreeNode *root=new TreeNode(head->val);
        root->left=left;
        head=head->next;
        root->right=helper(head, mid+1, end);
        return root;
    }
};

