/**
272[H]. Closest Binary Search Tree Value II
 
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
Note:
·       Given target value is a floating point.
·       You may assume k is always valid, that is: k ≤ total nodes.
·       You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
 
Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?
Hint:
1. Consider implement these two helper functions:
　　i. getPredecessor(N), which returns the next smaller node to N.
　　ii. getSuccessor(N), which returns the next larger node to N.
2. Try to assume that each node has a parent pointer, it makes the problem much easier.
3. Without parent pointer we just need to keep track of the path from the root to the current node using a stack.
4. You would need two stacks to track the path in finding predecessor and successor node separately.
**/
 
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
       vector<int> res;
       priority_queue<pair<double, int> > q;
       dfs(root, target, k, q);
       while(!q.empty())
       {
           auto a=q.front();q.pop();
           res.push_back(a.second);
       }
       return res;
    }
    void dfs(TreeNode *root, double target, int k, priority_queue<pair<double, int> >&q)
    {
       if(root==NULL) return;
       dfs(root->left, target, k, q);
       q.push({abs(root->val-target, root->val});
       if(q.size()>k) q.pop();
       dfs(root->right, target, k, q);
    }
};

