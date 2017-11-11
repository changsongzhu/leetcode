/**
102[E]. Binary Tree Level Order Traversal
 
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
For example:
Given binary tree [3,9,20,null,null,15,7],
    3	
   / \
  9  20 	
     /  \
    15   7
return its level order traversal as:
[  
[3],  
[9,20],  
[15,7] ]
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

//Iterative Solution
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int> > res;
        queue<pair<TreeNode *, int> > q;
        if(root)q.push({root, 1});
        while(!q.empty())
        {
            auto a=q.front();q.pop();
            if(res.size()<a.second)
            {
                res.push_back({a.first->val});
            }
            else
            {
                res[a.second-1].push_back(a.first->val);
            }
            if(a.first->left)
                q.push({a.first->left, a.second+1});
            if(a.first->right)
                q.push({a.first->right, a.second+1});
        }
        return res;
    }
};


//Recursive Solution
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        helper(res, root, 1);
        return res;
    }
    void helper(vector<vector<int> > &res, TreeNode *root, int level)
    {
       if(root==NULL) return;
       if(res.size()<level) res.push_back({root->val});
       else res[level-1].push_back(root->val);
       helper(res, root->left, level+1);
       helper(res, root->right, level+1);
    }
};

