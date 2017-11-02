/**
199[M]. Binary Tree Right Side View
 
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
For example:
Given the following binary tree,
  1            <--- 
/   \
2 	3         <--- 
\ 	\
  5     4   	<---
You should return [1, 3, 4].
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

//BFS Solution with Queue
class Solution {
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        queue<pair<TreeNode *, int> > q;
        if(root!=NULL) q.push({root, 1});
        while(!q.empty())
        {
            auto a=q.front();q.pop();
            if(res.size()<a.second)
            {
                res.push_back(a.first->val);
            }
            else
            {
                res[a.second-1]=a.first->val;
            }
            if(a.first->left) q.push({a.first->left, a.second+1});
            if(a.first->right)q.push({a.first->right, a.second+1});
        }
        return res;
    }
};


//DFS Solution
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        vector<vector<int> > path;
        helper(path, root, 1);
        for(int i=0;i<path.size();i++)
        {
            res.push_back(path[i][path[i].size()-1]);
        }
        return res;
    }
    void helper(vector<vector<int> >&res, TreeNode *root, int level)
    {
        if(root==NULL) return;
        if(res.size()<level) res.push_back({root->val});
        else res[level-1].push_back(root->val);
        helper(res, root->left, level+1);
        helper(res, root->right, level+1);
    }
};

