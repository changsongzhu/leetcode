/**
136[E]. Single Number
 
Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

**/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(auto n:nums)
            res^=n;
        return res;
    }
};
