/**
55[M]. Jump Game
 
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false.
**/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==0) return true;
        int last=nums.size()-1;
        int max_pos=0;
        for(int i=0;i<nums.size();i++)
        {
            max_pos=max(max_pos, i+nums[i]);
            if(max_pos>=last) return true;
            else if(max_pos<=i) return false;
        }
        return true;
    }
};
