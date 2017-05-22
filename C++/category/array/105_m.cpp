/**

105[M].Construct Tree from Preorder and Inorder Traversals
 
Given preorder and inorder traversal of a tree, construct the binary tree.
Note:
You may assume that duplicates do not exist in the tree.
 
Notes: The root node is always the first item of the preorder traversal. Then we use the root node in the in order traversal sequence as the boundary for the left tree and right tree. 
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
   }
   TreeNode * dfs(vector<int>& preorder, int pre_start, int pre_end, vector<int> &inorder, int in_start, int in_end)
   {
       if(pre_start>pre_end)
       {
           return NULL;
       }
       int left_len=0;
       for(int i=in_start;i<=in_end;i++)
       {
           if(inorder[i]==preorder[pre_start])
           {
              left_len=i-in_start;
           }
       }
       TreeNode* node=new TreeNode(preorder[pre_start]);
       node->left=dfs(preorder, pre_start+1, pre_start+left_len, inorder, in_start, in_start+left_len-1);
       node->right=dfs(preorder,pre_start+left_len+1, pre_end, inorder, in_start+left_len+1, in_end);
       return node;
   }
};
