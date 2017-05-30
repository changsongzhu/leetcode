/**
113[M]. Path Sum II 
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example:
Given the below binary tree and sum = 22,
           5             
          / \
         4   8        	
       	/   / \
      	11 13  4      	
       /  \    / \
      7    2  5   1
return
[	
[5,4,11,2],	
[5,8,4,5]
] 
**/

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res; 
        vector<int> path;
        dfs(res, path, root, sum);
        return res;
    }
    void dfs(vector<vector<int> > &res, vector<int> path, TreeNode *root, int sum)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL&&root->right==NULL&&root->val==sum)
        {
            path.push_back(root->val);
            res.push_back(path);
            return;
        }
        path.push_back(root->val);
        dfs(res, path, root->left, sum-root->val);
        dfs(res, path, root->right, sum-root->val);
    }
};

