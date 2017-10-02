/**
689[H]. Maximum Sum of 3 Non-Overlapping Subarrays
In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.
Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.
Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.
Example:
Input: [1,2,1,2,6,7,5,1], 2
Output: [0, 3, 5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.


Note:
nums.length will be between 1 and 20000.
nums[i] will be between 1 and 65535.
k will be between 1 and floor(nums.length / 3).
**/

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size(), maxSum=0;
        vector<int> left(n, 0), right(n, n-k), sums(n+1, 0), res(3, 0);
        
        for(int i=0;i<nums.size();i++)
            sums[i+1]=sums[i]+nums[i];
        
        for(int i=k, total=sums[k]-sums[0];i<n;i++)
        {
            if(sums[i+1]-sums[i+1-k]>total)
            {
                left[i]=i+1-k;
                total=sums[i+1]-sums[i+1-k];
            }
            else
            {
                left[i]=left[i-1];
            }
        }
        
         for(int i=n-1-k, total=sums[n]-sums[n-k];i>=0;i--)
        {
            if(sums[i+k]-sums[i]>total)
            {
                right[i]=i;
                total=sums[i+k]-sums[i];
            }
            else
            {
                right[i]=right[i+1];
            }
        }
        
        for(int i=k;i<=n-2*k;i++)
        {
            int l=left[i-1], r=right[i+k];
            int sum=sums[l+k]-sums[l]+sums[r+k]-sums[r]+sums[i+k]-sums[i];
            if(sum>maxSum)
            {
                maxSum=sum;
                res[0]=l;res[1]=i;res[2]=r;
            }
        }
        return res;
        
    }
};

