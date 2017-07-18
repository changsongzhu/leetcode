/**
644[H]. Maximum Average Subarray II
Given an array consisting of n integers, find the contiguous subarray whose length is greater than or equal to k that has the maximum average value. And you need to output the maximum average value.
Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation:
when length is 5, maximum average value is 10.8,
when length is 6, maximum average value is 9.16667.
Thus return 12.75.
Note:
1 <= k <= n <= 10,000.
Elements of the given array will be in range [-10,000, 10,000].
The answer with the calculation error less than 10-5 will be accepted.
**/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double sum=0;
        for(int i=0;i<k;i++)
            sum+=nums[i];
        int len=k;
        double res=sum/k;
        for(int i=k;i<nums.size();i++)
        {
            sum+=nums[i];
            len++;
            double avg=sum/len;
            
            double tmpSum=sum;
            double tmpAvg=avg;
            for(int j=len-1;j>=k;j--)
            {
                tmpSum-=nums[i-j];
                tmpAvg=tmpSum/j;
                if(tmpAvg>avg)
                {
                    avg=tmpAvg;
                    sum=tmpSum;
                    len=j;
                }     
            }
            if(avg>res) res=avg;
        }
        return res;
        
    }
};
