/**
643[E]. Maximum Average Subarray I
Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.
Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75


Note:
1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].
**/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res=INT_MIN;
        int sum=0, cnt=0, left=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            cnt++;
            while(cnt>k)
            {
                sum-=nums[left++];
                cnt--;
            }
            if(cnt==k)
            {
                res=max(res, (double)sum/k);
            }
        }
        return res;
    }
};

