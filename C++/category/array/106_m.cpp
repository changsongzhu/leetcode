/**
106[M]. Construct Tree from Inorder  and Postorder Traversals
 
Given inorder and postorder traversal of a tree, construct the binary tree.
Note:
You may assume that duplicates do not exist in the tree.
 
Note: The last item of the post order traversal sequence is always the root node. Then search the root node in in-order traversal sequence and use it as boundary b/w left tree and right tree.
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    TreeNode* dfs(vector<int>&inorder, int in_start, int in_end, vector<int>&postorder, int post_start, int post_end)
    {
        if(in_start>in_end)
           return NULL;
        int left_len=0;
        for(int i=in_start;i<=in_end;i++)
        {
            if(inorder[i]==postorder[post_end])
            {
                left_len=i-in_start;
                break;
            }
        }
        TreeNode *node=new TreeNode(postorder[post_end]);
        node->left=dfs(inorder, in_start, in_start+left_len-1, postorder,post_start, post_start+left_len-1);
        node->right=dfs(inorder,in_start+left_len+1, in_end, postorder, post_start+left_len, post_end-1);
        return node;
    }
};

