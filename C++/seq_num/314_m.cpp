/**
314[M]. Binary Tree Vertical Order Traversal
 
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
If two nodes are in the same row and column, the order should be from left to right.
Examples:
Given binary tree [3,9,20,null,null,15,7],
    3	
   / \
  9  20 	
    /  \
   15   7
return its vertical order traversal as:
[  
[9],  
[3,15],  
[20],  
[7]
]
Given binary tree [3,9,20,4,5,2,7],
     3	
   /   \
  9	20 
 / \   / \
4   5 2   7
return its vertical order traversal as:
[ 
[4],  
[9],  
[3,5,2],  
[20],  
[7]
]
**/

/*Right Answer*/
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int> >  res;
        vector<vector<pair<int, int>> >l;
        map<int, vector<int>>m;
        helper(root, 0, 0, l);
        int index=0;
        for(auto b:l){
            for(auto a:b){
                m[a.first].push_back(a.second);
            }
        }
        for(auto a:m){
            res.push_back(a.second);
        }
        return res;       
    }
    void helper(TreeNode *root, int index, int level, vector<vector<pair<int, int>> >&l){
        if(root==NULL)return;   
        if(l.size()<=level){
            l.push_back({{index, root->val}});
        }else{
            l[level].push_back({index, root->val});
        }
        helper(root->left, index-1,level+1, l);
        helper(root->right,index+1,level+1, l);
 
    }
};

/*Wrong Answer*/ 
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int> > mp;
        vector<vector<int> > res;
        dfs(mp, root, 0);
        for(auto i:mp)
           res.push_back(i.second);
        return res;
   }
   void dfs(map<int, vector<int> >&mp, TreeNode *root, int index)
   {
       if(root==NULL) return;
       mp[index].push_back(root->val);
       dfs(mp, root->left, index-1);
       dfs(mp, root->right,index+1);
   }
};

