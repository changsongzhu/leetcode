/**
493[H]. Reverse Pairs
Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].
You need to return the number of important reverse pairs in the given array.
Example1:
Input: [1,3,2,3,1]
Output: 2
Example2:
Input: [2,4,3,5,1]
Output: 3
Note:
The length of the given array will not exceed 50,000.
All the numbers in the input array are in the range of 32-bit integer.
**/

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
    int mergeSort(vector<int> &nums, int left, int right)
    {
        if(left>=right)return 0;
        int mid=left+(right-left)/2;
        int res=mergeSort(nums, left, mid) + mergeSort(nums, mid+1, right);
        for(int i=left, j=mid+1;i<=mid;i++)
        {
            while(j<=right&&nums[i]/2.0>nums[j])j++;
            res+=j-(mid+1);
        }
        sort(nums.begin()+left, nums.begin()+right+1);
        return res;
    }
};

//TLE 
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int res=0;
        for(int j=nums.size()-1;j>0;j--)
        {
            for(int i=j-1;i>=0;i--)
                if(nums[i]>2*nums[j]) res++;
        }
        return res;
        
    }
};

