/**
257[E]. Binary Tree Paths
Given a binary tree, return all root-to-leaf paths.
For example, given the following binary tree:
   1 
 /   \
2 	3 
 \
  5
All root-to-leaf paths are:
[
"1->2->5",
"1->3"
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        helper(root, result, path);
        return result;
    }
    void helper(TreeNode *root, vector<string> &result, string path)
    {
        if(root==NULL) return;
        
        if(root->left==NULL && root->right==NULL)
        {
            path+=to_string(root->val);
            result.push_back(path);
            return;
        }
        path +=to_string(root->val) + "->";
        helper(root->left, result, path);
        helper(root->right, result,  path);
    }
};
