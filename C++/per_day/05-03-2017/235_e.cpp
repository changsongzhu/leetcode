/*
235[E]. Lowest Common Ancestor of a Binary Tree

Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
          6    	
        /    \
       2      8	
      / \    / \
     0	  4  7 9      	
         /  \
        3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. 
Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
        if(root==NULL) return NULL;
    
        TreeNode *cur=root;
        TreeNode *left=(p->val>=q->val)?p:q;
        TreeNode *right=(p->val>=q->val)?q:p;
    
        while(1)
        {
            if(cur->val>=left->val && cur->val<=right->val)
                return cur;
            else if(cur->val>right->val)
                cur=cur->left;
            else
                cur=cur->right;
        }
    
    }

};

