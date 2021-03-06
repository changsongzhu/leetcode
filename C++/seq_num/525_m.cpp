/**
525[M]. Contiguous Array
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.
**/
class Solution{
public:
    int findMaxLength(vector<int> &nums){
        if(nums.size()==0) return 0;
        map<int, int> m;
        m[0]=-1;
        int res=0, sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]==0)?-1:1;
            //never update the first sum's index because we want to get the maximum length
            if(m.count(sum))
            {
                res=max(res, i-m[sum]);
            }
            else
            {
                m[sum]=i;
            }
        }
        return res;
    }
};


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size()==0) return 0;
        map<int,int> mp{{0,-1}};
        int sum=0;
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=(nums[i]==1?1:-1);
            if(mp.count(sum))
            {
                res=max(res, i-mp[sum]);
            }
            else
            {
                mp[sum]=i;
            }
        }
        return res;
        
    }
};
