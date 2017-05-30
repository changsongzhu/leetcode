/**
117[M]. Populating Next Right Pointers in Each Node
 
Follow up for problem "Populating Next Right Pointers in Each Node".
What if the given tree could be any binary tree? Would your previous solution still work?
Note:
You may only use constant extra space.
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

