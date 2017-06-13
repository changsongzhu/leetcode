/**
 
611[M]. Valid Triangle Number
Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are:
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Note:
The length of the given array won't exceed 1000.
The integers in the given array are in the range of [0, 1000].
**/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3) return 0;
        int res=0;
        for(int i=0;i<nums.size()-2;i++)
        {
            int a=nums[i];
            for(int j=i+1;j<nums.size()-1;j++)
            {
                int b=nums[j];
                for(int k=j+1;k<nums.size();k++)
                {
                    int c=nums[k];
                    if(a+b>c&&a+c>b&&b+c>a) res++;
                }
            }
        }
        return res;
    }
};

