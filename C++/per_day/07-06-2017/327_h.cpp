/**
327[H]. Count of Range Sum
Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.
Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.
Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.
**/

//TLE Solution
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int res=0;
        multiset<long long> sums;
        long long sum=0;
        sums.insert(sum);
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            res+=distance(sums.lower_bound(sum-upper), sums.upper_bound(sum-lower));
            sums.insert(sum);
        }
        return res;
    }
};


//TLE Solution
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int m=nums.size();
        vector<long long> sums(m+1, 0);
        for(int i=0;i<=m;i++)
        {
            if(i==0) sums[i]=0;
            else sums[i]=sums[i-1]+nums[i-1];
        }
        int res=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(sums[i]-sums[j]>=lower&&sums[i]-sums[j]<=upper) res++;
            }
        }
        return res;
    }
};

