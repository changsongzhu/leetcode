/**
485[E] Max Consecutive Ones
 
Given a binary array, find the maximum number of consecutive 1s in this array.
Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:
The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
**/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0;
        int size=nums.size();
        int start=-1;
        for(int i=0;i<size;i++)
        {
            if(nums[i]==0&&start!=-1)
            {
                res=max(res, i-start);
                start=-1;
            }
            else if(nums[i]==1&&start==-1)
            {
                start=i;
            }
        }
        return (start==-1)?res:max(res, size-start);
    }
};
