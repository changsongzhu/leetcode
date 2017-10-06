/**
581[E]. Shortest Unsorted Continuous Subarray
 
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.
You need to find the shortest such subarray and output its length.
Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
**/
//Refined Solution
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int left=-1, right=-1;
        int mn=INT_MAX, mx=INT_MIN;
        for(int i=nums.size()-1;i>=0;i--)
        {
            left=(nums[i]>mn)?i:left;
            mn=min(mn, nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            right=(nums[i]<mx)?i:right;
            mx=max(nums[i], mx);
        }
        return (left!=-1&&right!=-1)?right-left+1:0;
        
    }
};


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()<2) return 0;
        vector<int> max_v(nums.size(),0);
        vector<int> min_v(nums.size(),0);
        int max_val=INT_MIN;
        int min_val=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            max_val=max(max_val, nums[i]);
            max_v[i]=max_val;
            min_val=min(min_val, nums[nums.size()-1-i]);
            min_v[nums.size()-1-i]=min_val;
        }
        int left=-1;
        int right=-1;
        for(int i=0;i<nums.size();i++)
        {
           if((nums[i]!=max_v[i]||nums[i]!=min_v[i])&&left==-1)
               left=i;
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
           if((nums[i]!=max_v[i]||nums[i]!=min_v[i])&&right==-1)
               right=i;
        }
        return (left!=-1&&right!=-1)?right-left+1:0;
    }
};
