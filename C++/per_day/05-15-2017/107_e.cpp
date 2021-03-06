/**
107[E]. Binary Tree Level Order Traversal 2
 Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
For example:
Given binary tree [3,9,20,null,null,15,7],
   3	
   / \
   9  20 	
     /  \
    15   7
return its bottom-up level order traversal as:
[  
[15,7],  
  [9,20],  
[3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > result;
        helper(result, root, 0);
        reverse(result.begin(), result.end());
        return result;
    }
    void helper(vector<vector<int> > &result, TreeNode *root, int level)
    {
        if(root==NULL) return;
        if(result.size() < level+1)
        {
            result.push_back({root->val});
        }
        else
        {
            result[level].push_back(root->val);
        }
        helper(result, root->left, level+1);
        helper(result, root->right, level+1);
        
    }
};

