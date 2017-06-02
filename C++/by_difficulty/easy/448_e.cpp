/**
448[E]. Find All Numbers Disappeared in an Array

Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements of [1, n] inclusive that do not appear in this array.
Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

**/


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        vector<int> tmp(nums.size(), 0);
        for(int i=0;i<nums.size();i++)
        {
            tmp[nums[i]-1]=nums[i];
        }
        for(int i=0;i<tmp.size();i++)
        {
            if(tmp[i]==0)
                res.push_back(i+1);
        }
        return res;
    }
};
