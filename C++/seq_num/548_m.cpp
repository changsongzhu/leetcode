/**
548[M]. Split Array with Equal Sums
Given an array with n integers, you need to find if there are triplets (i, j, k) which satisfies following conditions:
1.     0 < i, i + 1 < j, j + 1 < k < n - 1
2.     Sum of subarrays (0, i - 1), (i + 1, j - 1), (j + 1, k - 1) and (k + 1, n - 1) should be equal.
where we define that subarray (L, R) represents a slice of the original array starting from the element indexed L to the element indexed R.
Example:
Input: [1,2,1,2,1,2,1]
Output: True
Explanation:
i = 1, j = 3, k = 5.
sum(0, i - 1) = sum(0, 0) = 1
sum(i + 1, j - 1) = sum(2, 2) = 1
sum(j + 1, k - 1) = sum(4, 4) = 1
sum(k + 1, n - 1) = sum(6, 6) = 1
Note:
1.     1 <= n <= 2000.
2.     Elements in the given array will be in range [-1,000,000, 1,000,000].
**/

class Solution {
public:
    bool splitArray(vector<int>& nums) {
        if(nums.size()<7) return false;
        vector<int> sums(nums.size(), 0);
        for(int i=0;i<nums.size();i++)
        {
            if(i==0) sums[i]=nums[i];
            else sums[i]=sums[i-1]+nums[i];
        }
        for(int i=1;i<nums.size()-5;i++)
        {
            for(int j=i+2;;j<nums.size()-3;j++)
            {
                for(int k=j+2;k<nums.size()-1;k++)
                {
                     if((sums[nums.size()-1]-sums[k])==(sums[k-1]-sums[j])&&
                        (sums[nums.size()-1]-sums[k])==(sums[j-1]-sums[i])&&
                        (sums[nums.size()-1]-sums[k])==sums[i-1])
                         return true;
                }
            }
        }
        return false;
   }
};

