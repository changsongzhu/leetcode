/**494[M]. Target Sum
 
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
Find out how many ways to assign symbols to make sum of integers equal to target S.
Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5
Explanation:
 
-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3
 
There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
**/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res=0;
        dfs(nums, res, 0, S);
        return res;
    }
    void dfs(vector<int> &nums, int &res, int start, int gap)
    {
        if(start==nums.size()&&gap==0)
        {
           res++;
           return;
        }
        if(start>nums.size())return;
        dfs(nums, res, start+1, gap-nums[start]);
        dfs(nums, res, start+1, gap+nums[start]);
    }
};
