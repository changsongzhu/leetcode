/**

268[M]. Missing Number
 
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
For example,
Given nums = [0, 1, 3] return 2.
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 
Notes:
·   	Considering the contiguous of the number sequence, here can calculate the sum and compare the expected one with the real one. The difference is the missing number.

**/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expected_sum=0;
        int real_sum=0;
        for(int i=0;i<nums.size();i++)
        {
            real_sum+=nums[i];
            expected_sum+=(i+1);
        }
        return expected_sum-real_sum;
    }
};
