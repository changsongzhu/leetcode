/**
77[M]. Combinations
 
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
For example,
If n = 4 and k = 2, a solution is:
[  
[2,4],  
[3,4],  
[2,3],  
[1,2],  
[1,3],  
[1,4],
] 
*/
 
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> path;
        dfs(res, path, 1, n, k);
        return res;
   }
   void dfs(vector<vector<int> >&res, vector<int> &path, int start,int n, int k)
   {
       if(path.size()==k)
       {
           res.push_back(path);
           return;
       }
       for(int i=start;i<=n;i++)
       {
           path.push_back(i);
           dfs(res, path,i+1, n, k);
           path.pop_back();
       }
 
   }
};

