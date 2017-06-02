/**
285[M]. Inorder Successor of a Node
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
Note: If the given node has no in-order successor in the tree, return null.
**/

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> stk;
        TreeNode *res=NULL;
        bool flag=false;
        TreeNode *cur=root;
        while(cur)
        {
            stk.push(cur);
            cur=cur->left;
        }
        while(!stk.empty())
        {
            TreeNode *node=stk.top();stk.pop();
            if(flag==true)
            {
                res=node;
                break;
            }
            if(node==p) flag=true;
            node=node->right;
            while(node)
            {
                stk.push(node);
                node=node->left;
            }
        }
        return res;
    }
};

