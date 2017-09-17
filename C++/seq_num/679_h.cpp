/**
679[H]. 24 Game
You have 4 cards each containing a number from 1 to 9. You need to judge whether they could operated through *, /, +, -, (, ) to get the value of 24.
Example 1:
Input: [4, 1, 8, 7]
Output: True
Explanation: (8-4) * (7-1) = 24


Example 2:
Input: [1, 2, 1, 2]
Output: False


Note:
The division operator / represents real division, not integer division. For example, 4 / (1 - 2/3) = 12.
Every operation done is between two numbers. In particular, we cannot use - as a unary operator. For example, with [1, 1, 1, 1] as input, the expression -1 - 1 - 1 - 1 is not allowed.
You cannot concatenate numbers together. For example, if the input is [1, 2, 1, 2], we cannot write this as 12 + 12.

**/

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        if(nums.size()!=4) return false;
        vector<double> tmp;
        for(int i=0;i<nums.size();i++)
            tmp.push_back((double)nums[i]);
        return helper(tmp, 4);
    }
    
    bool helper(vector<double> &nums, int n)
    {
        if(n==1)
        {
            if(fabs(nums[0]-24.0)<0.0000000001)
                return true;
            else 
                return false;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                vector<double> tmp;
                if(i==j) continue;
                double t1=nums[i];
                double t2=nums[j];
                tmp.push_back(t1+t2);
                for(int k=0;k<n;k++)
                {
                    if(k==i||k==j) continue;
                    tmp.push_back(nums[k]);
                }
                tmp[0]=t1+t2;
                if(helper(tmp, tmp.size())) return true;
                tmp[0]=t1-t2;
                if(helper(tmp, tmp.size())) return true;
                tmp[0]=t1*t2;
                if(helper(tmp, tmp.size())) return true;
                if(t2!=0)
                {
                    tmp[0]=t1/t2;
                    if(helper(tmp,tmp.size())) return true;
                }
            }
        }
        return false;
    }
};

