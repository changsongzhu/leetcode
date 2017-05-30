/**
103[M]. Binary Tree ZigZag Level Order Traversal
 
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
For example:
Given binary tree [3,9,20,null,null,15,7],
    3 
   / \
  9  20  
     /  \
    15   7
return its zigzag level order traversal as:
[  
[3],  
[20,9],  
[15,7]
]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        helper(res, root, 1);
        for(int i=1;i<res.size();i=i+2)
        {
            reverse(res[i].begin(), res[i].end());
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

