/**
303[E]. Range Sum Query – Immutable
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
Example:
Given nums = [-2, 0, 3, -5, 2, -1]  sumRange(0, 2) -> 1 sumRange(2, 5) -> -1 sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
**/

class NumArray {
public:
    NumArray(vector<int> nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(i==0) sums.push_back(nums[i]);
            else sums.push_back(sums[i-1]+nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        if(i==0) return sums[j];
        else return sums[j]-sums[i-1];
    }
private:
    vector<int> sums;
};
