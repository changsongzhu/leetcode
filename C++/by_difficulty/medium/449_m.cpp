/**
449[M]. Serialize and Deserialize BST
 
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.
The encoded string should be as compact as possible.
Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
**/

class Codec {
public:
 
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }
 
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
private:
    void serialize(TreeNode* root, ostringstream &out)
    {
        if(!root)
        {
            out<<"# ";
        }
        else
        {
            out<<root->val<<" ";
            serialize(root->left, out);
            serialize(root->right, out);
        }
    }
    TreeNode* deserialize(istringstream &in)
    {
        string val;
        in>>val;
        if(val=="#") return NULL;
        TreeNode *node=new TreeNode(stoi(val));
        node->left=deserialize(in);
        node->right=deserialize(in);
        return node;
    }
};

