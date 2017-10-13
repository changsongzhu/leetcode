/**
536[M]. Construct Binary Tree From String
 
You need to construct a binary tree from a string consisting of parenthesis and integers.
The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.
You always start to construct the left child node of the parent first if it exists.
Example:
Input: "4(2(3)(1))(6(5))"
Output: return the tree root node representing the following tree:
 
       4
     /   \
    2     6
   / \   /
  3   1 5  
 
Note:
1.     There will only be '(', ')', '-' and '0' ~ '9' in the input string.
2.     An empty tree is represented by "" instead of "()".
**/

class Solution {
public:
    TreeNode* str2tree(string s) {
        if(s.size()==0) return NULL;
        auto found=s.find('(');
        if(found==string::npos)
        {
            TreeNode *cur=new TreeNode(stoi(s));
            return cur;
        }
        int val=stoi(s.substr(0, found));
        TreeNode *cur=new TreeNode(val);
        int start=found,cnt=0;
        for(int i=start;i<s.size();i++)
        {
            if(s[i]=='(') cnt++;
            else if(s[i]==')') cnt--;
            if(cnt==0&&start==found)
            {
                cur->left=str2tree(s.substr(start+1, i-start-1));
                start=i+1;
            }
            else if(cnt==0)
            {
                cur->right=str2tree(s.substr(start+1, i-start-1));
            }
        }
        return cur;
    }
    
};
