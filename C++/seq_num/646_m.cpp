/**
646. Maximum Length of Pair Chain
 
You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.
Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.
Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.
Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]


Note:
The number of given pairs will be in the range [1, 1000].
**/

//DP Solution
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b){return a[0]<b[0];});
        int n=pairs.size();
        vector<int> dp(n+1,0);
        dp[0]=0;
        int res=1;
        for(int i=1;i<=n;i++)
        {
            dp[i]=1;
            for(int j=1;j<i;j++)
            {
                if(pairs[i-1][0]>pairs[j-1][1])
                {
                    dp[i]=max(dp[i], dp[j]+1);
                }
            }
            res=max(res, dp[i]);
        }
        return res;
    }
};


class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b){return a[1]<b[1]||(a[1]==b[1]&&a[0]>b[0]);});
        int res=1;
        int index=0;
        for(int i=1;i<pairs.size();i++)
        {
            if(pairs[i][0]>pairs[index][1])
            {
                res++;
                index=i;
            }
        }
        return res;
        
    }
};

