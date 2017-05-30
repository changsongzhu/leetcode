/**
333[M]. Largest BST Subtree
Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.
Note:
A subtree must include all of its descendants.
Here's an example:
    10
    / \
   5  15
  / \   \
 1   8   7
The Largest BST Subtree in this case is the highlighted one. 
The return value is the subtree's size, which is 3.
 
Hint:
1.     You can recursively use algorithm similar to 98. Validate Binary Search Tree at each node of the tree, which will result in O(nlogn) time complexity.
Follow up:
Can you figure out ways to solve it with O(n) time complexity?
**/

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int res=0;
        dfs(root, res);
        return res;
   }
   int dfs(TreeNOde *root, int &res)
   {
       if(root==NULL) return 0;
       int l=dfs(root->left, res);
       int r=dfs(root->right, res);
       if(l==-1||r==-1||
          (root->left!=NULL&&root->val<=root->left->val)&&
          (root->right!=NULL&root->val>=root->right->val))
       {
           res=max(res, max(l, r));
           return -1;
       }
       res=max(res, l+r+1);
       return l+r+1;
   } 
};

