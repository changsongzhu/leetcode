/**
45[M]. Jump Game II
 
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
For example:
Given array A = [2,3,1,1,4]
The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
Note:
You can assume that you can always reach the last index.
**/

class Solution {
public:
    int jump(vector<int>& nums) {
        int steps=0;
        int right=0;
        int i=0;
        while(right<nums.size()-1)
        {
            int prev=right;
            for(;i<=prev;i++)
                right=max(right, i+nums[i]);
            steps++;
        }
        return step;
    }
};

