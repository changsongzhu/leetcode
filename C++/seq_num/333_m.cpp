/**
333[M]. Largest BST Subtree
Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.
Note:
A subtree must include all of its descendants.
Here's an example:
    10
    / \
   5  15
  / \   \
 1   8   7
The Largest BST Subtree in this case is the highlighted one. 
The return value is the subtree's size, which is 3.
 
Hint:
1.     You can recursively use algorithm similar to 98. Validate Binary Search Tree at each node of the tree, which will result in O(nlogn) time complexity.
Follow up:
Can you figure out ways to solve it with O(n) time complexity?
**/


//Right Solution
class Solution {
public:
    struct Result{
        int size;
        int lower;
        int upper;
        Result(int s, int l, int u){
            size=s;lower=l;upper=u;
        }
    };
    int largestBSTSubtree(TreeNode* root) {
        if(root==NULL) return 0;
        int res=0;
        helper(root, res);
        return res;   
    }
    Result helper(TreeNode *root, int &res){
        if(root==NULL) return  Result(0, INT_MAX, INT_MIN);
        Result left=helper(root->left, res);
        Result right=helper(root->right, res);
        if(left.size==-1||right.size==-1||root->val<=left.upper||root->val>=right.lower){
            return Result(-1, 0, 0);     
        }
        res=max(res, right.size+left.size+1);
        return  Result(right.size+left.size+1, min(root->val, left.lower), max(root->val,right.upper));    
    }
};

//Wrong Solution
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int res=0;
        dfs(root, res);
        return res;
   }
   int dfs(TreeNOde *root, int &res)
   {
       if(root==NULL) return 0;
       int l=dfs(root->left, res);
       int r=dfs(root->right, res);
       if(l==-1||r==-1||
          (root->left!=NULL&&root->val<=root->left->val)&&
          (root->right!=NULL&root->val>=root->right->val))
       {
           res=max(res, max(l, r));
           return -1;
       }
       res=max(res, l+r+1);
       return l+r+1;
   } 
};

