/**
34[M].Search for a Range
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].
For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
**/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==1&&nums[0]==target) return vector<int>({0,0});
        int left=0,right=nums.size()-1;
        int index=-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==target)
            {
                index=mid;
                break;
            }
            else if(nums[mid]<target)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        if(index==-1) return vector<int>({-1,-1});
        left=right=index;
        while(left>=0&&nums[left]==target)left--;
        while(right<=nums.size()-1&&nums[right]==target)right++;
        return vector<int>({left+1, right-1});
    }
};
