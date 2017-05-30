/**
116[M].Populating Next Right Pointers in Each Node
 
Given a binary tree
	struct TreeLinkNode {   	
    	TreeLinkNode *left;   	
    	TreeLinkNode *right;   	
    	TreeLinkNode *next; 	
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.
Note:
You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
     	 1    	
        /  \
       2    3  	
      / \  / \
     4  5  6  7
After calling your function, the tree should look like:
     	 1 -> NULL    	
        /  \
       2 -> 3 -> NULL  	
      / \  / \
     4->5->6->7 -> NULL
**/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        vector<vector<TreeLinkNode*> > res;
        dfs(res, root, 1);
        for(int i=0;i<res.size();i++)
        {
            for(int j=0;j<res[i].size();j++)
            {
               if(j==res[i].size()-1) res[i][j]->next=NULL;
               else res[i][j]->next=res[i][j+1];
            }
        }
        
    }
    void dfs(vector<vector<TreeLinkNode*> > &res, TreeLinkNode *root, int level)
    {
        if(root==NULL) return;
        if(res.size()<level) res.push_back({root});
        else res[level-1].push_back(root);
        dfs(res, root->left,level+1);
        dfs(res, root->right, level+1);
    }
};

