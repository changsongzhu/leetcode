class Solution{
public:
    int bstDistance( vector<int> &nums, int n1,  int n2)
    {
        if(nums.size()==0) return 0;
        sort(nums.begin(), nums.end());

        TreeNode *root=createBST(nums, 0, nums.size()-1);
        TreeNode *lca=findLCA(root, n1, n2);
        if(lca==NULL) return 0;
        
        int l1=findLevel(lca, n1, 0);
        int l2=findLevel(lca, n2, 0);
        return l1+l2;
      
    }

    TreeNode *createBST(vector<int> &nums, int start, int end)
     {
          if(start>end) return NULL;
          TreeNode *node=new TreeNode(nums[start+(end-start)/2]);
          node->left=createBST(nums, start, start+(end-start)/2-1);
          node->right=createBST(nums, start+(end-start)/2+1, end);       
      }
      TreeNode* findLCA(TreeNode *root, int val1, int val2)
      {
          if(root==NULL) return NULL;
          if(root->val>val1&&root->val>val2) return findLCA(root->left, val1, val2);
          if(root->val<val1&&root->val<val2) return findLCA(root->right, val1, val2);
          return root;
      }
      int findLevel(TreeNode* root, int val, int level)
      {
          if(root==NULL) return 0;
          if(root->val==val) return level;
          int downlevel=0;
          if(root->val>val)
              downlevel=findLevel(root->left, val, level+1);
          else
              downlevel=findLevel(root->right, val, level+1);
          return downlevel!=0?downlevel, 0;
      }
};

