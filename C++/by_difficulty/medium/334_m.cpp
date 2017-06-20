/**
334[M]. Increasing Triplet Subsequence
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.
Examples:
Given [1, 2, 3, 4, 5],
return true.
Given [5, 4, 3, 2, 1],
return false.
**/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
       vector<int> dp(nums.size(), 1);
       int res=0;
       for(int i=0;i<nums.size();i++)
       {
          for(int j=0;j<i;j++)
          {
              if(nums[i]>nums[j]) dp[i]=max(dp[i], dp[j]+1);
          }
          res=max(res, dp[i]);
       }
       return res>=3;
    }
};

