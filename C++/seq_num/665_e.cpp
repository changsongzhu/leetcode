/**
665[E]: Non-Decreasing Array
Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.
We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).
Example 1:
Input: [4,2,3]
Output: True
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.


Example 2:
Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element.


Note: The n belongs to [1, 10,000].
**/

/*
Explanation:

Case 1: A>B<C<D:   For C, prev value should be B (min(A, B))
Case 2: A<B>C<D:   For D, prev value has two cases:
		  if(A>C) prev value is B
                  if(A<C) prev value is C
*/


class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size()<3) return true;
        int cnt=0;
        int prev=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<prev)
            {
                cnt++;
                if(cnt>=2) return false;
                prev=(i!=1)?(nums[i]<nums[i-2]?nums[i-1]:nums[i]):nums[i];
            }
            else
            {
                prev=nums[i];
            }
        }
        return cnt<=1;
    }
};

