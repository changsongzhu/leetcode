/**
173[M]. BST Iterator
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
Calling next() will return the next smallest number in the BST.
Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
**/

class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
            while(root)
            {
                stk.push(root);
                root=root->left;
            }
}
 
	/** @return whether we have a next smallest number */
	bool hasNext() {
            return !stk.empty();
}
 
	/** @return the next smallest number */
	int next() {
            TreeNode *node=stk.top();stk.pop();
            if(node->right!=NULL) 
            {
                TreeNode *tmp=node->right;
                while(tmp)
                {
                   stk.push(tmp);
                   tmp=tmp->left;
                }
            }
            return node->val;
	}
private:
    stack<TreeNode*> stk;
};
 
/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

