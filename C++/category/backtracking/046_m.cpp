/**

46[M]. Permutation
 
Given a collection of distinct numbers, return all possible permutations.
For example,
[1,2,3] have the following permutations:
[  
[1,2,3],  
[1,3,2],  
[2,1,3],  
[2,3,1],  
[3,1,2],  
[3,2,1]
]

**/
 
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> path;
        vector<bool>visited(nums.size(), false);
        dfs(res, path, visited, nums);
        return res;
        
    }
    void dfs(vector<vector<int> > &res, vector<int> &path, vector<bool> &visited, vector<int>& nums)
    {
        if(path.size()==nums.size())
        {
            res.push_back(path);
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

