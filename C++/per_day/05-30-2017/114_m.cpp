/*
114[M]. Flatten Binary Search Tree to Linked List
 
Given a binary tree, flatten it to a linked list in-place.
For example,
Given
     	   1     	
    	  / \
         2   5   	
  	/ \   \
       3   4   6
The flattened tree should look like:
 
  1 	
   \
    2   
     \
      3
     	\
      	 4
       	 \
       	   5
            \
             6 
**/

class Solution {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> res;
        helper(root, res);
        for(int i=0;i<res.size();i++)
        {
            res[i]->left=res[i]->right=NULL;
            if(i!=0)res[i-1]->right=res[i];
        }
    }
    void helper(TreeNode* root, vector<TreeNode*> &res)
    {
        if(root==NULL) return;
        res.push_back(root);
        helper(root->left, res);
        helper(root->right, res);
    }
};

