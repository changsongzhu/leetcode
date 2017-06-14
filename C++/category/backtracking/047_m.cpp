/**
47[M]. Permutation 2
 
Given a collection of numbers that might contain duplicates, return all possible unique permutations.
For example,
[1,1,2] have the following unique permutations:
[  
[1,1,2],  
[1,2,1],  
[2,1,1]
]
**/
 
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int> > res;
        vector<int> path;
        vector<bool>visited(nums.size(), false);
        dfs(res, path, visited, nums);
        return vector<vector<int> >(res.begin(), res.end());
 
    }
    void dfs(set<vector<int> > &res, vector<int> &path, vector<bool> &visited, vector<int>& nums)
    {
        if(path.size()==nums.size())
        {
            res.insert(path);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(visited[i]) continue;
            visited[i]=true;
 
 
            path.push_back(nums[i]);
            dfs(res, path, visited, nums);
            path.pop_back();
            visited[i]=false;
        }
    }
};

