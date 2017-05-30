/**
199[M]. Binary Tree Right Side View
 
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
For example:
Given the following binary tree,
  1            <--- 
/   \
2 	3         <--- 
\ 	\
  5     4   	<---
You should return [1, 3, 4].
**/

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        vector<vector<int> > path;
        helper(path, root, 1);
        for(int i=0;i<path.size();i++)
        {
            res.push_back(path[i][path[i].size()-1]);
        }
        return res;
    }
    void helper(vector<vector<int> >&res, TreeNode *root, int level)
    {
        if(root==NULL) return;
        if(res.size()<level) res.push_back({root->val});
        else res[level-1].push_back(root->val);
        helper(res, root->left, level+1);
        helper(res, root->right, level+1);
    }
};

