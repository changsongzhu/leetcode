/**
687. Longest Univalue Path
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.
Note: The length of path between two nodes is represented by the number of edges between them.
Example 1:
Input:
             5
             / \
            4   5
           / \   \
          1   1   5


Output:
2


Example 2:
Input:
             1
             / \
            4   5
           / \   \
          4   4   5


Output:
2


Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
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
    int longestUnivaluePath(TreeNode* root) {
        int res=0;
        dfs(root, res);
        return res==0?0:res-1;
    }
    int dfs(TreeNode *root, int &res)
    {
        if(root==NULL) return 0;
        int left=dfs(root->left, res);
        int right=dfs(root->right, res);
        if(!left&&!right) return 1;
        if(left&&right&&root->left->val==root->val&&root->right->val==root->val)
        {
            res=max(res, left+right+1);
            return max(left+1, right+1);
        }
        else if(left&&root->left->val==root->val)
        {
            res=max(res, left+1);
            return left+1;
        }
        else if(right&&root->right->val==root->val)
        {
            res=max(res, right+1);
            return right+1;
        }
        else
        {
            res=max(res, 1);
            return 1;
        }   
    }
};

