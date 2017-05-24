/**
216[M]. Combination Sum 3
 
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:
Input: k = 3, n = 7
Output:
[
[1,2,4]
]


Example 2:
Input: k = 3, n = 9
Output:
[
[1,2,6],
[1,3,5],
[2,3,4]
]
**/
 
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int> path;
        if(k>9) return res;
        dfs(res, path, 1, k, n);
        return res;
    }
    void dfs(vector<vector<int> > &res, vector<int> &path, int start, int k, int target)
    {
        if(k==0&&target==0)
        {
            res.push_back(path);
            return;
        }
        if(k<=0||target<=0) return;
        for(int i=start;i<=9;i++)
        {
            path.push_back(i);
            dfs(res, path, i+1, k-1, target-i);
            path.pop_back();
        }
    }
};

