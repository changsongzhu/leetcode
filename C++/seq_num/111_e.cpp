/**
111[E]. Minimum Depth of Binary Tree
 
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int level;
        int result = INT_MAX;
        depth(root, 1, result);
        return result;
    }
    
    void depth(TreeNode *root, int level, int &result)
    {
        if(root==NULL) return ;
        
        if(root->left==NULL&&root->right==NULL)
        {
            result = min(result, level);
            return;
        }
        depth(root->left, level+1, result);
        depth(root->right, level+1, result);
    }
};

