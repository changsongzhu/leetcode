/**
446[H]. Arithmetic Slices II - Subsequence
A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
For example, these are arithmetic sequences:
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.
1, 1, 2, 5, 7
 
A zero-indexed array A consisting of N numbers is given. A subsequence slice of that array is any sequence of integers (P0, P1, ..., Pk) such that 0 ≤ P0 < P1 < ... < Pk < N.
A subsequence slice (P0, P1, ..., Pk) of array A is called arithmetic if the sequence A[P0], A[P1], ..., A[Pk-1], A[Pk] is arithmetic. In particular, this means that k ≥ 2.
The function should return the number of arithmetic subsequence slices in the array A.
The input contains N integers. Every integer is in the range of -231 and 231-1 and 0 ≤ N ≤ 1000. The output is guaranteed to be less than 231-1.
 
Example:
Input: [2, 4, 6, 8, 10]

Output: 7

Explanation:
All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]
**/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res=0, n=A.size();
        vector<unordered_map<int, int> > dp(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                long long diff = (long long)A[i]-(long long)A[j];
                if(diff>INT_MAX||diff<INT_MIN) continue;
                int d=(int)diff;
                if(!dp[i].count(d)) dp[i][d]=0;
                dp[i][d]++;
                if(dp[j].count(d))
                {
                    dp[i][d]+=dp[j][d];
                    res+=dp[j][d];
                }
            }
 
        }
        return res;
    }
};


//TLE Solution
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res=0;
        vector<int> path;
        dfs(A, path, 0, res);
        return res;
    }
    void dfs(vector<int> &nums,vector<int> &path, int start, int &res )
    {
        if(path.size()>=3)
        {
            res++;
        }
        if(start>=nums.size()) return;
        for(int i=start;i<nums.size();i++)
        {
            if(path.size()<2)
            {
                path.push_back(nums[i]);
                dfs(nums, path, i+1, res);
                path.pop_back();
            }
            else
            {
                if(i!=start&&nums[i]==nums[start]) continue;
                long long diff=(long long)path[1]-(long long)path[0];
                long long tmp= (long long)nums[i]-(long long)path[path.size()-1];
                if(tmp==diff)
                {
                    path.push_back(nums[i]);
                    dfs(nums, path, i+1, res);
                    path.pop_back();
                }
            }
        }
    }
};

