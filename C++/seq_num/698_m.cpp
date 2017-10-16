/**
698[M]. Partition to K equal sum subsets
Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into knon-empty subsets whose sums are all equal.
Example 1:
Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.


Note:
1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.
**/

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(nums.size()<k) return false;
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if((sum%k)!=0) return false;
        int avg=sum/k;
        vector<int> sums(k, 0);
        sort(nums.rbegin(), nums.rend());
        return dfs(nums, sums, 0, avg, k);  
    }
    
    bool dfs(vector<int>& nums, vector<int> &sums, int pos, int target, int k)
    {
        if(pos==nums.size())
        {
            for(int i=0;i<sums.size()-1;i++)
            {
                if(sums[i]!=target) return false;
            }
            return true;
        }

        for(int i=0;i<k;i++)
        {
           if(sums[i]+nums[pos]>target) continue;
           sums[i]+=nums[pos];
           if(dfs(nums, sums, pos+1, target, k)) return true;
           sums[i]-=nums[pos];
        }
        return false;
    }
};

