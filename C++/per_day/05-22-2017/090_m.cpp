/**
90[M]. Subsets II
 
Given a collection of integers that might contain duplicates, nums, return all possible subsets.
Note: The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:
[  
[2],  
[1],  
[1,2,2],  
[2,2],  
[1,2],  
[]
]
**/
 
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int> > res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        dfs(res, path, nums, 0);
        return vector<vector<int> >(res.begin(), res.end());
    }
    void dfs(set<vector<int> > &res, vector<int> &path, vector<int>& nums, int start)
    {
        if(start == nums.size())
        {
            res.insert(path);
            return;
        }
        dfs(res, path, nums, start+1);
        path.push_back(nums[start]);
        dfs(res, path, nums, start+1);
        path.pop_back();
    }
};
