/**
154[H]. Find Minimum in Rotated Sorted Array II
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
The array may contain duplicates.
**/

class Solution{
public:
    int findMin(vector<int> &nums){
        int left=0, right=nums.size()-1;
        while(left<right)
        {
            if(nums[left]<nums[right]) return nums[left];
            int mid=left+(right-left)/2;
            if(nums[mid]<nums[right])
            {
                right=mid;
            }
            else if(nums[mid]>nums[right])
            {
                left=mid+1;
            }
            else
            {
                right--;
            }
        }
        return nums[left];
    }
};


class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0, right=nums.size()-1, res=nums[0];
        while(left<right-1)
        {
            int mid=left+(right-left)/2;
            if(nums[left]>nums[mid])
            {
                res=min(res, nums[right]);
                right=mid;
            }
            else if(nums[left]<nums[mid])
            {
                res=min(res, nums[left]);
                left=mid+1;
            }
            else left++;
        }
        res=min(res, nums[left]);
        res=min(res, nums[right]);
        return res;
    }
};

