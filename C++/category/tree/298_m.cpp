/**
298[M]. Binay Tree Longest Consecutive Sequence
Given a binary tree, find the length of the longest consecutive sequence path.
 
The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).
For example,
   1
   \
    3
    /\
   2  4
       \
     	5
Longest consecutive sequence path is 3-4-5, so return 3.
   2
    \
     3
    /
   2	
  /
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
**/
 
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if(root==NULL) return 0;
        int res=0;
        dfs(root, res, 0,root->val-1);
        return res;
    }
   
    void dfs(TreeNode *root, int &res, int path, int prev_val)
    {
        if(root==NULL) return;
        if(root->val!=(prev_val+1))
        {
           path=0;
        }
        path++;
        res=max(res, path);
        prev_val=root->val;
        dfs(root->left, res, path, prev_val);
        dfs(root->right,res, path, prev_val);
        
    }
};

