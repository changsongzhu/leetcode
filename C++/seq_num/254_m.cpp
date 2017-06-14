/**
254[M]. Factor Combinations
Numbers can be regarded as product of its factors. For example,
8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.
Note: 
1.     Each combination's factors must be sorted ascending, for example: The factors of 2 and 6 is [2, 6], not [6, 2].
2.     You may assume that n is always positive.
3.     Factors should be greater than 1 and less than n.
 
Examples: 
input: 1
output: 
[]
input: 37
output: 
[]
input: 12
output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
input: 32
output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
**/

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int> > res;
        vector<int> path;
        dfs(res, path, 2, n);
        return res;
    }
    void dfs(vector<vector<int> >&res, vector<int>&path, int start, int n)
    {
        if(n<start) return;
        if(path.size()!=0)
        {
            path.push_back(n);
            res.push_back(path);
            path.pop_back();
        }
        for(int i=start;i<=n/2;i++)
        {
            if(n%i==0&&n/i>=start)
            {
                path.push_back(i);
                dfs(res, path, i, n/i);
                path.pop_back();
            }
        }
    }
};

