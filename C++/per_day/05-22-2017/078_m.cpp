/**
78[M]. Subsets
 
Given a set of distinct integers, nums, return all possible subsets.
Note: The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:
[  
[3],  
[1],  
[2],  
[1,2,3],  
[1,3],  
[2,3],  
[1,2],  
[]
]
**/
 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> path;
        dfs(nums, res, path, 0);
        return res;
   }
   void dfs(vector<int> & nums, vector<vector<int> >&res, vector<int> &path, int start)
   {
       if(start == nums.size())
       {
           res.push_back(path);
           return;
       }
       dfs(nums, res, path, start+1);
       path.push_back(nums[start]);
       dfs(nums, res, path, start+1);
       path.pop_back();
   }
};
