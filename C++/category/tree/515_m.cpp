/**
515[M].Find Largest Value in Each Tree Row
You need to find the largest value in each row of a binary tree.
Example:
Input:
 
          1
         / \
        3   2
       / \   \
      5   3   9
 
Output: [1, 3, 9]
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        helper(res, root, 1);
        return res;
    }
    void helper(vector<int> &res, TreeNode* root, int level)
    {
        if(root==NULL) return;
        if(res.size()<level) res.push_back(root->val);
        else res[level-1]=max(res[level-1], root->val);
        helper(res, root->left, level+1);
        helper(res, root->right, level+1);
    }
};

