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

//Refined Solution
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums){
       int res=0;
       for(int i=0;i<nums.size();i++)
       {
          if(nums[i]==0) continue;
          int j=i;
          while(j+1<nums.size()&&nums[j+1]==1) j=j+1;
          res=max(res, j-i+1);
          i=j;
       }
       return res;
    }
};

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


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        for(int i=0;i<n;)
        {
            if(nums[i]==1)
            {
                int start=i;
                while(nums[i]==1)i++;
                res=max(res, i-start);
            }
            else
            {
                i++;
            }
        }
        return res;
    }
};
