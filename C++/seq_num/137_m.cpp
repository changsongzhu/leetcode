/**
137[M]. Single Number II 
Given an array of integers, every element appears three times except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
**/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int res=0;
       for(int i=0;i<32;i++)
       {
           int sum=0;
           for(int j=0;j<nums.size();j++)
              sum+=(nums[j]>>i)&0x01;
           sum%=3;
           res|=(sum<<i);
       }
       return res;
    }
};

