/**
366[M]. Find Leaves of Binary Tree
 Given a binary tree, find all leaves and then remove those leaves. Then repeat the previous steps until the tree is empty.
Example:
Given binary tree 
      	 1      	
     	/ \
        2  3	
       / \
      4   5 	
Returns [4, 5, 3], [2], [1].
 
Explanation:
1. Remove the leaves [4, 5, 3] from the tree
      	1 	
     	/	
   	 2          
2. Remove the leaf [2] from the tree
     	 1          
3. Remove the leaf [1] from the tree
      	[]      	
Returns [4, 5, 3], [2], [1].
**/
 
class Solution {
public:
   vector<vector<int>> findLeaves(TreeNode* root) {
       vector<vector<int> > res;
       dfs(res, root);
       return res;
   }
   int dfs(vector<vector<int> >&res, TreeNode *root)
   {
       if(root==NULL) return 0;
       int left=dfs(res, root->left);
       int right=dfs(res, root->right);
       int level=min(left, right)+1;
       if(res.size()<level) res.push_back({root->val});
       else res[level-1].push_back(root->val);
       return level;
   }
};

